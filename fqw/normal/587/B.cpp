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

const LL MOD = LL(1e9) + 7;

int main() {
    int n, k;
    LL l;
    scanf("%d%lld%d", &n, &l, &k);
    VI a(n);
    repn(i, n) scanf("%d", &a[i]);
    {
        VI vals = a;
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
        repn(i, n) a[i] = int(lower_bound(all(vals), a[i]) - vals.begin());
    }

    VL f(k + 1), g(k + 1);
    vector<VL> dp(k + 1, VL(n));
    repn(i, n) dp[1][i] = 1;
    rep(num, 2, k) {
        VL sum(n);
        repn(i, n)(sum[a[i]] += dp[num - 1][i]) %= MOD;
        repn(v, n - 1)(sum[v + 1] += sum[v]) %= MOD;
        repn(i, n) dp[num][i] = sum[a[i]];
    }
    rep(num, 1, k) {
        repn(i, n) {
            (f[num] += dp[num][i]) %= MOD;
            if(i < int(l % n)) (g[num] += dp[num][i]) %= MOD;
        }
    }

    LL ans = 0;
    rep(num, 1, k) {
        LL r = l / n;
        if(r >= num) (ans += f[num] * ((r - num + 1) % MOD)) %= MOD;
        if(r + 1 >= num) (ans += g[num]) %= MOD;
    }
    printf("%lld\n", ans);

    return 0;
}