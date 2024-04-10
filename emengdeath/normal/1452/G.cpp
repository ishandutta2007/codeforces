#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
#include <set>
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
int n;
int dis[N];
vector<int>d;
bool bz[N];
int sz[N], mxsz[N];
int ans[N];
set<pair<int, int> > f;
void add(pair<int, int> v) {
    f.insert(v).first;
    while (1) {
        auto u = f.lower_bound({v.first, -1});
        if (u != f.begin()) {
            auto w = u;
            w --;
            if (w->second <= u->second) {
                f.erase(w);
                continue;
            }
        }
        auto w = u;
        w ++;
        if (w != f.end() && w->second >= u->second) {
            f.erase(u);
            continue;
        }
        break;
    }
}
int get(int dis) {
    if (f.empty()) return 0;
    auto u = f.lower_bound({dis, -1});
    if (u == f.end()) return 0;
    return u->second;
}
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
void dfs(int x, int fa, int deep) {
    ans[x] = max(ans[x], get(deep));
    for (auto u:g[x])
        if (u != fa && !bz[u])
            dfs(u, x, deep + 1);
}
void dfs1(int x, int fa, int deep) {
    add({dis[x] - deep, dis[x]});
    for (auto u:g[x])
        if (u != fa && !bz[u])
            dfs1(u, x, deep + 1);
}
void divide(int x) {
    x = root(x);
    bz[x] = 1;
    f.clear();
    add({dis[x], dis[x]});
    for (auto u:g[x])
        if (!bz[u]) {
            dfs(u, x, 1);
            dfs1(u, x, 1);
        }
    f.clear();
    add({dis[x], dis[x]});
    reverse(g[x].begin(), g[x].end());
    for (auto u:g[x])
        if (!bz[u]) {
            dfs(u, x, 1);
            dfs1(u, x, 1);
        }
    ans[x] = max(ans[x], get(0));
    for (auto u:g[x])
        if (!bz[u])
            divide(u);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n;i ++)
    {
        int x, y;
        scanf("%d %d", &x , &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int m;
    scanf("%d", &m);
    vector<int> d;
    while (m --) {
        int x;
        scanf("%d", &x);
        if (!dis[x]) {
            dis[x] = 1;
            d.push_back(x);
        }
    }
    for (int i = 0; i < d.size(); i ++)
        for (auto u:g[d[i]])
            if (!dis[u])
                dis[u] = dis[d[i]] + 1, d.push_back(u);
    for (int i = 1; i <= n;i ++) dis[i] -= 2;
    divide(1);
    for (int i = 1; i <= n; i++) {
        if (dis[i] == -1) ans[i] = 0;
        else ans[i] ++;
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}