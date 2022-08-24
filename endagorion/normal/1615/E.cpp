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
vi e[maxn];
int h[maxn];

void dfsh(int v, int p) {
    h[v] = 0;
    for (int u: e[v]) {
        if (u == p) continue;
        dfsh(u, v);
        uax(h[v], h[u] + 1);
    }
    sort(all(e[v]), [&](int u, int w){return h[u] > h[w];});
}

vi ord;

void dfsord(int v, int p, int l) {
    bool anyc = false;
    for (int u: e[v]) {
        if (u == p) continue;
        if (!anyc) dfsord(u, v, l + 1), anyc = true;
        else dfsord(u, v, 1);
    }
    int r = !anyc ? l : 0;
    ord.pb(r);
//    cerr << v << ' ' << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfsh(0, -1);
    dfsord(0, -1, 1);
    sort(rall(ord));

    i64 W = n;
    i64 ans = -1LL * (n / 2) * (n - n / 2);
    forn(i, k) {
        W -= ord[i];
        i64 b = n / 2, r = i + 1;
        i64 res = 1e18;
        if (b <= W) uin(res, (n - r - b) * (r - b));
        if (b + 1 <= W) uin(res, (n - r - b - 1) * (r - b - 1));
        uin(res, (n - r - W) * (r - W));
//        cerr << r << ' ' << W << ' ' << res << '\n';
        uax(ans, res);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}