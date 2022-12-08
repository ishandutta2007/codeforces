#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// {{{
// clang-format off
#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define irep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
// clang-format on
// }}}

LL solve(LL need, VI trips) {
    VPI es;
    LL maxd = 0;
    for(int d : trips) {
        setmax(maxd, LL(d));
        es.pb(mp(d, 1));
        es.pb(mp(d * 2, -1));
    }
    if(need <= 0) return maxd;
    sort(all(es));
    LL d = 0, cnt = 0;
    for(const auto& e : es) {
        LL dis = e.fi - d;
        if(cnt * dis >= need) {
            dis = (need + cnt - 1) / cnt;
            return max(maxd, d + dis);
        }
        need -= cnt * dis, d += dis;
        cnt += e.se;
    }
    return 1ll << 55;
}

int main() {
    int n, k, s, t;
    scanf("%d%d%d%d", &n, &k, &s, &t);
    VPI cars(n);
    repn(i, n) scanf("%d%d", &cars[i].fi, &cars[i].se);
    VI trips, pos(k);
    repn(i, k) scanf("%d", &pos[i]);
    sort(all(pos));
    int last = 0;
    for(int x : pos) {
        trips.pb(x - last);
        last = x;
    }
    trips.pb(s - last);

    if(t < s) {
        printf("-1\n");
        return 0;
    }
    LL min_tank = solve(s * 2 - t, trips);
    int ans = 1 << 30;
    for(const auto& car : cars) {
        if(car.se >= min_tank) setmin(ans, car.fi);
    }
    if(ans == (1 << 30)) ans = -1;
    printf("%d\n", ans);

    return 0;
}