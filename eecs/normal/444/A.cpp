#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, m, x[maxn];
double ans;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        ans = max(ans, 1.0 * (x[u] + x[v]) / w);
    }
    printf("%.10f\n", ans);
    return 0;
}