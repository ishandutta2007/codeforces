#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, K, rt, ans, lim;
int a[maxn], sz[maxn], c[2][maxn], cs[2][maxn];
bool solved[maxn];
vector<pair<int, int>> G[maxn];

void add(int *c, int p, int v) {
    for (p++; p <= lim; p += p & -p) {
        if ((c[p] += v) >= P) c[p] -= P;
    }
}

int query(int *c, int p) {
    int s = 0;
    for (p = min(lim, p + 1); p; p -= p & -p) {
        if ((s += c[p]) >= P) s -= P;
    }
    return s;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, u, v, c; i < n; i++) {
        scanf("%d %d %d", &u, &v, &c);
        G[u].emplace_back(v, c), G[v].emplace_back(u, c);
    }
    function<void(int, int, int)> find_rt = [&](int v, int fa, int all) {
        sz[v] = 1;
        int mx = 0;
        for (auto &e : G[v]) {
            int u = e.first;
            if (u ^ fa && !solved[u]) {
                find_rt(u, v, all), sz[v] += sz[u];
                mx = max(mx, sz[u]);
            }
        }
        if (max(mx, all - sz[v]) * 2 <= all) rt = v;
    };
    function<void(int, int)> solve = [&](int v, int U) {
        solved[v] = 1;
        (ans += a[v]) %= P, lim = U;
        for (int col : {0, 1}) {
            fill(c[col], c[col] + lim + 1, 0);
            fill(cs[col], cs[col] + lim + 1, 0);
        }
        for (auto &e : G[v]) {
            int u = e.first;
            if (solved[u]) continue;
            vector<array<int, 2>> V;
            function<void(int, int, int, int, int)> dfs = [&](int x, int fa, int s, int cnt, int lst) {
                sz[x] = 1;
                if (cnt <= K) {
                    ans = (1LL * ans + a[v] + s) % P;
                    V.push_back({cnt, s});
                    for (int col : {0, 1}) {
                        int rem = K - cnt - (col != e.second);
                        if (rem < 0) continue;
                        ans = (ans + 1LL * (a[v] + s) * query(c[col], rem)) % P;
                        (ans += query(cs[col], rem)) %= P;
                    }
                }
                for (auto &e : G[x]) if (e.first ^ fa && !solved[e.first]) {
                    dfs(e.first, x, (s + a[e.first]) % P, cnt + (e.second != lst), e.second);
                    sz[x] += sz[e.first];
                }
            };
            dfs(u, v, a[u], 0, e.second);
            for (auto &p : V) {
                add(c[e.second], p[0], 1);
                add(cs[e.second], p[0], p[1]);
            }
        }
        for (auto &e : G[v]) {
            int u = e.first;
            if (!solved[u]) find_rt(u, v, sz[u]), solve(rt, sz[u]);
        }
    };
    find_rt(1, 0, n), solve(rt, n);
    printf("%d\n", ans);
    return 0;
}