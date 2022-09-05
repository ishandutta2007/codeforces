#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, ans, rt, a[maxn], inv[maxn], dist[maxn], sz[maxn], vis[maxn];
int tot, prime[maxn], phi[maxn], c[maxn], s1[maxn], s2[maxn], e[maxn];
bool solved[maxn];
vector<int> G[maxn], d[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), inv[i] = qp(i, P - 2);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    auto init = [&]() {
        fill(prime, prime + n + 1, 1), phi[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) prime[++tot] = i, phi[i] = i - 1;
            for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
                prime[i * prime[j]] = 0;
                if (i % prime[j]) phi[i * prime[j]] = phi[i] * phi[prime[j]];
                else { phi[i * prime[j]] = phi[i] * prime[j]; break; }
            }
        }
        for (int i = 1; i <= n; i++) {
            c[i] = 1LL * i * inv[phi[i]] % P;
            for (int j = i; j <= n; j += i) d[j].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + i; j <= n; j += i) red(c[j] -= c[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) red(e[j] += c[i] - P);
        }
    };
    init();
    function<void(int, int, int)> find_root = [&](int v, int fa, int all) {
        sz[v] = 1;
        int mx = 0;
        for (int u : G[v]) if (u ^ fa && !solved[u]) {
            find_root(u, v, all), sz[v] += sz[u];
            mx = max(mx, sz[u]);
        }
        if (max(mx, all - sz[v]) * 2 <= all) rt = v;
    };
    auto calc = [&](int v, int coef) {
        vector<int> V;
        function<void(int, int)> dfs = [&](int x, int fa) {
            V.push_back(x);
            for (int y : G[x]) if (y ^ fa && !solved[y]) dfs(y, x);
        };
        dfs(v, 0);
        int res = 0;
        for (int v : V) {
            int x = 1LL * phi[a[v]] * dist[v] % P;
            red(res -= 1LL * x * phi[a[v]] % P * e[a[v]] % P);
            for (int y : d[a[v]]) red(s1[y] += x - P);
            red(s2[a[v]] += phi[a[v]] - P);
        }
        for (int v : V) if (!vis[a[v]]) {
            vis[a[v]] = 1;
            for (int y : d[a[v]]) red(res += 1LL * s2[a[v]] * s1[y] % P * c[y] % P - P);
        }
        for (int v : V) {
            vis[a[v]] = s2[a[v]] = 0;
            for (int x : d[a[v]]) s1[x] = 0;
        }
        coef == -1 ? red(ans -= res) : red(ans += res - P);
    };
    function<void(int)> solve = [&](int v) {
        solved[v] = 1, dist[v] = 0;
        for (int u : G[v]) if (!solved[u]) {
            function<void(int, int)> dfs = [&](int x, int fa) {
                dist[x] = dist[fa] + 1, sz[x] = 1;
                for (int y : G[x]) if (y ^ fa && !solved[y]) {
                    dfs(y, x), sz[x] += sz[y];
                }
            };
            dfs(u, v);
        }
        calc(v, 1);
        for (int u : G[v]) {
            if (!solved[u]) calc(u, -1);
        }
        for (int u : G[v]) if (!solved[u]) {
            find_root(u, v, sz[u]), solve(rt);
        }
    };
    find_root(1, 0, n), solve(rt);
    printf("%lld\n", 1LL * ans * qp(1LL * n * (n - 1) / 2 % P, P - 2) % P);
    return 0;
}