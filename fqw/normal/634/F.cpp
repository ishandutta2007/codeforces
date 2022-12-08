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

struct Node {
    int j, num;
    Node *l, *r;
};

int main() {
    int n, m, num, want;
    scanf("%d%d%d%d", &n, &m, &num, &want);
    vector<VI> dots(n);
    while(num--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        dots[x].pb(y);
    }

    const auto remove = [&](Node* x) {
        LL ans = 0;

        Node *l = x, *r = x;
        int tot = x->num;
        while(tot < want && l->l) {
            l = l->l;
            tot += l->num;
        }
        while(1) {
            while(tot < want && r->r) {
                r = r->r;
                tot += r->num;
            }
            if(tot == want) {
                int lspace = (l->l ? l->j - l->l->j : l->j + 1);
                int rspace = (r->r ? r->r->j - r->j : m - r->j);
                ans += lspace * rspace;
            }
            if(l == x) break;
            tot -= l->num, l = l->r;
        }
        if(--(x->num) == 0) {
            if(x->l) x->l->r = x->r;
            if(x->r) x->r->l = x->l;
        }
        return ans;
    };
    LL ans = 0;
    repn(x1, n) {
        vector<Node> nodes(m);
        repn(j, m) {
            nodes[j].j = j;
            nodes[j].num = 0;
        }
        replr(i, x1, n) {
            for(int j : dots[i]) ++nodes[j].num;
        }
        Node* last = nullptr;
        repn(j, m) if(nodes[j].num) {
            nodes[j].l = last;
            if(last) last->r = &nodes[j];
            last = &nodes[j];
        }
        if(last) last->r = nullptr;

        VL diff(n);
        reprl(i, x1, n) {
            for(int j : dots[i]) {
                diff[i] += remove(&nodes[j]);
            }
        }
        LL cur = 0;
        replr(i, x1, n) {
            cur += diff[i];
            ans += cur;
        }
    }
    printf("%lld\n", ans);

    return 0;
}