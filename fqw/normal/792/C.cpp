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

int main() {
    string s;
    cin >> s;
    int n = sz(s);
    VI a(n);
    repn(i, n) a[i] = int(s[i] - '0');

    static pair<int, PII> f[100010][3][2];
    fillchar(f, 50);
    const int INF = f[0][0][0].fi;

    f[n][0][0].fi = 0;
    int i0, ans = INF;
    irepn(i, n) {
        repn(j, 3) {
            f[i][j][0] = min(mp(f[i + 1][j][0].fi + 1, mp(j, 0)),
                             mp(f[i + 1][j][1].fi + 1, mp(j, 1)));
            f[i][(j + a[i]) % 3][1] = min(mp(f[i + 1][j][0].fi, mp(j, 0)),
                                          mp(f[i + 1][j][1].fi, mp(j, 1)));
        }
        if(a[i] != 0 && setmin(ans, f[i][0][1].fi + i)) {
            i0 = i;
        }
    }
    if(ans == INF) {
        if(find(all(a), 0) != a.end()) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        for(int i = i0, j = 0, k = 1; i < n; tie(j, k) = f[i][j][k].se, ++i) {
            if(k) {
                cout << a[i];
            }
        }
        cout << endl;
    }
    return 0;
}