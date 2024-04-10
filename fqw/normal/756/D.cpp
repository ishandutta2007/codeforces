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
#define nxt first
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

const LL MOD = LL(1e9) + 7;

LL f[5050][5050];
int nxt[5050][26];
char s[5050];
int n;

int main() {
    scanf("%d%s", &n, s + 1);
    repn(c, 26) nxt[n + 1][c] = n + 1;
    irep(i, n, 1) {
        repn(c, 26) nxt[i][c] = nxt[i + 1][c];
        nxt[i][int(s[i] - 'a')] = i;
    }

    fillchar(f, 0);
    repn(c, 26) if(nxt[1][c] <= n) { f[1][nxt[1][c]] = 1; }
    rep(i, 1, n - 1) rep(j, 1, n) {
        f[i][j] %= MOD;
        if(f[i][j] == 0) continue;
        repn(c, 26) if(nxt[j][c] <= n) { f[i + 1][nxt[j][c]] += f[i][j]; }
    }

    LL ans = 0;
    rep(j, 1, n)(ans += f[n][j]) %= MOD;
    printf("%d\n", int(ans));

    return 0;
}