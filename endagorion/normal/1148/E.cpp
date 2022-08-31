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
    vector<pi64> a(n), b(n);
    forn(i, n) cin >> a[i].fi, a[i].se = i;
    forn(i, n) cin >> b[i].fi, b[i].se = i;
    sort(all(a));
    sort(all(b));
    vector<pi64> d;
    vector<tuple<i64, i64, i64> > res;
    bool ok = true;
    forn(i, n) {
        if (!ok) break;
        i64 del = b[i].fi - a[i].fi;
        if (!del) continue;
        if (del > 0) d.pb({a[i].se, del});
        else {
            while (del != 0) {
                if (d.empty()) {
                    ok = false;
                    break;
                }
                i64 z = min(-del, d.back().se);
                assert(z);
                res.pb(mt(d.back().fi + 1, a[i].se + 1, z));
                d.back().se -= z;
                del += z;
                if (!d.back().se) d.pop_back();
            }
        }
    }
    ok &= d.empty();
    if (!ok) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << res.size() << '\n';
        for (auto w: res) {
            i64 a, b, c;
            tie(a, b, c) = w;
            cout << a << ' ' << b << ' ' << c << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}