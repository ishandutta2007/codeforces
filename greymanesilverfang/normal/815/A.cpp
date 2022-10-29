#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = 1e3;

int Min[105], m, n, a[105][105];

void Swap() {
    swap(m, n);
    for (int i = 1; i <= 100; ++i)
        for (int j = i + 1; j <= 100; ++j)
            swap(a[i][j], a[j][i]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    bool SWAP; if (SWAP = n > m) Swap();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        Min[i] = INF;
        for (int j = 1; j <= m; ++j) {
            ans += a[i][j];
            Min[i] = min(Min[i], a[i][j]);
            if (a[i][j] - a[i][1] != a[1][j] - a[1][1]) {
                printf("-1");
                return 0;
            }
        }
        ans += Min[i] * (n - m);
    }
    printf("%d\n", ans / n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= Min[i]; ++j)
            printf("%s %d\n", SWAP ? "col" : "row", i);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= a[1][i] - Min[1]; ++j)
            printf("%s %d\n", SWAP ? "row" : "col", i);
    return 0;
}