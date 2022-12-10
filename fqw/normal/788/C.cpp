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

const int INF = 1 << 30;

struct Poss {
    VI f;

    Poss(int limit) : f(limit + 1, INF) { f[0] = 0; }
};

Poss go(VI xs, int limit, int) {
    Poss f(limit);
    for(int x : xs) {
        rep(i, 0, limit - x) { setmin(f.f[i + x], f.f[i] + 1); }
    }
    return f;
}

int solve(int target, VI has) {
    if(has[target]) return 1;

    VI l, r;
    irep(i, target - 1, 0) if(has[i]) l.pb(target - i);
    rep(i, target + 1, 1000) if(has[i]) r.pb(i - target);
    if(l.empty() || r.empty()) return -1;
    const int bound = l[0] + r[0];

    const int limit = min(l.back(), r.back()) * (bound - 1);
    // printf("%d %d\n",bound,limit);
    Poss fl = go(l, limit, bound - 1);
    Poss fr = go(r, limit, bound - 1);
    int ans = INF;
    rep(i, 1, limit) if(fl.f[i] < INF && fr.f[i] < INF) {
        setmin(ans, fl.f[i] + fr.f[i]);
    }
    assert(ans <= bound);
    return ans;
}

void test() {
    int target = 500;
    VI has(1001);
    rep(i, 0, 100) has[i] = 1;
    rep(i, 900, 1000) has[i] = 1;
    int ans = solve(target, has);
    printf("%d\n", ans);
}

int main() {
    //test();
    //exit(0);

    int target, k;
    scanf("%d%d", &target, &k);
    VI has(1001);
    repn(i, k) {
        int x;
        scanf("%d", &x);
        has[x] = 1;
    }
    int ans = solve(target, has);
    printf("%d\n", ans);
    return 0;
}