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

void ins(pii &p, int x) {
    if (x == -1 || p.fi == x || p.se == x) return;
    if (x > p.fi) swap(p.fi, x);
    if (x > p.se) swap(p.se, x);
}

const int K = 21;
int s[1 << K];

void mark(int m) {
    if (s[m]) return;
    s[m] = 1;
    forn(i, K) if ((m >> i) & 1) mark(m ^ (1 << i));
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
    vi a(n);
    forn(i, n) cin >> a[i];
    vector<pii> occ(1 << K, {-1, -1});
    forn(i, n) ins(occ[a[i]], i);
    ford(i, 1 << K) forn(j, K) if ((i >> j) & 1) {
        pii &p = occ[i], &q = occ[i ^ (1 << j)];
        ins(q, p.fi);
        ins(q, p.se);
    }

    vvi q(n);

    forn(i, 1 << K) if (occ[i].se != -1) {
//        cerr << i << ' ' << occ[i].se << '\n';
        q[occ[i].se].pb(i);
    }

    int ans = 0;
    forn(i, n) {
        for (int x: q[i]) {
            int mask = 0;
            ford(j, K) {
                if ((x >> j) & 1) continue;
                if (s[mask | (1 << j)]) mask |= 1 << j;
            }
            uax(ans, x + mask);
        }
        mark(a[i]);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}