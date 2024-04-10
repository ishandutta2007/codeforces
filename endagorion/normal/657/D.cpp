#include <iostream>
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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

bool cmp(pii a, pii b) {
    return 1LL * a.fi * b.se > 1LL * a.se * b.fi;
}

bool eq(pii a, pii b) {
    return !cmp(a, b) && !cmp(b, a);
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
    vector<pii> a(n);
    i64 TT = 0;
    forn(i, n) cin >> a[i].fi;
    forn(i, n) cin >> a[i].se, TT += a[i].se;
    sort(all(a), cmp);
    double l = 0.0, r = 1.0;
    forn(its, 50) {
        double m = 0.5 * (l + r);
//        cerr << m << '\n';
//        map<int, double> lowt, hight;
        i64 T = 0;
        vector< pair<int, double> > evs;
        for (int i = 0; i < n; ) {
            int j = i;
            i64 st = 0;
            while (j < n && eq(a[j], a[i])) st += a[j++].se;
            for (int k = i; k < j; ++k) {
                evs.pb(mp(a[k].fi, a[k].fi * (1.0 - m * (T + st) / TT)));
                evs.pb(mp(a[k].fi, a[k].fi * (1.0 - m * (T + a[k].se) / TT)));
            }
            T += st;
            i = j;
        }
        double pp = -1e18;
        bool ok = true;
        sort(all(evs));
        for (int i = 0; i < evs.size(); ) {
            int p = evs[i].fi;
            double lowt = 1e18, hight = -1e18;
            while (i < evs.size() && evs[i].fi == p) {
                double t = evs[i].se;
                uin(lowt, t);
                uax(hight, t);
                ++i;
            }
            ok &= lowt > pp;
            pp = hight;
        }
        (ok ? l : r) = m;
    }
    cout << l << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}