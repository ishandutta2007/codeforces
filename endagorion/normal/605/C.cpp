#include <iostream>
#include <tuple>
#include <sstream>
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
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TPoint {
    i64 x, y;

    TPoint(i64 x = 0, i64 y = 0)
        : x(x)
        , y(y)
    {
    }

    TPoint operator-(const TPoint &p) const {
        return TPoint(x - p.x, y - p.y);
    }

    i64 operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }

    bool operator<(const TPoint &p) const {
        return mp(x, y) < mp(p.x, p.y);
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

    int n;
    i64 x, y;
    cin >> n >> x >> y;
    vector<TPoint> p(n);
    forn(i, n) cin >> p[i].x >> p[i].y;
    sort(all(p));
    vector<TPoint> st;
//    st.pb(TPoint(0, 0));
    forn(i, n) {
//        if (i + 1 < n && p[i].x == p[i + 1].x) continue;
        while (st.size() > 1) {
            TPoint prv = st.back(), pprv = st[st.size() - 2];
            if ((p[i] - pprv) % (prv - pprv) <= 0) st.pop_back();
            else break;
        }
        while (!st.empty() && st.back() % p[i] == 0) st.pop_back();
        st.pb(p[i]);
    }
//    for (TPoint p: st) cerr << p.x << ' ' << p.y << '\n';
    double ans = 1e9;
    TPoint Q = TPoint(x, y);
    forn(i, st.size()) {
        uin(ans, max(1.0 * Q.x / st[i].x, 1.0 * y / st[i].y));
        if (i + 1 < st.size()) {
            if ((Q % st[i]) >= 0 && (st[i + 1] % Q) >= 0) {
                uin(ans, 1.0 / ((st[i + 1] - st[i]) % st[i]) * ((st[i + 1] - st[i]) % Q));
            }
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}