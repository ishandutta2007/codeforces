#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define debug(x) std::cout << #x << ": " << x << '\n';
typedef long long ll;
const int N = 1e6 + 10, K = 100 + 10, LG = 16;
const ll INF = 2e9 + 10;
int p[N], sz[N];
std::vector<std::pair<int*, int>> v;
void set(int &a, int b) {
    v.pb({&a, a});
    a = b;
}
void rollBack() {
    auto t = v.back();
    v.pop_back();
    (*t.first) = t.second;
}
int find(int x) {
    return p[x] == x ? x : find(p[x]);
}
void unite(int a, int b ){
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) std::swap(a, b);
    set(p[b], a);
    set(sz[a], sz[a] + sz[b]);
}
struct edge
{
    int l, r;
    int v, u;
};
edge edges[N];
int query[N], where[N], answ[N];
void dfs(int tl, int tr, int l, int r) {
    int k = v.size();
    for (int i = l; i <= r; ++i) {
        int l2 = edges[i].l, r2 = edges[i].r;
        // debug(l2 << ' ' << r2 << ' ' << tl << ' ' << tr)
        if (l2 <= tl && tr <= r2) {
            unite(edges[i].v, edges[i].u);
            std::swap(edges[i], edges[r]);
            --i; 
            --r;
            continue;
        }
        if (std::max(l2, tl) > std::min(r2, tr)) {
            std::swap(edges[i], edges[r]);
            --i; 
            --r;
            continue;
        }
    }
    if (tr - tl + 1 == 1 && query[tl]) {
        // debug(tl << ' ' << where[tl])
        // debug(find(where[tl]))
        answ[tl] = sz[find(where[tl])];
    }
    else if (tr - tl + 1 > 1) {
        int tm = (tl + tr) / 2;
        dfs(tl, tm, l, r);
        dfs(tm + 1, tr, l, r);
    }
    while ((int)v.size() != k) rollBack();
}
int timeK[N];
struct QUERY
{
    int t, a, b;
};
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, q, k;
    std::cin >> n >> q >> k;
    FOR(i, n) {
        p[i] = i;
        sz[i] = 1;
    }
    FOR(i, q + k) {
        timeK[i] = q;
    }
    std::vector<QUERY> Q;
    int T = 0;
    FOR(i, q) {
        int t;
        std::cin >> t;
        int a, b;
        if (t == 1) {
            std::cin >> a >> b;
            --a; --b;
        }
        if (t == 2) {
            std::cin >> a;
            --a;
            query[i] = 1;
            where[i] = a;
        }
        if (t == 3) {
            timeK[++T] = i;
        }
        Q.pb({t, a, b});
    }
    int edgesCnt = 0;
    T = 0;
    FOR(i, q) {
        if (Q[i].t == 1) {
            edges[edgesCnt++] = {i, timeK[T + k], Q[i].a, Q[i].b};
            // debug(i << ' ' << timeK[T + k])
        }
        if (Q[i].t == 3) {
            ++T;
        }
    }
    dfs(0, q - 1, 0, edgesCnt - 1);
    FOR(i, q) {
        if (query[i]) {
            std::cout << answ[i] << '\n';
        }
    }
}