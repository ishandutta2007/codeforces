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

int f[77][77][77][3];
char str[77];
int n;

int main() {
    scanf("%d%s", &n, str + 1);
    int where[3][77];
    int c[3] = {0, 0, 0}, c2[77][3];
    {
        fillchar(where, 0);
        fillchar(c2, 0);
        rep(i, 1, n) {
            repn(k, 3) c2[i][k] = c2[i - 1][k];
            int cur = 2;
            if(str[i] == 'V') cur = 0;
            if(str[i] == 'K') cur = 1;
            ++c2[i][cur];
            ++c[cur];
            where[cur][c[cur]] = i;
        }
    }

    fillchar(f, 55);
    const int maxval = f[0][0][0][0];
    repn(i, 3) f[0][0][0][i] = 0;
    rep(i, 1, n) repn(nv, 77) repn(nk, 77) repn(last, 3) {
        const int val = f[i - 1][nv][nk][last];
        if(val == maxval) continue;
        const int na = i - 1 - nv - nk;
        repn(cur, 3) {
            if(last == 0 && cur == 1) continue;
            int nv2 = nv, nk2 = nk, na2 = na, w;
            if(cur == 0) ++nv2, w = where[0][nv2];
            if(cur == 1) ++nk2, w = where[1][nk2];
            if(cur == 2) ++na2, w = where[2][na2];
            if(nv2 > c[0] || nk2 > c[1] || na2 > c[2]) continue;
            int cv = c2[w][0], ck = c2[w][1], ca = c2[w][2];
            int tmp = max(0, nv2 - cv) + max(0, nk2 - ck) + max(0, na2 - ca);
            setmin(f[i][nv2][nk2][cur], val + tmp);
        }
    }
    int ans = maxval;
    repn(i, 3) setmin(ans, f[n][c[0]][c[1]][i]);
    printf("%d\n", ans);

    return 0;
}