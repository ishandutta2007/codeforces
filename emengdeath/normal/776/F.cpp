#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 400001;
vector<pair<int, int> > g[N];
pair<int, int> nex[N];
int n, m, tot;
pair<pair<int, int>, int> b[N];
int bz[N];
int id[N], rk[N];
int ans[N];
vector<int> e[N];
int op(int x) {
    return x > n + m ? x - n - m : x + n + m;
}


vector<int>d;
bool have_do[N];
int sz[N], mxsz[N];
void dfs(int x, int fa){
    sz[x] = 1;
    mxsz[x] = 0;
    d.push_back(x);
    for (auto u:e[x])
        if (u != fa && !have_do[u])
            dfs(u, x), sz[x] += sz[u], mxsz[x] = max(mxsz[x], sz[u]);
};
int root(int x) {
    d.clear();
    dfs(x, 0);
    for (auto u:d)
        if (max(mxsz[u], (int)d.size() - sz[u]) < max(mxsz[x], (int)d.size() - sz[x])) x = u;
    return x;
}
void divide(int x, int c) {
    x = root(x);
    have_do[x] = 1;
    ans[x] = c;
    for (auto u:e[x])
        if (!have_do[u])
            divide(u, c + 1);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= m;i ++){
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back({y, i});
        g[y].push_back({x, i + m + n});
    }
    for (int i = 1; i <= n; i ++) {
        g[i].push_back({i % n + 1, i + m + n + m});
        g[i].push_back({(i + n - 2) % n + 1, (i - 2 + n) % n + 1 + m});
    }
    for (int i = 1; i <= n; i ++) {
        sort(g[i].begin(), g[i].end());
        for (int j = 0; j < g[i].size(); j ++) {
            auto x = g[i][j], y = g[i][(j + 1) % g[i].size()];
            if (x.first < i && y.first > i) continue;
            nex[op(x.second)] = {y.second, x.first};
        }
    }
    for (int i = 1; i <= n + m + m; i ++)
        if (!bz[i]) {
            int x = i;
            vector<int> d;
            ++tot;
            while (!bz[x]) {
                bz[x] = tot;
                d.push_back(nex[x].second);
                x = nex[x].first;
            }
            sort(d.rbegin(), d.rend());
            b[tot] = {{d[0], d[1]}, d[2]};
            id[tot] = tot;
        }
    sort(id + 1, id + tot + 1, [](int x, int y) {
        return b[x] < b[y];
    });
    for (int i = 1;  i <= tot ; i++) rk[id[i]] = i;
    for (int i = 1; i <= m; i ++) {
        e[rk[bz[i]]].push_back(rk[bz[i + n + m]]);
        e[rk[bz[i + n + m]]].push_back(rk[bz[i]]);
    }
    divide(1, 1);
    for (int i = 1; i <= tot; i ++)
        printf("%d%c", ans[i], " \n"[i == tot]);
    return 0;
}