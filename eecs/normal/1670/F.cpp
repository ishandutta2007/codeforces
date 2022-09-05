#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 1000000007;
int n, f[2010][2], g[2010][2], binom[1010][1010];
ll l, r, z;

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %lld %lld %lld", &n, &l, &r, &z);
    for (int i = 0; i <= n; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            red(binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j] - P);
        }
    }
    auto solve = [&](ll lim) {
        memset(f, 0, sizeof(f)), f[0][1] = 1;
        int ans = 0;
        for (int i = 0; i < 60; i++) {
            int v = z >> i & 1, _v = lim >> i & 1;
            memset(g, 0, sizeof(g));
            for (int j = 0; j < 2010; j++) {
                for (int p : {0, 1}) if (f[j][p]) {
                    for (int k = v; k <= n; k += 2) {
                        int c = (j + k) % 2;
                        red(g[(j + k) / 2][c < _v ? 1 : c == _v ? p : 0] += 1LL * f[j][p] * binom[n][k] % P - P);
                    }
                }
            }
            swap(f, g);
        }
        return f[0][1];
    };
    printf("%d\n", (solve(r) - solve(l - 1) + P) % P);
    return 0;
}