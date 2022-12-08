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
typedef vector<PLL> VPL; typedef vector<VB> VVB;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

VPI solve(int n, bool half) {
    VVB used(n, VB(n, false));
    VI rest(n, n - 1);
    if(half) {
        repn(i, n) replr(j, i + 1, n) {
            if(i / (n / 2) == j / (n / 2)) used[i][j] = true;
        }
        fill(all(rest), n / 2);
    }
    int cnt = 0;
    repn(i, n) replr(j, i + 1, n) if(!used[i][j]) cnt++;
    VPI ans;
    VI a(n), b(n);
    iota(all(a), 0);
    iota(all(b), 0);
    const function<bool(int)> dfs = [&](int cur) {
        if(cur >= cnt) return a == b;
        repn(i, n) replr(j, i + 1, n) if(!used[i][j]) {
            swap(a[i], a[j]), --rest[i], --rest[j], used[i][j] = true;
            ans.pb(mp(i, j));
            if((rest[i] > 0 || a[i] == i) && (rest[j] > 0 || a[j] == j)) {
                if(dfs(cur + 1)) return true;
            }
            ans.pop_back();
            swap(a[i], a[j]), ++rest[i], ++rest[j], used[i][j] = false;
        }
        return false;
    };
    dfs(0);
    return ans;
}

int main() {
    VPI ans4 = solve(4, false);
    VPI ans5 = solve(5, false);
    VPI bip8 = solve(8, true);
    // cout << ans4 << endl;
    // cout << ans5 << endl;
    // cout << bip8 << endl;
    int n;
    scanf("%d", &n);
    if(n % 4 == 2 || n % 4 == 3) {
        printf("NO\n");
        return 0;
    }
    VPI ans;
    for(int i = 0; i < n - 1; i += 4) {
        VI xs;
        repn(j, 4) xs.pb(i + j);
        if(n % 4 == 0) {
            for(const auto& p : ans4) {
                ans.pb({xs[p.fi], xs[p.se]});
            }
        } else {
            xs.pb(n - 1);
            for(const auto& p : ans5) {
                ans.pb({xs[p.fi], xs[p.se]});
            }
        }
    }
    for(int i = 0; i < n; i += 4) {
        for(int j = i + 4; j < n - 1; j += 4) {
            VI xs;
            repn(k, 4) xs.pb(i + k);
            repn(k, 4) xs.pb(j + k);
            for(const auto& p : bip8) {
                ans.pb({xs[p.fi], xs[p.se]});
            }
        }
    }
    printf("YES\n");
    for(const auto& x : ans) {
        printf("%d %d\n", x.fi + 1, x.se + 1);
    }
    return 0;
}