#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S; cin >> S;
    int N = S.size();
    S = " " + S;
    vector<int> z(N + 1, 0), y = z, x = z;
    for (int i = 1; i <= N; ++i) {
        z[i] = z[i - 1];
        y[i] = y[i - 1];
        x[i] = x[i - 1];
        if (S[i] == 'x')
            ++x[i];
        else if (S[i] == 'y')
            ++y[i];
        else
            ++z[i];
    }

    int M; cin >> M;
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        --u;
        int X, Y, Z;
        X = x[v] - x[u];
        Y = y[v] - y[u];
        Z = z[v] - z[u];

        if (max({X, Y, Z}) - min({X, Y, Z}) <= 1 or v - u <= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}