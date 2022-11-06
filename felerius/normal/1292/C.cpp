#include <bits/stdc++.h>

// Contest: Codeforces Round #614 (Div. 1) (https://codeforces.com/contest/1292)
// Problem: C: Xenon's Attack on the Gangs (https://codeforces.com/contest/1292/problem/C)

using namespace std;

#define sz(x)       (int)size(x)
#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define trav(a, b)  for(auto& a : b)

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = long long;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

[[maybe_unused]] const int INF = (int)1e9;
[[maybe_unused]] const ll INFL = (ll)1e18;

struct Edge {
    int u, v;
    int size_u, size_v;

    Edge() = default;
    Edge(int u, int v) : u(u), v(v) {}

    int other(int a) const { return a == v ? u : v; }
    int& size(int a) { return a == v ? size_v : size_u; }
    int node(int dir) { return dir == 0 ? u : v; }
    int dir(int a) { return a == u ? 0 : 1; }
};

vector<Edge> E;
vvi V;
int n;
arr<ll, 3000, 2, 3000, 2> dp{};

void dfs_size(Edge* e, int from) {
    int to = e->other(from);
    e->size(to) = 1;
    for (auto ei2 : V[to]) {
        auto* e2 = &E[ei2];
        if (e2 == e)
            continue;
        dfs_size(&E[ei2], to);
        e->size(to) += e2->size(e2->other(to));
    }
    e->size(from) = n - e->size(to);
}

ll calc_recursive(int ei1, int d1, int ei2, int d2) {
    if (dp[ei1][d1][ei2][d2] != -1)
        return dp[ei1][d1][ei2][d2];
    auto *e1 = &E[ei1], *e2 = &E[ei2];
    int v1 = e1->node(d1), v2 = e2->node(d2);
    ll mx = 0;
    for (auto eni1 : V[v1]) {
        auto* en1 = &E[eni1];
        if (en1 == e1)
            continue;
        int dn1 = en1->dir(en1->other(v1));
        mx = max(mx, calc_recursive(eni1, dn1, ei2, d2));
    }
    for (auto eni2 : V[v2]) {
        auto* en2 = &E[eni2];
        if (en2 == e2)
            continue;
        int dn2 = en2->dir(en2->other(v2));
        mx = max(mx, calc_recursive(ei1, d1, eni2, dn2));
    }
    return dp[ei1][d1][ei2][d2] = (ll)e1->size(v1) * e2->size(v2) + mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    V.resize(n);
    E.resize(n - 1);
    rep(i, n - 1) {
        int a, b; cin >> a >> b; --a, --b;
        E[i] = Edge(a, b);
        V[a].push_back(i);
        V[b].push_back(i);
    }
    auto* e1 = &E[0];
    dfs_size(e1, e1->u);
    dfs_size(e1, e1->v);
    trav(r1,dp) trav(r2,r1) trav(r3,r2) r3.fill(-1);

    ll mx = 0;
    rep(ei, n-1)
        mx = max(mx, calc_recursive(ei, 0, ei, 1));

    cout << mx << '\n';
    return 0;
}