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

int k;

struct Value {
    LL f[5];
    LL count;

    Value() {
        fillchar(f, 0);
        count = 0;
    }

    void merge(const Value& b) {
        count += b.count;
        repn(i, k) f[i] += b.f[i];
    }
    void advance() {
        LL tmp = f[0];
        repn(i, k - 1) f[i] = f[i + 1] + 1;
        f[k - 1] = tmp + count + 1;
        count++;
    }
};

int main() {
    int n;
    scanf("%d%d", &n, &k);
    vector<VI> es(n);
    repn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        es[a].pb(b), es[b].pb(a);
    }

    vector<Value> f(n);
    const function<void(int, int)> dfs = [&](int x, int fa) {
        for(int y : es[x])
            if(y != fa) {
                dfs(y, x);
                f[x].merge(f[y]);
            }
        f[x].advance();
    };
    dfs(0, -1);
    LL ans = 0;
    const function<void(int, int, Value)> dfs2 = [&](int x, int fa, Value up) {
        VI ys;
        for(int y : es[x]) {
            if(y != fa) ys.pb(y);
        }
        vector<Value> l(sz(ys) + 1), r(sz(ys) + 1);
        repn(i, sz(ys)) {
            l[i + 1] = l[i];
            l[i + 1].merge(f[ys[i]]);
        }
        irepn(i, sz(ys)) {
            r[i] = r[i + 1];
            r[i].merge(f[ys[i]]);
        }
        repn(i, sz(ys)) {
            Value cur = up;
            cur.merge(l[i]);
            cur.merge(r[i + 1]);
            cur.advance();
            dfs2(ys[i], x, cur);
        }

        ans += up.f[0] + r[0].f[0];
    };
    dfs2(0, -1, Value());
    ans /= 2;

    cout << ans << endl;

    return 0;
}