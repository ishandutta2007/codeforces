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

int main() {
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    VI cores(k);
    repn(i, k) scanf("%d", &cores[i]), --cores[i];
    sort(all(cores));
    cores.erase(unique(all(cores)), cores.end());
    vector<VI> es(n);
    VPI all_es;
    repn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        all_es.pb(mp(a, b));
        es[a].pb(b), es[b].pb(a);
    }
    VI vis(n, -1);
    queue<int> que;
    for(int x : cores) {
        vis[x] = x;
        que.push(x);
    }
    while(!que.empty()) {
        int x = que.front();
        que.pop();
        for(int y : es[x]) {
            if(vis[y] < 0) {
                vis[y] = vis[x];
                que.push(y);
            }
        }
    }

    VI ans;
    repn(i, n - 1) {
        const auto& e = all_es[i];
        if(vis[e.fi] != vis[e.se]) {
            ans.pb(i);
        }
    }
    printf("%d\n", sz(ans));
    for(int x : ans) printf("%d ", x + 1);
    printf("\n");

    return 0;
}