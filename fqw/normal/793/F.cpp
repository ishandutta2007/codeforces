// 19:26 - 19:31
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
const int B = 400;

int f[N][N / B + 3];
VI front[N];
int back[N], cur_front[N];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    fillchar(back, -1);
    repn(i, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        front[l].pb(r);
        back[r] = l;
    }
    rep(i, 1, n) sort(all(front[i]), greater<int>());

    fillchar(f, 0);
    fillchar(cur_front, 0);
    for(int r = B; r <= n; r += B) {
        const int id = r / B;
        rep(i, 1, n) {
            while(!front[i].empty() && front[i].back() <= r) {
                cur_front[i] = front[i].back();
                front[i].pop_back();
            }
        }
        VI stack;
        f[r][id] = r;
        stack.pb(r);
        irep(i, r - 1, 1) {
            f[i][id] = i;
            while(!stack.empty() && cur_front[i] >= stack.back()) {
                f[i][id] = f[stack.back()][id];
                stack.pop_back();
            }
            stack.pb(i);
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int cur = max(l, f[l][r / B]);
        rep(i, max(l, r / B * B), r) {
            if(back[i] >= l && back[i] <= cur) {
                cur = i;
            }
        }
        printf("%d\n", cur);
    }

    return 0;
}