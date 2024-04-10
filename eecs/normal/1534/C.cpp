#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int T, n, pos1[maxn], pos2[maxn], vis[maxn], fa[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1, x; i <= n; i++) {
            scanf("%d", &x), pos1[x] = i;
        }
        for (int i = 1, x; i <= n; i++) {
            scanf("%d", &x), pos2[x] = i;
        }
        iota(fa + 1, fa + n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fa[find(pos1[i])] = find(pos2[i]);
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (i == find(i)) (ans <<= 1) %= 1000000007;
        }
        printf("%d\n", ans);
    }
    return 0;
}