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

const int N = 100010;
char a[N], b[N];
int x[N], y[N];
int n, m;

int main() {
    scanf("%s%s", a + 1, b + 1);
    n = (int)strlen(a + 1);
    m = (int)strlen(b + 1);

    x[0] = 0;
    rep(i, 1, m) {
        x[i] = min(n + 1, x[i - 1] + 1);
        while(x[i] <= n && a[x[i]] != b[i]) {
            ++x[i];
        }
    }
    y[m + 1] = n + 1;
    irep(i, m, 1) {
        y[i] = max(0, y[i + 1] - 1);
        while(y[i] >= 1 && a[y[i]] != b[i]) {
            --y[i];
        }
    }

    pair<int, PII> ans = {-1, {0, 0}};
    int j = 1;
    while(y[j] < 1) ++j;
    rep(i, 0, n) {
        if(x[i] > n) break;
        while(i>=j || x[i] >= y[j]) ++j;
        setmax(ans, mp(i + m - j + 1, mp(i, j)));
    }
    if(ans.fi == 0) {
        printf("-\n");
    } else {
        rep(i, 1, ans.se.fi) printf("%c", b[i]);
        rep(i, ans.se.se, m) printf("%c", b[i]);
        printf("\n");
    }

    return 0;
}