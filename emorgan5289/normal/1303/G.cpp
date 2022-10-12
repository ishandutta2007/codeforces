#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct centroid {

    int c, s;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> sz;

    centroid(int n) : adj(n), vis(n, 0), sz(n) {}

    // add an edge between i and j
    void edge(int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    void dfs1(int i, int p) {
        sz[i] = 1;
        for (int j : adj[i])
            if (j != p && !vis[j]) {
                dfs1(j, i);
                sz[i] += sz[j];
            }
    }

    void dfs2(int i, int p) {
        bool v = sz[i] >= s;
        for (int j : adj[i])
            if (j != p && !vis[j]) {
                dfs2(j, i);
                v &= sz[j] <= s;
            }
        if (v) c = i;
    }

    int find(int r) {
        dfs1(r, r);
        s = sz[r]/2;
        dfs2(r, r);
        return c;
    }

    // returns the vertices of the tree ordered in a
    // pre-order dfs traversal of the centroid tree in O(VlogV)
    vector<int> solve() {
        vector<int> out, stk = {0};
        while (!stk.empty()) {
            int i = find(stk.back()); stk.pop_back();
            out.push_back(i);
            vis[i] = 1;
            for (int j : adj[i])
                if (!vis[j])
                    stk.push_back(j);
        }
        return out;
    }

    // returns {root, children-only adjacency list} of the centroid tree
    pair<int, vector<vector<int>>> full_tree() {
        int root = find(0);
        vector<vector<int>> out(adj.size());
        vector<int> stk = {root};
        while (!stk.empty()) {
            int i = stk.back(); stk.pop_back();
            vis[i] = 1;
            for (int j : adj[i])
                if (!vis[j]) {
                    int r = find(j);
                    out[i].push_back(r);
                    stk.push_back(r);
                }
        }
        return {root, out};
    }
};

template<typename T>
struct lineset {

    struct line {
        mutable T m, b, p;
        bool operator<(const line& o) const { return m < o.m; }
        bool operator<(T x) const { return p < x; }
    };

    multiset<line, less<>> hull;
    using it = decltype(hull.end());
    const static T max_T = numeric_limits<T>::max();
    const static T min_T = numeric_limits<T>::min();

    static T div(T x, T y) {
        return x/y - (is_integral<T>::value ? ((x^y) < 0 && x%y) : 0);
    }

    bool isect(it x, it y) {
        if (y == hull.end())
            return (x->p = max_T, 0);
        if (x->m == y->m)
            x->p = x->b > y->b ? max_T : min_T;
        else
            x->p = div(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }

    // remove all lines from the set
    void clear() {
        hull.clear();
    }

    // insert the line mx+b into the set, runs in O(logn).
    void insert(T m, T b) {
        it z = hull.insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z)) z = hull.erase(z);
        if (x != hull.begin() && isect(--x, y))
            isect(x, y = hull.erase(y));
        while ((y = x) != hull.begin() && (--x)->p >= y->p)
            isect(x, hull.erase(y));
    }

    // returns the maximum value of mx+b over all lines in the set, runs in O(logn).
    T query(T x) const {
        auto [m, b, _] = *hull.lower_bound(x);
        return m*x + b;
    }
};

const ll N = 150005;
vector<ll> adj[N];
ll a[N], out = -inf_ll;
bool vis[N];
lineset<ll> s;

void ins(int i, int p, ll x, ll y, ll d) {
    for (auto& j : adj[i])
        if (j != p && !vis[j])
            ins(j, i, x+a[j]*d, y+a[j], d+1);
    s.insert(y, x);
}

void chk(int i, int p, ll x, ll y, ll d) {
    for (auto& j : adj[i])
        if (j != p && !vis[j])
            chk(j, i, x+y+a[j], y+a[j], d+1);
    out = max(out, s.query(d-1)+x);
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    centroid cd(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        cd.edge(u, v);
        adj[u].pb(v), adj[v].pb(u);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (auto& r : cd.solve()) {
        debug(r, adj[r]);
        s.clear();
        s.insert(a[r], a[r]);
        for (auto& j : adj[r])
            if (!vis[j]) {
                chk(j, r, a[j], a[j], 2);
                ins(j, r, a[r]+2*a[j], a[r]+a[j], 3);
            }
        out = max(out, s.query(0));
        reverse(all(adj[r]));
        s.clear();
        s.insert(a[r], a[r]);
        for (auto& j : adj[r])
            if (!vis[j]) {
                chk(j, r, a[j], a[j], 2);
                ins(j, r, a[r]+2*a[j], a[r]+a[j], 3);
            }
        out = max(out, s.query(0));
        vis[r] = 1;
    }
    cout << out << "\n";
}