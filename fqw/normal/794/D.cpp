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

pair<VI, VI> bfs(const VVI& es, int start) {
    const int n = sz(es);
    VI dis(n, -1), pre(n, -1);
    queue<int> que;
    dis[start] = 0;
    que.push(start);
    while(!que.empty()) {
        int x = que.front();
        que.pop();
        for(int y : es[x]) {
            if(dis[y] < 0) {
                dis[y] = dis[x] + 1;
                pre[y] = x;
                que.push(y);
            }
        }
    }
    return {dis, pre};
}

bool check(const VVI& es, VI ans) {
    const int n = sz(es);
    VI cnt(n * 2 + 5, 0);
    for(int c : ans) cnt[c]++;
    repn(x, n) {
        if(sz(es[x]) != cnt[ans[x] - 1] + cnt[ans[x]] + cnt[ans[x] + 1] - 1) {
            return false;
        }
        for(int y : es[x]) {
            if(abs(ans[x] - ans[y]) > 1) {
                return false;
            }
        }
    }
    return true;
}

VI solve(VVI es) {
    const int n = sz(es);
    int a = -1, b = -1;
    repn(x, n) {
        sort(all(es[x]));
        es[x].erase(unique(all(es[x])), es[x].end());
        if(sz(es[x]) < n - 1) {
            a = x;
            b = 0;
            for(int y : es[x]) {
                if(y == b) {
                    ++b;
                } else {
                    break;
                }
            }
        }
    }
    if(a < 0) {
        return VI(n, 1);
    }
    const auto has = [&](int x, int y) {
        auto it = lower_bound(all(es[x]), y);
        return it != es[x].end() && *it == y;
    };

    int c = -1;
    {
        VI dis, pre;
        tie(dis, pre) = bfs(es, a);
        VI path;
        for(int x = b; x >= 0; x = pre[x]) path.pb(x);
        assert(sz(path) >= 3);
        a = path[0], b = path[1], c = path[2];
    }
    VI da = bfs(es, a).fi, db = bfs(es, b).fi, dc = bfs(es, c).fi;
    VI ans(n, -1);
    ans[a] = n - 1, ans[b] = n, ans[c] = n + 1;
    for(int x : es[b]) {
        if(x != a && x != c) {
            bool ba = has(a, x), bc = has(c, x);
            if(ba && bc) {
                ans[x] = n;
            } else if(ba) {
                ans[x] = n - 1;
            } else {
                ans[x] = n + 1;
            }
        }
    }
    repn(x, n) if(ans[x] < 0) {
        if(da[x] < dc[x]) {
            ans[x] = n - db[x];
        } else {
            ans[x] = n + db[x];
        }
    }
    if(check(es, ans)) {
        return ans;
    } else {
        return VI();
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    VVI es(n);
    repn(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        es[a].pb(b), es[b].pb(a);
    }
    VI xs = solve(es);
    if(xs.empty()) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for(int x : xs) printf("%d ", x);
        printf("\n");
    }
    return 0;
}