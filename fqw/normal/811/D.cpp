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

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    static char board[110][110];
    repn(i, n) scanf("%s", board[i]);

    string ans;
    static PII pre[110][110];
    static char dir[110][110];
    fillchar(dir, '?');
    queue<PII> que;
    dir[0][0] = '*', que.push({0, 0});
    while(!que.empty()) {
        PII p = que.front();
        que.pop();
        static const int dx[4] = {0, 1, 0, -1};
        static const int dy[4] = {1, 0, -1, 0};
        static const char dc[] = "RDLU";
        repn(i, 4) {
            int x = p.fi + dx[i], y = p.se + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '*')
                continue;
            if(dir[x][y] != '?') continue;
            dir[x][y] = dc[i], pre[x][y] = p;
            que.push({x, y});
        }
    }
    {
        int x = 0, y = 0;
        repn(i, n) repn(j, m) if(board[i][j] == 'F') x = i, y = j;
        while(x != 0 || y != 0) {
            ans += dir[x][y];
            tie(x, y) = pre[x][y];
        }
        reverse(all(ans));
    }

    int x = 0, y = 0;
    repn(i, sz(ans)) {
        printf("%c\n", ans[i]), fflush(stdout);
        int nx, ny;
        scanf("%d%d", &nx, &ny), --nx, --ny;
        if(nx == x && ny == y) {
            if(ans[i] == 'L' || ans[i] == 'R') {
                repn(j, sz(ans)) {
                    if(ans[j] == 'L')
                        ans[j] = 'R';
                    else if(ans[j] == 'R')
                        ans[j] = 'L';
                }
            } else {
                repn(j, sz(ans)) {
                    if(ans[j] == 'U')
                        ans[j] = 'D';
                    else if(ans[j] == 'D')
                        ans[j] = 'U';
                }
            }
            printf("%c\n", ans[i]), fflush(stdout);
            scanf("%d%d", &nx, &ny), --nx, --ny;
            assert(nx != x || ny != y);
        }
        x = nx, y = ny;
    }
    return 0;
}