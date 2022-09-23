#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 1e6 + 100;
const int LOG = 25;
const int mod = 1e9 + 7;
const int MX = 1e6 + 100;
typedef long long li;
const li MOD = 1000000000949747713ll;


int A[MX], B[MX], C[MX];
int parent[MAXN];

void build(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

int find_parent(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v]);
}

mt19937 mt(228);

bool union_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (mt() & 1)
            swap(a, b);
        parent[b] = a;
        return true;
    }
    return false;
}

vector<pii> g[MAXN];

int up[MAXN][LOG];
int val[MAXN][LOG];
int h[MAXN];

void dfs(int v, int p, int dis) {
    up[v][0] = p;
    val[v][0] = dis;
    for (int i = 1; i < LOG; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int i = 1; i < LOG; ++i) {
        val[v][i] = max(val[up[v][i - 1]][i - 1], val[v][i - 1]);
    }
    for (pii x:g[v]) {
        int to = x.fi;
        if (to == p)
            continue;
        h[to] = h[v] + 1;
        dfs(to, v, x.se);

    }
}

int lca(int a, int b) {
    if (h[b] < h[a])
        swap(a, b);
    int dif = h[b] - h[a];
    for (int i = 0; i < LOG; ++i) {
        if (dif & (1 << i))
            b = up[b][i];
    }
    assert(h[a] == h[b]);
    if (a == b)
        return a;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int get_mx(int a, int lc) {
    assert(h[lc] <= h[a]);

    int res = 0;
    if (a == lc)
        return res;
    for (int i = LOG - 1; i >= 0; --i) {
        if (h[up[a][i]] > h[lc]) {
            res = max(res, val[a][i]);
            a = up[a][i];
        }
    }
    res = max(res, val[a][0]);
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> cc;
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cc.pb({c, i});
        A[i] = a;
        B[i] = b;
        C[i] = c;
    }
    sort(all(cc));

    vector<int> rest;
    build(n);
    for (auto x:cc) {
        int id = x.se;
        if (union_set(A[id], B[id])) {
            g[A[id]].pb({B[id], C[id]});
            g[B[id]].pb({A[id], C[id]});
        } else {
            rest.pb(id);
        }
    }
    sort(all(rest));
    dfs(1, 1, 0);

    for (int v: rest) {

        int lc = lca(A[v], B[v]);
        dout << A[v] << " " << B[v] << " : " << lc << endl;
        int res = max(get_mx(A[v], lc), get_mx(B[v], lc));

        cout << res << " ";


    }


}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#else
    //freopen("roboherd.in", "r", stdin);
    //freopen("roboherd.out", "w", stdout);

#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int t = 1;
    while (t--)
        solve();
    if (debug)
        cerr << endl << "time : " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}