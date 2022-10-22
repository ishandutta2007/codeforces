#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int M, K; cin >> M >> K;
    set<int> S;
    for (int i = 0; i < K; ++i) {
        int x; cin >> x;
        S.insert(x);
    }

    int N; cin >> N;
    vector<int> least(N, 0), most(N, 0);

    // sunt sigur favorite daca least[meu] >= most[oricine]
    // sigur nu sunt daca most[meu] < least[cineva]
    // else bla bla
    int maxmost = 0, maxleast = 0;
    for (int i = 0; i < N; ++i) {
        string SD; cin >> SD;
        int D; cin >> D;

        int favorite = 0, empty = 0;
        for (int j = 0; j < D; ++j) {
            int x; cin >> x;
            if (S.find(x) != S.end())
                ++favorite;
            if (x == 0)
                ++empty;
        }

        // tre sa aleg inca empty spatii
        // si afara am K -favorite favoriti din totalul de M - D - empty
        // pai pun M - D - empty - K + favorite(ca atatia am, daca nu ajunge)
        least[i] = favorite;
        if (M - D + empty - K + favorite < empty)
            least[i] += empty - (M - D + empty - K + favorite);

        most[i] = favorite + min(K - favorite, empty);

        maxmost = max(maxmost, most[i]);
        maxleast = max(maxleast, least[i]);
        //cerr << least[i] << " " << most[i] << "\n";
    }

    for (int i = 0; i < N; ++i) {
        maxmost = 0;
        maxleast = 0;
        for (int j = 0; j < N; ++j)
            if (j != i) {
                maxmost = max(maxmost, most[j]);
                maxleast = max(maxleast, least[j]);
            }

        if (least[i] >= maxmost)
            cout << "0\n";
        else
            if (most[i] < maxleast)
                cout << "1\n";
            else
                cout << "2\n";
    }
}