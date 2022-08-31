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

    int n, L;
    cin >> n >> L;
    int x = 0;
    vector<pair<int, double> > segs;
    forn(i, n) {
        int lx, rx;
        double s;
        cin >> lx >> rx >> s;
        if (lx > x) segs.pb({lx - x, 0.0});
        segs.pb({rx - lx, s});
        x = rx;
    }
    if (x < L) segs.pb({L - x, 0.0});
    map<double, double> parts;
    parts[1.0] = 1e18;
    double T0 = 0.0;
    for (auto w: segs) {
        int l = w.fi;
        double v0 = w.se;
        parts[1.0 / (1.0 + v0)] += (v0 < 1e-9 ? 1e9 : l / v0) + l / (v0 + 2);
        T0 += l / (v0 + 2);
        double to_cut = l / (v0 + 2);
        while (to_cut > 1e-9) {
            auto w = parts.begin();
//            cerr << "C " << w->fi << ' ' << w->se << ' ' << to_cut << ' ' << T0 << '\n';
            double z = min(w->se, to_cut);
            to_cut -= z;
            parts.begin()->se -= z;
            T0 += z * w->fi;
            if (parts.begin()->se < 1e-9) parts.erase(parts.begin());
        }
//        cerr << l << ' ' << v0 << ' ' << T0 << '\n';
    }
    
    cout << T0 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}