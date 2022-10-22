#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const int kModulo = 998244353;


int pow(int a, int b) {
    if (b == 0) {
        if (a != 0)
            return 1;
        else
            return 0;
    }

    if (b % 2)
        return 1LL * pow(a, b - 1) * a % kModulo;
    int v = pow(a, b / 2);
    return 1LL * v * v % kModulo;
}

int inv(int x) {
    return pow(x, kModulo - 2);
}

int main() {
    int N, A, B; cin >> N >> A >> B;
    int P = 1LL * A * inv(B) % kModulo;
    int Q = (1 - P + kModulo) % kModulo;

    vector< vector<int> > beat(N + 1, vector<int>(N + 1, 1));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            beat[i][j] = (1LL * beat[i][j - 1] * pow(P, i) + 1LL * beat[i - 1][j] * pow(Q, j)) % kModulo;
        }

    vector<int> fact(N + 1, 1), ifact(N + 1, 1);
    for (int i = 1; i <= N; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % kModulo;
        ifact[i] = inv(fact[i]);
    }


    vector< vector<int> > pick(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j < i; ++j) {
            pick[i][j] = 1LL * ifact[j] * ifact[i - j] % kModulo;
            pick[i][j] = 1LL * pick[i][j] * fact[i] % kModulo;
        }

    vector<int> good(N + 1, 0);
    good[0] = good[1] = 1;
    for (int i = 2; i <= N; ++i) {
        good[i] = 1;
        for (int j = 1; j < i; ++j) {
            int aux = 1LL * beat[j][i - j] * good[j] % kModulo;

            good[i] = (good[i] - aux + kModulo) % kModulo;
        }

    }

    vector<int> games(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        games[i] = 1LL * i * (i - 1) % kModulo;
        games[i] = 1LL * games[i] * inv(2) % kModulo;
        for (int j = 1; j < i; ++j) {
            int aux = 1LL * good[j] * beat[j][i - j] % kModulo;

            int extra_games = 1LL * (i - j) * (i - j - 1) % kModulo;
            extra_games = 1LL * extra_games * inv(2) % kModulo;
            extra_games = (games[j] + games[i - j] - extra_games) % kModulo;

            if (extra_games < 0)
                extra_games += kModulo;
            games[i] = (games[i] + 1LL * aux * extra_games) % kModulo;
        }
        
        if (good[i] != 1) { // recursive expected
            games[i] = 1LL * games[i] * inv((1 - good[i] + kModulo) % kModulo) % kModulo;
            if (games[i] < 0)
                games[i] += kModulo;
        }

    }

    cout << games[N] << "\n";
}