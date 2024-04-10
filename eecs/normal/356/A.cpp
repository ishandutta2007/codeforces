#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, a[maxn], fa[maxn], ans[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    iota(fa + 1, fa + n + 2, 1);
    while (m--) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        for (int i = find(l); i <= r; i = find(i + 1)) {
            if (i ^ x) ans[i] = x, fa[i] = i + 1;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}