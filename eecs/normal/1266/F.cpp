#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, mx[maxn], ans[maxn], cnt[maxn], f[maxn], fa[maxn], lst[maxn];
vector<int> G[maxn], id[maxn];
multiset<int> S[maxn];

void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs1 = [&](int u) {
        for (int v : G[u]) if (v ^ fa[u]) {
            fa[v] = u, dfs1(v), S[u].insert(mx[v]);
        }
        mx[u] = (S[u].empty() ? 0 : *S[u].rbegin()) + 1;
    };
    function<void(int)> dfs2 = [&](int u) {
        chk(ans[1], G[u].size() + 1);
        for (int v : G[u]) {
            id[mx[v]].push_back(u);
        }
        for (int v : G[u]) if (v ^ fa[u]) {
            int x = mx[u], y = mx[v];
            S[u].erase(S[u].find(mx[v]));
            S[v].insert(mx[u] = (S[u].empty() ? 0 : *S[u].rbegin()) + 1);
            mx[v] = (S[v].empty() ? 0 : *S[v].rbegin()) + 1, dfs2(v);
            S[v].erase(S[v].find(mx[u]));
            S[u].insert(mx[v] = y), mx[u] = x;
        }
    };
    dfs1(1), dfs2(1);
    for (int i = n; i; i--) {
        for (int x : id[i]) {
            chk(ans[i * 2], ++cnt[x]);
            chk(ans[i * 2], cnt[x] + max(f[x], cnt[fa[x]]) - 2);
            if (lst[x]) chk(ans[min(i, lst[x] - 1) * 2 + 1], cnt[x]);
            f[fa[x]] = max(f[fa[x]], cnt[x]), lst[x] = i;
        }
    }
    for (int i = n - 2; i; i--) {
        ans[i] = max(ans[i], ans[i + 2]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", max(1, ans[i]));
    }
    return 0;
}