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

map<i64, i64> sp;

i64 T;

pi64 next_sp(i64 t) { // >= t
    auto it = sp.lower_bound(t);
    if (it == sp.end()) return *sp.begin();
    return *it;
}

pi64 prev_sp(i64 t) { // < t
    auto it = sp.lower_bound(t);
    if (it == sp.begin()) return *sp.rbegin();
    return *--it;
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
    cin >> n >> T;
    vi64 g(n), c(n), d(n - 1);
    forn(i, n) cin >> g[i] >> c[i];
    forn(i, n - 1) cin >> d[i];

    i64 t0 = 0;
    ford(i, n) {
/*        cerr << i << ' ' << t0 << ": ";
        for (auto [x, v]: sp) cerr << x << ' ' << v << ", ";
        cerr << '\n';*/
        i64 r = T - g[i];
        if (!sp.empty()) {
            auto [x, v] = prev_sp((t0 + 1) % T);
            v -= (t0 - x + T) % T;
            uax(v, 0LL);
            while (!sp.empty()) {
                auto [xx, vv] = prev_sp(t0 % T);
                i64 dist = (t0 - xx + T) % T;
                if (dist <= r) sp.erase(xx);
                else break;
            }
            sp[(t0 - r + T) % T] = v + r;
        } else sp[(t0 - r + T) % T] = r;

        if (i) {
            (t0 += T + d[i - 1]) %= T;
            (t0 += T + (c[i] - c[i - 1])) %= T;
        }
    }

    i64 ans = 1e18;
    if (sp.empty()) ans = 0;
    else {
        for (auto [x, v]: sp) {
            auto [xx, vv] = next_sp((x + 1) % T);
            uin(ans, max(0LL, v - (xx - x - 1 + T) % T));
        }
    }
    ans += accumulate(all(d), 0LL);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}