#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, m, q, fa[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    iota(fa + 1, fa + n + m + 1, 1);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        fa[find(x)] = find(y + n);
    }
    int ans = 0;
    for (int i = 1; i <= n + m; i++) {
        if (i == find(i)) ans++;
    }
    printf("%d\n", ans - 1);
    return 0;
}