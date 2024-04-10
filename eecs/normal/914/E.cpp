#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, rt, cnt[1 << 20], _cnt[1 << 20], sz[maxn], fa[maxn], w[maxn], solved[maxn];
vector<int> V = {0}, G[maxn];
char s[maxn];
long long cur, ans[maxn], num[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        w[i] = 1 << (s[i] - 'a');
    }
    for (int i = 0; i <= 19; i++) {
        V.push_back(1 << i);
    }
    function<void(int, int, int)> find_rt = [&](int v, int fa, int all) {
        sz[v] = 1;
        int mx = 0;
        for (int u : G[v]) if (u ^ fa && !solved[u]) {
            find_rt(u, v, all), sz[v] += sz[u];
            mx = max(mx, sz[u]);
        }
        if (max(mx, all - sz[v]) * 2 <= all) rt = v;
    };
    function<void(int)> solve = [&](int v) {
        int _v = v;
        solved[v] = 1, cnt[w[v]]++;
        long long ways = 0;
        for (int u : G[v]) if (!solved[u]) {
            function<void(int, int, int)> dfs = [&](int v, int fa, int xors) {
                xors ^= w[v], cnt[xors]++;
                if (!xors || !(xors & (xors - 1))) ways++;
                for (int u : G[v]) if (u ^ fa && !solved[u]) dfs(u, v, xors);
            };
            dfs(u, 0, w[v]);
        }
        for (int u : G[v]) if (!solved[u]) {
            function<void(int, int, int)> add = [&](int v, int fa, int xors) {
                xors ^= w[v], _cnt[xors]++;
                for (int u : G[v]) if (u ^ fa && !solved[u]) add(u, v, xors);
            };
            function<void(int, int, int)> dfs1 = [&](int v, int fa, int xors) {
                xors ^= w[v], num[v] = 0;
                for (int x : V) num[v] += cnt[x ^ xors ^ w[_v]] - _cnt[x ^ xors ^ w[_v]];
                for (int u : G[v]) if (u ^ fa && !solved[u]) dfs1(u, v, xors);
            };
            function<void(int, int, int)> dfs2 = [&](int v, int fa, int xors) {
                _cnt[xors ^= w[v]]--, sz[v] = 1;
                for (int u : G[v]) if (u ^ fa && !solved[u]) {
                    dfs2(u, v, xors), num[v] += num[u], sz[v] += sz[u];
                }
                ans[v] += num[v];
            };
            add(u, 0, w[v]), dfs1(u, 0, w[v]), dfs2(u, 0, w[v]), ways += num[u];
        }
        cnt[w[v]]--, ans[v] += ways / 2;
        for (int u : G[v]) if (!solved[u]) {
            function<void(int, int, int)> dfs = [&](int v, int fa, int xors) {
                xors ^= w[v], cnt[xors]--;
                for (int u : G[v]) if (u ^ fa && !solved[u]) dfs(u, v, xors);
            };
            dfs(u, 0, w[v]);
        }
        for (int u : G[v]) if (!solved[u]) {
            find_rt(u, 0, sz[u]), solve(rt);
        }
    };
    find_rt(1, 0, n), solve(3);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i] + 1);
    }
    return 0;
}