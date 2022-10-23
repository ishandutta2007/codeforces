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

const int maxn = 1100;
int par[maxn], sz[maxn];
int d[maxn];

int root(int v) {
    return v == par[v] ? v : par[v] = root(par[v]);
}

void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
        par[x] = y;
        sz[y] += sz[x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        forn(i, n) cin >> d[i];
        forn(i, n) par[i] = i, sz[i] = 1;

        vi ord(n);
        iota(all(ord), 0);
        sort(all(ord), [](int v, int u){return d[v] > d[u];});
        for (int v: ord) {
            while (sz[root(v)] < d[v]) {
                cout << "? " << v + 1 << endl;
                int u;
                cin >> u;
                assert(u != -1);
                --u;
                unite(v, u);
            }
        }

        cout << "! ";
        forn(v, n) cout << root(v) + 1 << ' ';
        cout << endl;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}