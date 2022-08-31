#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 110000;
vi e[maxn];
int dp_down[maxn], dp_up[maxn];
int h[maxn], par[maxn];
int query_down[maxn];
int forb[maxn];
int max_ans = 0;

int eval(multiset<int> &vals) {
    if (vals.empty()) return 0;
    vi v(all(vals));
    reverse(all(v));
    int ans = 1;
    forn(i, v.size()) uax(ans, i + max(v[i], 1));
//    for (int x: v) cerr << x << ' ';
//    cerr << ": " << ans << '\n';
    return ans;
}

int eval2(multiset<int> vals) {
    int ans = 0;
    int ex = 0;
    vi v(all(vals));
    reverse(all(v));
/*    while (!vals.empty()) {
        int x = *vals.rbegin();
        vals.erase(vals.find(x));
        uax(ans, ex + max(x, 1) + eval(vals));
        ++ex;
    }*/
    int maxs = 0;
    ford(i, v.size()) {
        uax(ans, i + max(v[i], 1) + maxs);
        maxs = max(maxs + 1, max(v[i], 1));
    }
    return ans;
}

void dfs_down(int v, int p) {
    multiset<int> vals;
    query_down[v] = v;
    int maxch = -1;
    for (int u: e[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        par[u] = v;
        dfs_down(u, v);
        vals.insert(dp_down[u]);
        if (uax(maxch, dp_down[u])) query_down[v] = query_down[u];
    }
    dp_down[v] = eval(vals);
}

map<int, int> wo_info(multiset<int> vals) {
    vi v(all(vals));
    reverse(all(v));
    vi maxp(v.size() + 1), maxs(v.size() + 1);
    forn(i, v.size()) maxp[i + 1] = max(maxp[i], i + max(v[i], 1));
    forn(i, v.size()) maxs[i + 1] = max(maxs[i], (int)v.size() - i - 1 + max(v[v.size() - i - 1], 1));
    map<int, int> ans;
    forn(i, v.size()) ans[v[i]] = max(maxp[i], maxs[v.size() - i - 1] - 1);
    return ans;
}

void dfs_up(int v, int p, int val_up) {
    multiset<int> vals;
    if (val_up != -1) vals.insert(val_up);
    for (int u: e[v]) {
        if (u != p) vals.insert(dp_down[u]);
    }
    uax(max_ans, eval2(vals));
/*    cerr << v << ' ' << p << ' ' << val_up << '\n';
    for (int x: vals) cerr << x << ' ';
    cerr << ": " << eval2(vals) << '\n';*/
    auto wo = wo_info(vals);
    for (int u: e[v]) {
        if (u == p) continue;
//        vals.erase(vals.find(dp_down[u]));
        dfs_up(u, v, wo[dp_down[u]]);
//        vals.insert(dp_down[u]);
    }
}

int desc(int v, int anc) {
    while (par[v] != anc) v = par[v];
    return v;
}

int solve_down(int v) {
    vi children;
    for (int u: e[v]) {
        if (forb[u] || h[u] < h[v]) continue;
        children.pb(u);
    }
    sort(all(children), [&](int v, int u){return dp_down[v] > dp_down[u];});
    for (int u: children) {
        int q = query_down[u];
        forb[u] = 1;
//        cerr << "Query from " << v << ", child " << u << '\n';
        cout << "? " << q + 1 << endl;
        int result;
        cin >> result;
        --result;
        if (result == v) continue;
        if (result == q) return q;
        forb[desc(q, result)] = 1;
        return solve_down(result);
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs_down(0, -1);
    dfs_up(0, -1, -1);
    cout << max_ans << endl;
    int root;
    cin >> root;
    --root;
    h[root] = 0;
    dfs_down(root, -1);
    dfs_up(root, -1, -1);

    vi children = e[root];
    sort(all(children), [&](int v, int u){return dp_down[v] > dp_down[u];});
    bool done = false;
    for (int v: children) {
        forb[v] = 1;
        int q = query_down[v];
        cout << "? " << q + 1 << endl;
        int result;
        cin >> result;
        --result;
        if (result == root) {
            continue;
        } else {
            if (result != q) forb[desc(q, result)] = 1;
            int a = solve_down(result);
            int b = solve_down(root);
            cout << "! " << a + 1 << ' ' << b + 1 << endl;
            done = true;
            break;
        }
    }
    if (!done) cout << "! " << root + 1 << ' ' << root + 1 << endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}