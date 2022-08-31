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

struct TRect {
    i64 x, y, a;

    bool operator<(const TRect &r) const {
        return x < r.x;
    }
};

const int maxn = 1100000;
TRect a[maxn];
i64 dp[maxn];

bool ccw(pi64 a, pi64 b, pi64 c) {
    i64 dx1 = c.fi - a.fi, dy1 = c.se - a.se;
    i64 dx2 = b.fi - a.fi, dy2 = b.se - a.se;
    assert(dx1 > 0 && dx2 > 0);
    if (dy1 / dx1 != dy2 / dx2) return dy1 / dx1 > dy2 / dx2;
    dy1 %= dx1; dy2 %= dx2;
    return dx2 * dy1 - dx1 * dy2 >= 0;
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
    scanf("%d", &n);
    forn(i, n) scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].a);
    sort(a, a + n);
    vector<pi64> st = {{0, 0}};
    int opt = 0;
    forn(i, n) {
        i64 val = st[opt].se - st[opt].fi * a[i].y;
        while (opt + 1 < (int)st.size()) {
            i64 nval = st[opt + 1].se - st[opt + 1].fi * a[i].y;
            if (nval < val) break;
            ++opt;
            val = nval;
        }
        dp[i] = a[i].x * a[i].y - a[i].a + max(0LL, val);
        pi64 np = {a[i].x, dp[i]};
//        cerr << i << ' ' << a[i].x << ' ' << a[i].y << ' ' << a[i].a << ' ' << dp[i] << ' ' << val << '\n';
        while (st.size() > 1 && ccw(st[st.size() - 2], st.back(), np)) st.pop_back();
        uin(opt, (int)st.size() - 1);
        st.pb(np);
    }
    cout << *max_element(dp, dp + n) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}