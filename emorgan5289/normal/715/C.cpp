#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

// returns (b^r)%m, runs in O(logr) time.
template<typename T>
T powmod(T b, T r, T m) {
    T out = 1;
    for (T t = 1; t <= r; t <<= 1) {
        if (r&t) out = (out*b)%m;
        b = (b*b)%m;
    }
    return out;
}

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

// based on something from KACTL, requires 64bit C++
struct fastmod {
    __int128_t b, m;
    fastmod(int64_t x) : b(x), m(((__int128_t)1<<64) / x) {}
    int64_t reduce(int64_t x) {
        __int128_t q = (m*x)>>64;
        __int128_t r = x - q*b;
        return r >= b ? r - b : r;
    }
};

const int maxn = 100005;
vector<pair<ll, int>> adj[maxn];
map<ll, ll> f;
bool vis[maxn];
ll n, m, d;

void ins(int i, int k, ll p, ll r) {
    f[p]++;
    for (auto& [e, j] : adj[i])
        if (!vis[j] && j != k)
            ins(j, i, (p+r*e)%m, (r*10)%m);
}

void rem(int i, int k, ll p, ll r) {
    f[p]--;
    for (auto& [e, j] : adj[i])
        if (!vis[j] && j != k)
            rem(j, i, (p+r*e)%m, (r*10)%m);
}

ll qry(int i, int k, ll p, ll r) {
    ll out = f.count(p) ? f[p] : 0;
    for (auto& [e, j] : adj[i])
        if (!vis[j] && j != k)
            out += qry(j, i, (p+m-((r*e)%m))%m, (r*d)%m);
    return out;
}

void gcd(ll x,ll y,ll &a,ll &b)
{
    if(!y){a=1;b=0;return;}
    gcd(y,x%y,b,a);b-=x/y*a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ll ignore;
    gcd(10ll,m,d,ignore);
    d = ((d%m)+m)%m;
    debug(10, d, m);
    centroid cd(n);
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        cd.edge(u, v);
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
    ll out = 0;
    for (auto& r : cd.solve()) {
        f.clear();
        f[0]++;
        for (auto& [e, i] : adj[r])
            if (!vis[i])
                ins(i, r, e%m, 10%m);
        out += f[0]-1;
        for (auto& [e, i] : adj[r])
            if (!vis[i]) {
                rem(i, r, e%m, 10%m);
                out += qry(i, r, (m-((e*d)%m))%m, (d*d)%m);
                ins(i, r, e%m, 10%m);
            }
        vis[r] = 1;
        debug(r, f, out);
    }
    cout << out << "\n";
}