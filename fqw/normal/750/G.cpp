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

LL solve(int nx, int ny, LL s) {
    if(s < 0) return 0;
    LL ans = 0;
    rep(pop, 2, nx + ny + 2) {
        LL desire = s + 1 + pop;
        if(desire % 2 != 0) continue;
        desire /= 2;
        {
            LL minx, miny, maxx, maxy;
            if(nx == 0) {
                minx = maxx = 1;
            } else {
                minx = 1ll << nx, maxx = (3ll << (nx - 1)) - 1;
            }
            if(ny == 0) {
                miny = maxy = 1;
            } else {
                miny = 3ll << (ny - 1), maxy = (1ll << (ny + 1)) - 1;
            }
            if(minx + miny > desire || maxx + maxy < desire) continue;
        }

        static LL f[55][120][2];
        fillchar(f, 0);
        f[0][0][0] = 1;
        rep(i, 0, max(nx, ny)) {
            int cur = int(desire % 2);
            desire /= 2;
            int x1 = 0, x2 = 1, y1 = 0, y2 = 1;
            if(i == nx - 1 || i > nx) {
                x1 = x2 = 0;
            } else if(i == nx) {
                x1 = x2 = 1;
            }
            if(i == ny - 1 || i == ny) {
                y1 = y2 = 1;
            } else if(i > ny) {
                y1 = y2 = 0;
            }
            rep(c, 0, pop) repn(carry, 2) if(f[i][c][carry]) {
                rep(x, x1, x2) {
                    int y = cur ^ x ^ carry;
                    if(y >= y1 && y <= y2 && c + x + y <= pop) {
                        f[i + 1][c + x + y][(x + y + carry) >> 1] +=
                            f[i][c][carry];
                    }
                }
            }
        }
        if(desire < 2) {
            ans += f[max(nx, ny) + 1][pop][desire];
        }
    }
    return ans;
}

int main() {
    LL s;
    cin >> s;
    LL ans = 0;
    rep(nx, 0, 50) rep(ny, 0, 50) {
        LL coeff = (1ll << (nx + 1)) + (1ll << (ny + 1)) - 3;
        LL p = s / coeff;
        if(p >= 1) {
            ans += solve(nx, ny, s - coeff * (p - 1));
        }
    }
    cout << ans << endl;
    return 0;
}