#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, ans = 1, solved[maxn], cnt[maxn << 1], prod[maxn << 1];
int rt, sz[maxn];
struct edge { int v, x, o, w; };
vector<edge> G[maxn];

int inv(int x) {
    return x <= 1 ? x : 1LL * (P - P / x) * inv(P % x) % P;
}

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, x, o; i < n; i++) {
        scanf("%d %d %d %d", &u, &v, &x, &o);
        G[u].push_back((edge){v, x, o, 0}), G[v].push_back((edge){u, x, o, 0});
    }
    function<void(int, int, int)> find_rt = [&](int v, int fa, int all) {
        sz[v] = 1;
        int mx = 0;
        for (auto e : G[v]) if (e.v ^ fa && !solved[e.v]) {
            find_rt(e.v, v, all), sz[v] += sz[e.v];
            mx = max(mx, sz[e.v]);
        }
        if (max(mx, all - sz[v]) * 2 <= all) rt = v;
    };
    function<void(int)> solve = [&](int v) {
        solved[v] = 1, find_rt(v, 0, 0);
        vector<int> cnt(sz[v] * 4 + 2), prod(sz[v] * 4 + 2, 1);
        int all = sz[v] * 2;
        auto add = [&](int p, int v) {
            for (p++; p <= all * 2 + 1; p += p & -p) {
                cnt[p]++, prod[p] = 1LL * prod[p] * v % P;
            }
        };
        auto query = [&](int p) {
            int x = 0, y = 1;
            for (p++; p; p -= p & -p) {
                x += cnt[p], y = 1LL * y * prod[p] % P;
            }
            return make_pair(x, y);
        };
        for (auto e : G[v]) if (!solved[e.v]) {
            function<void(int, int, int, int)> dfs1 = [&](int v, int fa, int s, int p) {
                if (s <= all) ans = 1LL * ans * p % P;
                auto q = query(all - (s - all));
                if (q.first) ans = 1LL * ans * qp(p, q.first) % P * q.second % P;
                for (auto e : G[v]) if (e.v ^ fa && !solved[e.v]) {
                    dfs1(e.v, v, s + e.w, 1LL * p * e.x % P);
                }
            };
            function<void(int, int, int, int)> dfs2 = [&](int v, int fa, int s, int p) {
                add(s, p);
                for (auto e : G[v]) if (e.v ^ fa && !solved[e.v]) {
                    dfs2(e.v, v, s + e.w, 1LL * p * e.x % P);
                }
            };
            dfs1(e.v, v, all + e.w, e.x), dfs2(e.v, v, all + e.w, e.x);
        }
        for (auto e : G[v]) if (!solved[e.v]) {
            rt = 0, find_rt(e.v, v, sz[e.v]);
            assert(rt), solve(rt);
        }
    };
    auto chk = [&](bool dir) {
        for (int i = 1; i <= n; i++) {
            for (auto &e : G[i]) {
                if (!dir) e.w = e.o ? 1 : -2;
                else e.w = !e.o ? 1 : -2;
            }
        }
        solve(1), memset(solved, 0, sizeof(solved));
    };
    chk(0), chk(1), find_rt(1, 0, 0);
    function<void(int, int)> dfs = [&](int v, int fa) {
        for (auto e : G[v]) if (e.v ^ fa) {
            ans = 1LL * ans * inv(qp(e.x, 1LL * sz[e.v] * (n - sz[e.v]) % (P - 1))) % P;
            dfs(e.v, v);
        }
    };
    dfs(1, 0), printf("%d\n", ans);
    return 0;
}