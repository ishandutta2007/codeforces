#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TDancer {
    int g, p, t, id;

    bool operator<(const TDancer &d) const {
        if (p - t != d.p - d.t) return p - t < d.p - d.t;
        if (g != d.g) return g < d.g;
        if (g == 1) return p > d.p;
        return p < d.p;
    }

    int group() const {
        return p - t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, w, h;
    cin >> n >> w >> h;
    vector<TDancer> d;
    forn(i, n) {
        int g, p, t;
        cin >> g >> p >> t;
        g ^= 3;
        d.pb({g, p, t, i});
    }

    sort(all(d));
    vector<pii> ans(n);
    int L = 0;
    while (L < n) {
        int R = L;
        while (R < n && d[L].group() == d[R].group()) ++R;
        vector<pii> vfin, hfin;
        for (int i = L; i < R; ++i) {
            if (d[i].g == 1) vfin.pb({w, d[i].p});
            else hfin.pb({d[i].p, h});
        }
        for (auto w: vfin) hfin.pb(w);
        forn(i, R - L) ans[d[L + i].id] = hfin[i];
        L = R;
    }
    forn(i, n) cout << ans[i].fi << ' ' << ans[i].se << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}