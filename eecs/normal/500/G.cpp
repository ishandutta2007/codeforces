#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, q, dep[maxn], fa[maxn][20];
vector<int> G[maxn];

ll calc(ll l, ll r, ll d, ll p) {
    if (!d || l > r) return LLONG_MAX;
    if (r / d * d >= l) return (l + d - 1) / d;
    ll x = calc((d - r % d) % d, (d - l % d) % d, p % d, d);
    return x == LLONG_MAX ? LLONG_MAX : (x * p + l + d - 1) / d;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1, y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    return y -= a / b * x, d;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int u) {
        dep[u] = dep[fa[u][0]] + 1;
        for (int i = 1; 1 << i < dep[u]; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (int v : G[u]) if (v ^ fa[u][0]) {
            fa[v][0] = u, dfs(v);
        }
    };
    dfs(1);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) {
            if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        }
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    auto dist = [&](int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    };
    auto solve1 = [&](ll a, ll b, ll t1, ll t2) {
        ll x, y, c = t2 - t1, d1 = a, d = exgcd(a, b, x, y);
        if (c % d) return LLONG_MAX;
        x *= c / d, y *= -c / d;
        a /= d, b /= d;
        if (x < 0 || y < 0) {
            ll k = max((-x - 1) / b, (-y - 1) / a) + 1;
            x += k * b, y += k * a;
        }
        return (x - min(x / b, y / a) * b) * d1 + t1;
    };
    auto solve2 = [&](ll d1, ll d2, ll t1, ll t2, ll d) {
        if ((d + t1 + t2) % 2) return LLONG_MAX;
        ll l = ((t2 - t1 - d) % d2 + d2) % d2, r = ((t2 - t1 + d) % d2 + d2) % d2, x1 = 0;
        if (l && 2 * d < d2 && l <= r) x1 = calc(l, r, d1 % d2, d2);
        if (x1 == LLONG_MAX) return LLONG_MAX;
        ll x2 = (x1 * d1 + t1 - t2 + d) / d2;
        return (x1 * d1 + x2 * d2 + t1 + t2 + d) / 2;
    };
    scanf("%d", &q);
    while (q--) {
        int u, v, x, y;
        scanf("%d %d %d %d", &u, &v, &x, &y);
        int p1 = 0, p2 = 0;
        for (int i : {lca(u, x), lca(u, y), lca(v, x), lca(v, y)}) {
            if (dep[i] > dep[p1]) p2 = p1, p1 = i;
            else if (dep[i] > dep[p2]) p2 = i;
        }
        if (p1 == p2 && dep[p1] < max(dep[lca(u, v)], dep[lca(x, y)])) {
            puts("-1"); continue;
        }
        int d = dist(p1, p2), d1 = dist(u, v) * 2, d2 = dist(x, y) * 2;
        int u1 = dist(u, p1), u2 = dist(u, p2);
        u1 < u2 ? u2 = d1 - u2 : u1 = d1 - u1;
        int x1 = dist(x, p1), x2 = dist(x, p2);
        x1 < x2 ? x2 = d2 - x2 : x1 = d2 - x1;
        ll ans = min(solve1(d1, d2, u1, x1), solve1(d1, d2, u2, x2));
        ans = min({ans, solve2(d1, d2, u1, x2, d), solve2(d1, d2, u2, x1, d)});
        printf("%lld\n", ans > 1e18 ? -1 : ans);
    }
    return 0;
}