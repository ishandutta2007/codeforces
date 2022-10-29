#include <stdio.h>
using namespace std;
const int MAX_N = 1e5 + 1;
int f[MAX_N], g[MAX_N], h[MAX_N];

int main() {
    int n, m = 0; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);
    for (int i = 1; i <= n; ++i) {
        if (f[f[i]] != f[i]) {
            printf("-1"); return 0;
        } else if (g[f[i]] == 0)
            h[g[f[i]] = ++m] = f[i];
        g[i] = g[f[i]];
    }
    printf("%d\n", m); for (int i = 1; i <= n; ++i) printf("%d ", g[i]);
    printf("\n");      for (int i = 1; i <= m; ++i) printf("%d ", h[i]);
    return 0;
}