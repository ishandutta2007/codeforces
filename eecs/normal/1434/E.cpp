#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int q, n, ans, a[maxn], nxt[maxn], sg[maxn], rb[maxn], vis[maxn];

struct DSU {
    int fa[maxn], w[maxn];
    void init(int n) {
        iota(fa + 1, fa + n + 1, 1), fill(w + 1, w + n + 1, 0);
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void cov(int l, int r, int c) {
        for (int i = find(l); i < r; i = find(i)) w[i] = c, fa[i] = i + 1;
    }
} T[500];

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        memset(nxt, 0, sizeof(nxt));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), nxt[a[i]] = i;
        }
        for (int i = 100000; ~i; i--) {
            if (!nxt[i]) nxt[i] = nxt[i + 1];
        }
        for (int i = 1; i <= 450; i++) T[i].init(n);
        sg[n] = 0;
        for (int i = n - 1; i; i--) {
            rb[1] = n;
            int j = 1;
            while (T[j].w[i]) rb[j + 1] = min(rb[j], T[j].w[i]), j++;
            sg[i] = j;
            for (int r = i, l; j; j--, r = l) {
                l = nxt[max(0, 2 * a[i] - a[rb[j]] + 1)];
                T[j].cov(l, r, i);
            }
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) vis[sg[i]] = 1;
        int x = 0;
        while (vis[x]) x++;
        ans ^= x;
    }
    puts(ans ? "YES" : "NO");
    return 0;
}