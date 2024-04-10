// 12:51 - 13:26
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

VI es[N];
int vis[N], tag[N], tr[N];

void dfs(int x) {
    if(vis[x] >= 0) return;
    static int cur = 0;
    vis[x] = cur++;
    for(int y : es[x]) {
        dfs(y);
    }
}

void add(int x) {
    for(; x < N; x += x & -x) tr[x]++;
}

int get(int x) {
    int r = 0;
    for(; x > 0; x -= x & -x) r += tr[x];
    return r;
}

int main() {
    int n, m;
    scanf("%d%*d%d", &n, &m);
    repn(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        es[a].pb(b), es[b].pb(a);
    }
    fillchar(vis, -1);
    fillchar(tag, 0);
    fillchar(tr, 0);
    rep(i, 1, n) if(vis[i] < 0) {
        dfs(i);
        tag[i] = 1;
        add(i);
    }

    int q;
    scanf("%d", &q);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        const auto check = [&](int i) {
            if(tag[i]) return 0;
            for(int j : es[i]) {
                if(j >= l && j <= r && vis[j] < vis[i]) return 0;
            }
            return 1;
        };
        int ans = get(r) - get(l - 1);
        rep(i, l, min(l + 4, r)) ans += check(i);
        rep(i, max(l + 5, r - 4), r) ans += check(i);
        printf("%d\n", ans);
    }

    return 0;
}