#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, m, tot, lst[maxn];
int eid, ex, ey, mn, sz[maxn];
bool del[maxn];

struct P {
    ll x, y;
    P(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

    P operator + (const P &o) { return P(x + o.x, y + o.y); }
    P operator - (const P &o) { return P(x - o.x, y - o.y); }
    __int128 operator * (const P &o) { return (__int128)x * o.y - (__int128)y * o.x; }
} val[maxn];
vector<pair<int, P>> G[maxn];
vector<tuple<int, P, int>> H[maxn];
vector<P> ans(1);

vector<P> hull(vector<P> V) {
    vector<P> st;
    sort(V.begin(), V.end(), [&](P x, P y) { return x.x ^ y.x ? x.x < y.x : x.y > y.y; });
    for (auto &p : V) {
        if (!st.empty() && st.back().x == p.x) continue;
        while (st.size() > 1 && (p - st.back()) * (st[st.size() - 2] - st.back()) >= 0) st.pop_back();
        st.push_back(p);
    }
    return st;
}

vector<P> minkowski(vector<P> A, vector<P> B) {
    if (A.empty()) return B;
    if (B.empty()) return A;
    vector<P> C = {A[0] + B[0]};
    int i = 0, j = 0;
    while (i + 1 < A.size() || j + 1 < B.size()) {
        if (i + 1 == A.size() || j + 1 < B.size() && (A[i + 1] - A[i]) * (B[j + 1] - B[j]) > 0) C.push_back(A[i] + B[++j]);
        else C.push_back(A[++i] + B[j]);
    }
    return C;
}

int main() {
    scanf("%d %d", &n, &m), tot = n;
    for (int i = 1, u, v, a, b; i < n; i++) {
        scanf("%d %d %d %d", &u, &v, &a, &b);
        G[u].emplace_back(v, P(a, b));
        G[v].emplace_back(u, P(a, b));
    }
    iota(lst + 1, lst + n + 1, 1);
    auto ins = [&](int u, int v, P w) {
        val[++eid] = w, H[++tot].emplace_back(v, w, eid);
        H[v].emplace_back(tot, w, eid);
        H[tot].emplace_back(lst[u], P(), ++eid);
        H[lst[u]].emplace_back(tot, P(), eid), lst[u] = tot;
    };
    function<void(int, int)> build = [&](int u, int fa) {
        for (auto &e : G[u]) if (e.first ^ fa) {
            ins(u, e.first, e.second), build(e.first, u);
        }
    };
    function<void(int, int, int)> find_edge = [&](int u, int fa, int all) {
        sz[u] = 1;
        for (auto &e : H[u]) if (!del[get<2>(e)] && get<0>(e) ^ fa) {
            find_edge(get<0>(e), u, all), sz[u] += sz[get<0>(e)];
            int x = max(sz[get<0>(e)], all - sz[get<0>(e)]);
            if (x < mn) mn = x, eid = get<2>(e), ex = get<0>(e), ey = u;
        }
    };
    function<void(int, int, P, vector<P>&)> dfs = [&](int u, int fa, P p, vector<P> &V) {
        if (u <= n) V.push_back(p);
        for (auto &e : H[u]) if (!del[get<2>(e)] && get<0>(e) ^ fa) {
            dfs(get<0>(e), u, p + get<1>(e), V);
        }
    };
    function<void(int, int)> solve = [&](int u, int all) {
        if (all == 1) return;
        mn = INT_MAX, find_edge(u, 0, all), del[eid] = 1;
        vector<P> A, B;
        dfs(ex, 0, P(), A), dfs(ey, 0, val[eid], B);
        auto C = minkowski(hull(A), hull(B));
        copy(C.begin(), C.end(), back_inserter(ans));
        int o = ex;
        solve(ey, all - sz[o]), solve(o, sz[o]);
    };
    build(1, 0), solve(1, tot), ans = hull(ans);
    for (int i = 0, j = 0; i < m; i++) {
        auto eval = [&](int k) { return 1LL * i * ans[k].x + ans[k].y; };
        while (j + 1 < ans.size() && eval(j) < eval(j + 1)) j++;
        printf("%lld ", eval(j));
    }
    return 0;
}