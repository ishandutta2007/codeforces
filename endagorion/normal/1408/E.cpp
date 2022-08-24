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

const int maxn = 210000;
int par[maxn];

int root(int x) {
    return x == par[x] ? x : par[x] = root(par[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vi64 a(n), b(m);
    forn(i, n) cin >> a[i];
    forn(i, m) cin >> b[i];
    vector<pii> e;
    i64 cost = 0;
    forn(i, n) {
        int s;
        cin >> s;
        forn(j, s) {
            int x;
            cin >> x;
            --x;
            e.pb(mp(i, x));
            cost += a[i] + b[x];
        }
    }
    sort(all(e), [&](pii x, pii y){return a[x.fi] + b[x.se] > a[y.fi] + b[y.se];});
    forn(i, n + m) par[i] = i;
    for (auto p: e) {
        int x = p.fi, y = p.se + n;
        if (root(x) == root(y)) continue;
        cost -= a[x] + b[y - n];
        par[root(x)] = root(y);
    }
    cout << cost << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}