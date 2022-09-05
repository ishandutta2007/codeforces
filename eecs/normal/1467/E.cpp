#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, ans, tag[maxn], fa[maxn], tid[maxn], sz[maxn];
vector<int> G[maxn];
map<int, vector<int>> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a), mp[a].push_back(i);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs1 = [&](int v) {
        static int tim = 0;
        tid[v] = ++tim, sz[v] = 1;
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs1(u), sz[v] += sz[u];
        }
    };
    dfs1(1);
    for (auto &p : mp) if (p.second.size() > 1) {
        auto &V = p.second;
        vector<int> p;
        for (int v : V) p.push_back(tid[v]);
        sort(p.begin(), p.end());
        auto chk = [&](int l, int r) {
            auto it1 = upper_bound(p.begin(), p.end(), r);
            auto it2 = lower_bound(p.begin(), p.end(), l);
            return it1 != it2;
        };
        for (int v : V) {
            for (int u : G[v]) if (u ^ fa[v]) {
                if (chk(tid[u], tid[u] + sz[u] - 1)) tag[1]++, tag[u]--;
            }
            if (chk(1, tid[v] - 1) || chk(tid[v] + sz[v], n)) tag[v]++;
        }
    }
    function<void(int, int)> dfs2 = [&](int v, int s) {
        s += tag[v];
        if (!s) ans++;
        for (int u : G[v]) if (u ^ fa[v]) dfs2(u, s);
    };
    dfs2(1, 0);
    printf("%d\n", ans);
    return 0;
}