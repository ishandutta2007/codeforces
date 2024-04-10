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
#define popcount __builtin_popcount
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

LL solve(VPI as) {
    if(sz(as) < 2) return 0;

    VI nums;
    for(PII a : as) {
        nums.pb(a.fi);
        nums.pb(max(1, a.fi - a.se));
    }
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    const auto parse = [&](int x) {
        return int(lower_bound(all(nums), x) - nums.begin());
    };
    VPI es;
    for(PII a : as) {
        es.pb(mp(a.fi, parse(max(1, a.fi - a.se))));
        es.pb(mp(a.fi + a.se + 1, -parse(a.fi) - 1));
    }
    sort(all(es));

    VI tr(sz(nums) + 1);
    const auto add = [&](int x, int delta) {
        x = sz(nums) - x;
        for(; x < sz(tr); x += x & -x) tr[x] += delta;
    };
    const auto sum_ge = [&](int x) {
        LL ans = 0;
        x = sz(nums) - x;
        for(; x > 0; x -= x & -x) ans += tr[x];
        return ans;
    };

    LL ans = 0;
    for(PII e : es) {
        if(e.se >= 0) {
            ans += sum_ge(e.se);
            add(parse(e.fi), 1);
        } else {
            add(-e.se - 1, -1);
        }
    }
    return ans;
}

int main() {
    const int F = 10000;
    int n, k;
    scanf("%d%d", &n, &k);
    vector<VPI> as(F);
    repn(i, n) {
        int x, r, f;
        scanf("%d%d%d", &x, &r, &f);
        --f;
        as[f].pb(mp(x, r));
    }
    VL single(F);
    repn(f, F) single[f] = solve(as[f]);
    LL ans = accumulate(all(single), 0ll);
    repn(f, F) rep(f2, max(0, f - k), f - 1) {
        VPI tmp = as[f];
        tmp.insert(tmp.end(), all(as[f2]));
        ans += solve(tmp) - single[f] - single[f2];
    }
    printf("%lld\n", ans);
    return 0;
}