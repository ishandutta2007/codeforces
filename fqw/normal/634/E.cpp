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
    int n, needed;
    scanf("%d%d", &n, &needed);
    vector<VI> es(n);
    VI val(n), size(n);
    repn(i, n) scanf("%d", &val[i]);
    repn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        es[a].pb(b), es[b].pb(a);
    }
    const function<void(int, int)> build = [&](int x, int fa) {
        size[x] = 1;
        for(int y : es[x]) {
            if(y == fa) continue;
            build(y, x);
            size[x] += size[y];
        }
    };
    build(0, -1);

    int limit = 0, le = 0, ri = 1000000;
    bool found = false;
    VI up(n);
    const function<void(int, int)> dfs_up = [&](int x, int fa) {
        int sum = 0, best = 0;
        for(int y : es[x]) {
            if(y == fa) continue;
            dfs_up(y, x);
            if(up[y] == size[y]) {
                sum += up[y];
            } else {
                setmax(best, up[y]);
            }
        }
        up[x] = (val[x] >= limit ? 1 + sum + best : 0);
    };
    const function<void(int, int, int)> dfs_down = [&](int x, int fa,
                                                       int down) {
        VI ys;
        for(int y : es[x]) {
            if(y != fa) ys.pb(y);
        }
        const int m = sz(ys);
        VI ls(m + 1), lb(m + 1), rs(m + 1), rb(m + 1);
        repn(i, m) {
            ls[i + 1] = ls[i], lb[i + 1] = lb[i];
            if(up[ys[i]] == size[ys[i]]) {
                ls[i + 1] += up[ys[i]];
            } else {
                setmax(lb[i + 1], up[ys[i]]);
            }
        }
        irepn(i, m) {
            rs[i] = rs[i + 1], rb[i] = rb[i + 1];
            if(up[ys[i]] == size[ys[i]]) {
                rs[i] += up[ys[i]];
            } else {
                setmax(rb[i], up[ys[i]]);
            }
        }
        repn(i, m) {
            int s = ls[i] + rs[i + 1], b = max(lb[i], rb[i + 1]);
            if(down == n - size[x]) {
                s += down;
            } else {
                setmax(b, down);
            }
            dfs_down(ys[i], x, val[x] >= limit ? 1 + s + b : 0);
        }

        if(val[x] >= limit) {
            int s = ls[m], b = lb[m];
            if(down == n - size[x]) {
                s += down;
            } else {
                setmax(b, down);
            }
            if(1 + s + b >= needed) {
                found = true;
            }
        }
    };

    while(le < ri) {
        limit = (le + ri + 1) / 2;
        found = false;
        dfs_up(0, -1);
        dfs_down(0, -1, 0);
        if(found) {
            le = limit;
        } else {
            ri = limit - 1;
        }
    }
    printf("%d\n", le);

    return 0;
}