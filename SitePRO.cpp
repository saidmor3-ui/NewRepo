#include <httplib.h>
#include <iostream>

int main() {
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("<h1>Connexion Reussie !</h1><p>Le serveur sur le port 8888 fonctionne.</p>", "text/html");
        });

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "ETAPE 1 : Tentative sur le port 8888..." << std::endl;

    // On lance le serveur
    // Si ca marche, le programme va "bloquer" ici et attendre les visites
    if (svr.listen("0.0.0.0", 8888)) {
        std::cout << "SUCCES : Le serveur ecoute sur http://localhost:8888" << std::endl;
    }
    else {
        // Si ca echoue, il ecrit l'erreur
        std::cout << "ECHEC : Le port 8888 est toujours occupe ou bloque." << std::endl;
    }

    std::cout << "Le programme est fini. Appuyez sur Entree." << std::endl;
    std::cin.get();
    return 0;
}
