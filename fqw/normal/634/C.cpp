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

struct Tree {
    const int n;
    VL tr;

    Tree(int _n) : n(_n), tr(n + 1) {}

    void add(int i, LL val) {
        ++i;
        for(; i <= n; i += i & -i) tr[i] += val;
    }

    LL sum(int i) {
        LL r = 0;
        for(; i >= 1; i -= i & -i) r += tr[i];
        return r;
    }
};

struct RevTree {
    const int n;
    Tree tr;

    RevTree(int _n) : n(_n), tr(n) {}

    void add(int i, LL val) { tr.add(n - i - 1, val); }

    LL sum(int i) { return tr.sum(n - i); }
};

int main() {
    int n, k, a, b, q;
    scanf("%d%d%d%d%d", &n, &k, &b, &a, &q);
    Tree t1(n);
    RevTree t2(n);
    VL val(n);

    while(q--) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int i, v;
            scanf("%d%d", &i, &v);
            --i;
            LL old = val[i];
            val[i] += v;
            t1.add(i, max(0ll, min(LL(a), val[i]) - old));
            t2.add(i, max(0ll, min(LL(b), val[i]) - old));
        } else {
            int i;
            scanf("%d", &i);
            --i;
            int j = i + k;
            LL ans = t1.sum(i) + t2.sum(j);
            printf("%lld\n", ans);
        }
    }

    return 0;
}