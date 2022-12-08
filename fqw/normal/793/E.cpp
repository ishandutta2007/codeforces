#include <algorithm>
#include <bitset>
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

int desired_gap = 0;

bool check(int sa, int sb, int sc, VI ss) {
    bitset<2501> b;
    if(sc < sz(b)) b[sc] = 1;
    for(int s : ss) b |= b << s;
    rep(i, 0, desired_gap) if(b[i]) {
        int extra = desired_gap - i;
        if(sa - 1 + sb - 1 >= extra) return true;
    }
    return false;
}

bool solve(int sa, int sc, int sb, int sd, VI ss) {
    return check(sa, sb, sc, ss) && check(sc, sd, sb, ss);
}

int main() {
    int n;
    scanf("%d", &n);
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    --a, --b, --c, --d;
    vector<VI> children(n);
    rep(i, 1, n - 1) {
        int j;
        scanf("%d", &j);
        --j;
        children[j].pb(i);
    }

    int sa, sb, sc, sd;
    VI ss;
    const function<PII(int)> dfs = [&](int x) {
        if(sz(children[x]) == 0) {
            return mp(1, x == a || x == b || x == c || x == d ? x : -1);
        }
        int s = 0, p = -1;
        for(int y : children[x]) {
            PII r = dfs(y);
            s += r.fi, setmax(p, r.se);
        }
        return mp(s, p);
    };
    int sum = 0;
    for(int x : children[0]) {
        PII r = dfs(x);
        sum += r.fi;
        if(r.se == a) {
            sa = r.fi;
        } else if(r.se == b) {
            sb = r.fi;
        } else if(r.se == c) {
            sc = r.fi;
        } else if(r.se == d) {
            sd = r.fi;
        } else {
            ss.pb(r.fi);
        }
    }
    bool ans;
    if(sum % 2 == 0) {
        desired_gap = sum / 2 - 1;
        ans = solve(sa, sc, sb, sd, ss) || solve(sa, sd, sb, sc, ss);
    } else {
        ans = false;
    }
    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}