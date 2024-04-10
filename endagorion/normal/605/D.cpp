#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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

const int maxn = 210000;
int a[maxn], b[maxn], c[maxn], d[maxn];
int vis[maxn], dist[maxn], prv[maxn];

struct TNode {
    vi z;
    int L, R;
    int left, right;

    TNode(int L = -1, int R = -1)
        : z()
        , L(L)
        , R(R)
        , left(-1)
        , right(-1)
    {
    }
};

const int MAXT = 520000;
TNode t[MAXT];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L > 1) {
        int M = (L + R) / 2;
        t[node].left = buildTree(L, M);
        t[node].right = buildTree(M, R);
    }
    return node;
}

void addEntry(int node, int i) {
    TNode &n = t[node];
    if (a[i] < n.L || a[i] >= n.R) return;
    n.z.pb(i);
    addEntry(n.left, i);
    addEntry(n.right, i);
}

bool cmp(int i, int j) {
    return b[i] > b[j];
}

void perform(int node, int v, vi &q) {
    TNode &n = t[node];
    if (n.L > c[v]) return;
    if (n.R <= c[v] + 1) {
        while (!n.z.empty()) {
            int u = n.z.back();
            if (b[u] > d[v]) break;
            if (!vis[u]) {
                q.pb(u);
                vis[u] = 1;
                prv[u] = v;
                dist[u] = dist[v] + 1;
            }
            n.z.pop_back();
        }
        return;
    }    
    perform(n.left, v, q);
    perform(n.right, v, q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vi x, y;
    x.pb(0); y.pb(0);
    forn(i, n) x.pb(a[i]), y.pb(b[i]), x.pb(c[i]), y.pb(d[i]);
    sort(all(x)); sort(all(y));
    x.erase(unique(all(x)), x.end());
    y.erase(unique(all(y)), y.end());
    map<int, int> xen, yen;
    forn(i, x.size()) xen[x[i]] = i;
    forn(i, y.size()) yen[y[i]] = i;
    forn(i, n) a[i] = xen[a[i]], b[i] = yen[b[i]], c[i] = xen[c[i]], d[i] = yen[d[i]];

    int root = buildTree(0, x.size());

    vi z;
    forn(i, n) z.pb(i);
    sort(all(z), cmp);
    for (int x: z) addEntry(root, x);
   
    vi q;
    forn(i, n) {
        dist[i] = 1e9;
        if (a[i] == 0 && b[i] == 0) q.pb(i), vis[i] = 1, dist[i] = 0;
    }

    forn(cur, q.size()) {
        int v = q[cur];
        perform(root, v, q);
    }
    if (dist[n - 1] > 1e8) cout << -1 << '\n';
    else {
        vi path;
        int v = n - 1;
        path.pb(v);
        while (dist[v]) {
            v = prv[v];
            path.pb(v);
        }
        cout << path.size() << '\n';
        reverse(all(path));
        for (int v: path) cout << v + 1 << ' ';
        cout << '\n';
    }
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}