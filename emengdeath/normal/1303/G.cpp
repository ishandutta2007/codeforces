#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int N = 2e5;
int n;
vector<int>g[N];
int v[N];
const ll is_query = 1ll << 62;
struct line{
    ll k, b;
    mutable function<const line *()> succ;
    bool operator<(const line & a) const {
        if (a.b != is_query)  return k < a.k;
        auto y = succ();
        if (!y) return 0;//querylower_boundthisquery
        return a.k * k + b < a.k * y->k + y->b;
    }
};
struct HullDynamic:public multiset<line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end())
                return 0;
            return z->k >= y->k && z->b >= y->b;
        }
        auto x = prev(y);
        if (z == end()) {
            return x->k == y->k && x->b == y->b;
        }
        return (x->b - z->b) * (y->k - x->k) <= (x->b - y->b) * (z ->k - x->k);
    }
    void insert_line(ll k, ll b) {
        auto y = insert({k, b});
        y -> succ = [=]() {return next(y) == end()? 0: &*next(y);};
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto y = *lower_bound((line){x, is_query});
        return y.k * x + y.b;
    }
}H;
vector<int>d, d2;
bool bz[N];
int sz[N], mxsz[N];
int len[N];
ll ans = 0;
ll w[N], all[N];
int root(int x) {
    function<void(int, int)>dfs = [&](int x, int fa){
        sz[x] = 1;
        mxsz[x] = 0;
        d.push_back(x);
        for (auto u:g[x])
            if (u != fa && !bz[u])
                dfs(u, x), sz[x] += sz[u], mxsz[x] = max(mxsz[x], sz[u]);
    };
    d.clear();
    dfs(x, 0);
    for (auto u:d)
        if (max(mxsz[u], (int)d.size() - sz[u]) < max(mxsz[x], (int)d.size() - sz[x])) x = u;
    return x;
}
void divide(int x) {
    x = root(x);
    function<void(int, int)> dfs = [&] (int x, int fa) {
        d2.push_back(x);
        for (auto u:g[x])
            if (u != fa && !bz[u]) {
                len[u] = len[x] + 1;
                w[u] = w[x] + (all[u] = all[x] + v[u]);
                dfs(u, x);
            }
    };
    function<void(int, int)> dfs1 = [&] (int x, int fa) {
        for (auto u:g[x])
            if (u != fa && !bz[u]) {
                len[u] = len[x] + 1;
                w[u] = w[x] + 1ll * len[u] * v[u];
                all[u] = all[x] + v[u];
                dfs1(u, x);
            }
    };
    function<void(int)> work = [&] (int x) {
        H.clear();
        for (auto u:g[x])
            if (!bz[u]) {
                d2.clear();
                len[u] = 2, all[u] = v[u] + v[x];
                w[u] = all[u] + v[x];
                dfs(u, x);
                for (auto v:d2) {
                    if (!H.empty())
                        ans = max(ans, H.eval(len[v]) + w[v]);
                    ans = max(ans, w[v]);
                }
                len[u] = 1, w[u] = all[u] = v[u];
                dfs1(u, x);
                ll tmp = v[x];
                for (auto v:d2) {
                    H.insert_line(all[v], w[v]);
                    ans = max(ans, w[v] + all[v] + tmp);
                }
            }
    };
    work(x);
    reverse(g[x].begin(), g[x].end());
    work(x);
    bz[x] = 1;
    for (auto u:g[x])
        if (!bz[u])
            divide(u);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i= 1; i <= n; i ++)
        scanf("%d", &v[i]);
    divide(1);
    printf("%lld\n", ans);
    return 0;
}