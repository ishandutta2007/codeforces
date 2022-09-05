#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, l, K, f[maxn][maxn], d[maxn], a[maxn];

int main() {
    scanf("%d %d %d", &n, &l, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    d[++n] = l;
    memset(f, 0x3f, sizeof(f)), f[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 0; k < j; k++) {
                int _k = k + i - j - 1;
                f[i][_k] = min(f[i][_k], f[j][k] + a[j] * (d[i] - d[j]));
            }
        }
    }
    printf("%d\n", *min_element(f[n], f[n] + K + 1));
    return 0;
}