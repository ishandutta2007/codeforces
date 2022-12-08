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
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

const int N = 100000;

VI es[N];
int belong[N];
VI fars[N];
vector<double> ss[N];
int n, m, q;

void init() {
    scanf("%d%d%d", &n, &m, &q);
    repn(i, m) {
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        es[a].pb(b), es[b].pb(a);
    }
    fillchar(belong, 0xff);
    VI f(n, -1), vis(n, 0), dis(n), xs;
    const auto bfs = [&](int start) {
        static int cnt = 0;
        ++cnt, xs.clear();
        xs.pb(start), vis[start] = cnt, dis[start] = 0;
        for(int i = 0; i < sz(xs); ++i) {
            int x = xs[i];
            for(int y : es[x]) {
                if(vis[y] != cnt) {
                    vis[y] = cnt, dis[y] = dis[x] + 1;
                    xs.pb(y);
                }
            }
        }
    };
    repn(i, n) if(belong[i] < 0) {
        bfs(i);
        for(int x : xs) belong[x] = i;
        bfs(xs.back());
        for(int x : xs) setmax(f[x], dis[x]);
        bfs(xs.back());
        for(int x : xs) setmax(f[x], dis[x]);
        for(int x : xs) fars[i].pb(f[x]);
        sort(all(fars[i]));
        ss[i].resize(sz(fars[i]) + 1);
        irepn(k, sz(fars[i])) ss[i][k] = ss[i][k + 1] + fars[i][k];
    }
}

double query(int a, int b) {
    assert(sz(fars[a]) > 0 && sz(fars[b]) > 0);
    if(sz(fars[a]) < sz(fars[b])) swap(a, b);
    double ans = 0;
    int t = max(fars[a].back(), fars[b].back());
    for(int val : fars[b]) {
        int i = int(lower_bound(all(fars[a]), t - val - 1) - fars[a].begin());
        ans += double(sz(fars[a]) - i) * double(val + 1) + ss[a][i];
        ans += double(i) * double(t);
    }
    ans /= sz(fars[a]);
    ans /= sz(fars[b]);
    return ans;
}

void solve() {
    map<PII, double> ans;
    while(q--) {
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        a = belong[a], b = belong[b];
        if(a == b) {
            printf("-1\n");
            continue;
        }
        if(a > b) swap(a, b);
        if(ans.count(mp(a, b)) == 0) {
            ans[mp(a, b)] = query(a, b);
        }
        printf("%.9lf\n", ans[mp(a, b)]);
    }
}

int main() {
    init();
    solve();
    return 0;
}