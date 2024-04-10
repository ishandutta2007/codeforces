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

int f[88][88][88];
int a[88][88];
int n, num, m;

int main() {
    scanf("%d%d%d", &n, &num, &m);
    fillchar(a, 50);
    repn(i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        setmin(a[u][v], c);
    }

    fillchar(f, 50);
    int inf = f[0][0][0];
    rep(i, 0, n + 1) rep(j, 1, n) if(i != j) f[0][i][j] = 0;
    rep(c, 1, num) rep(i, 0, n + 1) rep(j, 1, n) if(i != j) {
        int s = min(i, j), t = max(i, j);
        rep(k, s + 1, t - 1) {
            setmin(f[c][i][j], f[c - 1][i][k] + a[j][k]);
            setmin(f[c][i][j], f[c - 1][j][k] + a[j][k]);
        }
    }
    int ans = 1 << 30;
    rep(i, 1, n) {
        setmin(ans, f[num - 1][0][i]);
        setmin(ans, f[num - 1][n + 1][i]);
    }
    if(ans >= inf) ans = -1;
    printf("%d\n", ans);
    return 0;
}