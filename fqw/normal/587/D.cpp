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

namespace two_sat {

const int N = 6000000;

VI es[N];
int num, n;
VI ans;

void clear(int _n) {
    repn(i, num) es[i].clear();
    n = _n, num = n * 2;
}

void add(int i, int j) {
    es[i].pb(j ^ 1);
    if(i != j) es[j].pb(i ^ 1);
}

void add_conflicts(VI is) {
    VI us, vs;
    repn(k, sz(is)) us.pb(num), num += 2;
    repn(k, sz(is)) vs.pb(num), num += 2;
    repn(k, sz(is)) {
        add(us[k], is[k]);
        add(vs[k], is[k]);
        if(k > 0) {
            add(us[k], us[k - 1] ^ 1);
            add(is[k], us[k - 1] ^ 1);
        }
        if(k + 1 < sz(is)) {
            add(vs[k], vs[k + 1] ^ 1);
            add(is[k], vs[k + 1] ^ 1);
        }
    }
}

bool solve() {
    VI belong(num, -1), low(num), dfn(num), stack;
    int counter = 0, blocks = 0;
    const function<void(int)> dfs = [&](int x) {
        low[x] = dfn[x] = counter++;
        stack.pb(x);
        belong[x] = -2;
        for(int y : es[x]) {
            if(belong[y] == -1) {
                dfs(y);
                setmin(low[x], low[y]);
            } else if(belong[y] == -2) {
                setmin(low[x], dfn[y]);
            }
        }
        if(low[x] == dfn[x]) {
            while(1) {
                int cur = stack.back();
                stack.pop_back();
                belong[cur] = blocks;
                if(cur == x) break;
            }
            ++blocks;
        }
    };
    repn(i, num) if(belong[i] == -1) dfs(i);
    ans.resize(n);
    repn(i, num / 2) {
        if(belong[i * 2] == belong[i * 2 + 1]) return false;
    }
    repn(i, n) { ans[i] = (belong[i * 2] > belong[i * 2 + 1] ? 1 : 0); }
    return true;
}
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    struct Edge {
        int u, v, c, t, i;
    };
    vector<Edge> es(m);
    vector<unordered_map<int, VI>> cs(n);
    repn(i, m) {
        scanf("%d%d%d%d", &es[i].u, &es[i].v, &es[i].c, &es[i].t);
        --es[i].u, --es[i].v;
        es[i].i = i;
        cs[es[i].u][es[i].c].pb(i);
        cs[es[i].v][es[i].c].pb(i);
    }
    const auto check = [&](int t) {
        two_sat::clear(m);
        // printf("check %d\n", t);
        repn(i, m) if(es[i].t > t) {
            // printf("TOO LARGE: ");
            two_sat::add(i * 2 + 1, i * 2 + 1);
        }
        repn(x, n) {
            bool found = false;
            VI is;
            for(const auto& kv : cs[x]) {
                if(sz(kv.se) > 2) return false;
                if(sz(kv.se) == 2) {
                    if(found) return false;
                    found = true;
                    int i = kv.se[0], j = kv.se[1];
                    two_sat::add(i * 2 + 1, j * 2 + 1);
                    two_sat::add(j * 2, i * 2);
                } else {
                    is.pb(kv.se[0] * 2 + 1);
                }
            }
            if(found) {
                for(int i : is) {
                    two_sat::add(i, i);
                }
            } else {
                two_sat::add_conflicts(is);
            }
        }
        return two_sat::solve();
    };
    int le = 0, ri = 1 << 30;
    while(le < ri) {
        int mid = (le + ri) / 2;
        if(check(mid)) {
            ri = mid;
        } else {
            le = mid + 1;
        }
    }
    if(check(le)) {
        printf("Yes\n");
        VI is;
        repn(i, m) if(two_sat::ans[i]) is.pb(i);
        printf("%d %d\n", le, sz(is));
        for(int i : is) printf("%d ", i + 1);
        printf("\n");
    } else {
        printf("No\n");
    }
    return 0;
}