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

int n;
const int maxn = 1100;
vi e[maxn];
int w[maxn];
int sum[maxn];
map<pii, int> col;

void color(int v, int p, int &nxt, int mul) {
//    cerr << v << ' ' << p << ' ' << nxt << ' ' << mul << '\n';
    sum[v] = nxt++ * mul;
    col[{v, p}] = sum[v] - sum[p];
    for (int u: e[v]) if (u != p) color(u, v, nxt, mul);
}

int lb, rb;
bool done = false;

void dfs(int v, int p) {
    w[v] = 1;
    int pi = -1;
    forn(i, e[v].size()) {
        if (w[v] >= lb) {
            assert(w[v] <= rb);
            pi = i;
            break;
        }
        int u = e[v][i];
        if (u == p) continue;
        dfs(u, v);
        if (done) return;
        w[v] += w[u];
    }
    if (done) return;
    if (pi == -1 && w[v] >= lb) {
        assert(w[v] <= rb);
        pi = e[v].size();
    }
    if (pi != -1) {
        cerr << v << ' ' << pi << ' ' << w[v] << "!\n";
        int nxt1 = 1, nxt2 = 1;
        forn(i, e[v].size()) {
            int u = e[v][i];
//            cerr << v << ' ' << u << '\n';
            if (i < pi && u != p) color(u, v, nxt1, 1);
            else color(u, v, nxt2, w[v]);
        }
        done = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    if (n == 1) return 0;
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    lb = (n + 2) / 3; rb = (2 * n) / 3;
    dfs(0, -1);
    assert(done);
    for (auto w: col) {
        cout << w.fi.fi + 1 << ' ' << w.fi.se + 1 << ' ' << w.se << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}