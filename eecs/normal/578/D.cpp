#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m;
long long ans, f[maxn][16];
char s[maxn];

int main() {
    scanf("%d %d %s", &n, &m, s + 1);
    f[0][4] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 16; j++) if (f[i][j]) {
            int a = j & 1, b = j >> 1 & 1, c = j >> 2 & 1, d = j >> 3 & 1;
            for (int k = 0; k < m; k++) {
                int na = a && s[i] == k + 'a' || c;
                int nb = (a || b || c) && s[i + 1] == k + 'a' || d;
                int nc = c && s[i + 1] == k + 'a';
                int nd = (c || d) && s[i + 2] == k + 'a';
                if (!na && !nb && !nc && !nd) continue;
                f[i + 1][na | (nb * 2) | (nc * 4) | (nd * 8)] += f[i][j];
            }
        }
    }
    for (int i = 0; i < 16; i++) if (!(i >> 2 & 1)) {
        ans += f[n][i];
    }
    printf("%lld\n", ans);
    return 0;
}