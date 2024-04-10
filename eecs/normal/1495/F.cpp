#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, q, p[maxn], dep[maxn], fa[18][maxn], in[maxn], cnt[maxn];
ll a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]), c[i] = a[i] - b[i];
    }
    stack<int> st; st.push(0);
    for (int i = 1; i <= n; i++) {
        while (st.size() > 1 && p[st.top()] < p[i]) st.pop();
        dep[i] = dep[fa[0][i] = st.top()] + 1;
        c[st.top()] += b[i], st.push(i);
    }
    for (int i = n; i; i--) {
        d[fa[0][i]] += min(0LL, d[i] += c[i]);
    }
    d[0] += c[0];
    for (int i = 1; i <= n; i++) {
        d[i] += d[fa[0][i]] - min(0LL, d[i]);
    }
    for (int i = 1; i <= 17; i++) {
        for (int j = 0; j <= n; j++) {
            fa[i][j] = fa[i - 1][fa[i - 1][j]];
        }
    }
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 17; ~i; i--) {
            if (dep[fa[i][u]] >= dep[v]) u = fa[i][u];
        }
        if (u == v) return u;
        for (int i = 17; ~i; i--) {
            if (fa[i][u] ^ fa[i][v]) u = fa[i][u], v = fa[i][v];
        }
        return fa[0][u];
    };
    set<int> S = {0};
    ll ans = d[0];
    auto solve = [&](int x, int coef) {
        if (!x) return;
        auto pre = S.lower_bound(x), nxt = S.upper_bound(x);
        int u = pre == S.begin() ? -1 : *--pre;
        int v = nxt == S.end() ? -1 : *nxt;
        if (~u && ~v) ans += coef * d[lca(u, v)];
        if (~u) ans -= coef * d[lca(u, x)];
        if (~v) ans -= coef * d[lca(v, x)];
        ans += coef * d[x];
        coef == 1 ? (void)S.insert(x) : (void)S.erase(x);
    };
    for (int _ = 1, x; _ <= q; _++) {
        scanf("%d", &x);
        if (in[x]) {
            if (!--cnt[fa[0][x]]) solve(fa[0][x], -1);
        } else {
            if (!cnt[fa[0][x]]++) solve(fa[0][x], 1);
        }
        in[x] ^= 1, printf("%lld\n", ans);
    }
    return 0;
}