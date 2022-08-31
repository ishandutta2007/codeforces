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

const int maxn = 310000, maxa = 310000;
const i64 P = 1000000000 + 7;
i64 fact[maxn], tcaf[maxn];
i64 pcnk[maxn], coef[maxn];

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

int mind[maxa + 1];
vi ps;

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
    fact[0] = 1;
    for1(i, n) fact[i] = i * fact[i - 1] % P;
    tcaf[n] = deg(fact[n], -1);
    ford(i, n) tcaf[i] = tcaf[i + 1] * (i + 1) % P;

    forn(i, n) pcnk[i + 1] = (pcnk[i] + fact[n - 1] * tcaf[i] % P * tcaf[n - i - 1]) % P;

    forn(i, n) {
        coef[i] = (pcnk[n - i - 1] - (pcnk[n] - pcnk[n - i]) + P) % P;
//        cerr << i << ' ' << coef[i] << '\n';
    }

    forn(i, maxa + 1) mind[i] = i;
    fore(i, 2, maxa) {
        if (i == mind[i]) ps.pb(i);
        for (auto p: ps) {
            if (1LL * i * p > maxa) break;
            if (p > mind[i]) break;
            mind[i * p] = p;
        }
    }

    map<int, vi> ds;
    forn(i, n) {
        int x;
        cin >> x;
        while (x > 1) {
            int p = mind[x], z = 0;
//            cerr << x << ' ' << p << '\n';
            while (x % p == 0) x /= p, ++z;
            ds[p].pb(z);
        }
    }

    i64 ans = 0;
    for (auto &[p, v]: ds) {
        sort(rall(v));
//        cerr << p << ": ";
//        for (int x: v) cerr << x << ' ';
//        cerr << '\n';
        forn(i, v.size()) (ans += v[i] * coef[i]) %= P;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}