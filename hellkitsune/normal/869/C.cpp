#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 998244353;

int a, b, c;
int C[5001][5001], f[5001];

void init() {
    f[0] = 1;
    for (int i = 1; i < 5001; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
    }
    forn(i, 5001) C[0][i] = 0;
    C[0][0] = 1;
    for (int i = 1; i < 5001; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < 5001; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= MOD) {
                C[i][j] -= MOD;
            }
        }
    }
}

int solve(int a, int b) {
    int res = 0;
    for (int i = 0; i <= min(a, b); ++i) {
        res = (res + (LL)C[a][i] * C[b][i] % MOD * f[i]) % MOD;
    }
    return res;
}

int main() {
    init();
    cin >> a >> b >> c;
    int ans = (LL)solve(a, b) * solve(b, c) % MOD * solve(c, a) % MOD;
    cout << ans << endl;
    return 0;
}