#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
typedef vector<PDD> VPD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VPI> VVPI;
typedef vector<VPL> VVPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
VI read_vi(int n = -1) { if (n < 0) scanf("%d", &n); VI a(n); repn(i, n) scanf("%d", &a[i]); return a; }
VL read_vl(int n = -1) { if (n < 0) scanf("%d", &n); VL a(n); repn(i, n) scanf("%lld", &a[i]); return a; }
VD read_vd(int n = -1) { if (n < 0) scanf("%d", &n); VD a(n); repn(i, n) scanf("%lf", &a[i]); return a; }
VPI read_vpi(int n = -1) { if (n < 0) scanf("%d", &n); VPI a(n); repn(i, n) scanf("%d%d", &a[i].fi,&a[i].se); return a; }
VPL read_vpl(int n = -1) { if (n < 0) scanf("%d", &n); VPL a(n); repn(i, n) scanf("%lld%lld", &a[i].fi,&a[i].se); return a; }
VPD read_vpd(int n = -1) { if (n < 0) scanf("%d", &n); VPD a(n); repn(i, n) scanf("%lf%lf", &a[i].fi,&a[i].se); return a; }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

int solve(int p, int k) {
    const LL MOD = LL(1e9) + 7;
    if(k == 0) {
        LL ans = 1;
        repn(i, p - 1)(ans *= p) %= MOD;
        return int(ans);
    }
    VI cnt(p + 1);
    VB vis(p, false);
    repn(x, p) if(!vis[x]) {
        int len = 0;
        for(int y = x; !vis[y]; y = int(LL(y) * k % p)) {
            vis[y] = true, ++len;
        }
        ++cnt[len];
    }

    VL sum(p + 1);
    replr(len, 1, sz(cnt)) {
        for(int j = len; j < sz(cnt); j += len) {
            (sum[j] += cnt[len] * LL(len)) %= MOD;
        }
    }
    LL ans = 1;
    repn(len, sz(cnt)) {
        repn(i, cnt[len]) { (ans *= sum[len]) %= MOD; }
    }
    return int(ans);
}

int vio(int p, int k) {
    int ans = 0;
    VI f(p);
    const function<void(int)> dfs = [&](int cur) {
        if(cur == p) {
            bool ok = true;
            repn(i, p) if(f[i * k % p] != k * f[i] % p) ok = false;
            if(ok) ++ans;
            return;
        }
        for(f[cur] = 0; f[cur] < p; ++f[cur]) {
            dfs(cur + 1);
        }
    };
    dfs(0);
    return ans;
}

void check() {
    for(int p = 3; p <= 15; ++p) {
        repn(k, p) {
            printf("%d %d\n", p, k);
             cout<<">> "<<solve(p,k)<<" "<<vio(p,k)<<endl;
            assert(solve(p, k) == vio(p, k));
        }
    }
}

int main() {
    //check();
    int p, k;
    scanf("%d%d", &p, &k);
    printf("%d\n", solve(p, k));
    return 0;
}