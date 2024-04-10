#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, P, K, X, rt, a[maxn], in[maxn], out[maxn], sz[maxn];
int pw[maxn], ipw[maxn], dep[maxn];
bool solved[maxn];
vector<int> G[maxn], up, down;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d %d", &n, &P, &K, &X);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = pw[0] = ipw[0] = 1, inv = qp(K, P - 2); i <= n; i++) {
        pw[i] = 1LL * K * pw[i - 1] % P;
        ipw[i] = 1LL * inv * ipw[i - 1] % P;
    }
    function<void(int, int, int)> find_rt = [&](int v, int fa, int all) {
        sz[v] = 1;
        int mx = 0;
        for (int u : G[v]) if (u ^ fa && !solved[u]) {
            find_rt(u, v, all), sz[v] += sz[u];
            mx = max(mx, sz[u]);
        }
        if (max(mx, all - sz[v]) <= all / 2) rt = v;
    };
    auto calc = [&](int r, int coef, int v) {
        up.clear(), down.clear();
        int sz = 0;
        function<void(int, int, int, int)> dfs1 = [&](int v, int fa, int s1, int s2) {
            dep[v] = dep[fa] + 1, sz++;
            if (dep[v]) {
                s1 = (1LL * K * s1 + a[v]) % P;
                s2 = (s2 + 1LL * pw[dep[v] - 1] * a[v]) % P;
            }
            up.push_back(1LL * (X - s1 + P) * ipw[dep[v]] % P), down.push_back(s2);
            for (int u : G[v]) if (u ^ fa && !solved[u]) dfs1(u, v, s1, s2);
        };
        auto calc = [&](vector<int> &V, int x) {
            return upper_bound(V.begin(), V.end(), x) - lower_bound(V.begin(), V.end(), x);
        };
        function<void(int, int, int, int)> dfs2 = [&](int v, int fa, int s1, int s2) {
            dep[v] = dep[fa] + 1;
            s1 = (1LL * K * s1 + a[v]) % P;
            s2 = (s2 + 1LL * pw[dep[v] - 1] * a[v]) % P;
            int x = 1LL * (X - s1 + P) * ipw[dep[v]] % P;
            in[v] += coef * calc(down, x);
            out[v] += coef * calc(up, s2);
            for (int u : G[v]) if (u ^ fa && !solved[u]) dfs2(u, v, s1, s2);
        };
        dep[0] = r == v ? -1 : 0, dfs1(r, 0, 0, 0);
        sort(up.begin(), up.end()), sort(down.begin(), down.end());
        if (r == v) dep[0] = 0, dfs2(r, 0, 0, 0);
        else dep[0] = 1, dfs2(r, 0, a[v], a[v]);
        return sz;
    };
    function<void(int)> solve = [&](int v) {
        solved[v] = 1, calc(v, 1, v);
        for (int u : G[v]) if (!solved[u]) {
            sz[u] = calc(u, -1, v);
        }
        for (int u : G[v]) if (!solved[u]) {
            find_rt(u, v, sz[u]), solve(rt);
        }
    };
    find_rt(1, 0, n), solve(rt);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 2LL * in[i] * (n - in[i]) + 2LL * out[i] * (n - out[i]);
        ans += 1LL * in[i] * (n - out[i]) + 1LL * (n - in[i]) * out[i];
    }
    printf("%lld\n", 1LL * n * n * n - ans / 2);
    return 0;
}