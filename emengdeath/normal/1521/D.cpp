#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n;
vector<int> g[N];
int fa[N], deep[N];
pair<int, pair<int, int> >f[N][3];
bool bz[N];
vector<pair<pair<int, int> , pair <int, int > > > ans;
void upd(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > b) {
    if (b < a) a = b;
}
void dfs(int x) {
    deep[x] ++;
    for (int i = 0;i < g[x].size(); i ++)
        if (g[x][i] == fa[x]) {
            swap(g[x][i], g[x][g[x].size() - 1]);
            g[x].pop_back();
            i --;
        }
    f[x][0] = {1, {0, 0}};
    f[x][1] = {n, {0, 0}};
    f[x][2] = {n, {0, 0}}; 
    for (auto u:g[x])
    {
        pair<int, pair<int, int> > c[3] = {{n, {0, 0}}, {n, {0, 0}}, {n, {0, 0}}};
        fa[u] = x;
        deep[u] = deep[x];
        dfs(u);
        upd(c[0], {f[x][0].first + f[u][2].first, {0, 0}});
        upd(c[1], {f[x][0].first + f[u][1].first - 1, {f[u][1].second.first, 0}});
        upd(c[1], {f[x][1].first + f[u][2].first, f[x][1].second});
        upd(c[2], {f[x][2].first + f[u][2].first, f[x][2].second});
        upd(c[2], {f[x][1].first + f[u][1].first - 1, {f[x][1].second.first, f[u][1].second.first}});
        f[x][0] = c[0];
        f[x][1] = c[1];
        f[x][2] = c[2];
    }
    upd(f[x][1], {f[x][0].first, {x, 0}});
    upd(f[x][2], {f[x][0].first, {x, x}});
    upd(f[x][2], {f[x][1].first, {f[x][1].second.first, x}});
}
pair<pair<int, int>, pair<int, int> >work(int x) {
    if (!bz[x]) {
        
        int xx = f[x][2].second.first, yy = f[x][2].second.second;
        while (xx != yy) {
            if (deep[xx] < deep[yy]) swap(xx, yy);
            bz[xx]  =1;
            xx = fa[xx];
        }
        bz[xx] = 1;
        pair<int, int> li = f[x][2].second;
        for (auto u:g[x]) {
            auto v = work(u);
            pair<int, int> y = v.first;
            pair<int, int> _cut = v.second;
            if (y.first) {
                if (_cut.first)
                    ans.push_back({_cut, {li.second, y.first}});
                else
                    ans.push_back({{x, u}, {li.second, y.first}});
                li.second = y.second;
            }
        }
        return {li, {0, 0}};
    } else {
        pair<int, int> li = {0, 0};
        pair<int, int> cut = {0, 0};
        for (auto u:g[x]) {
            auto v = work(u);
            pair<int, int> y = v.first;
            pair<int, int> _cut = v.second;
            if (y.first) {
                if (_cut.first == 0) _cut = {x, u};
                if (!li.first) {
                    li = y;
                    cut = _cut;
                } else {
                    ans.push_back({cut, {li.second, y.first}});
                    li.second = y.second;
                    cut = _cut;
                }
            }
        }
        return {li, cut};
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i < n; i ++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        deep[1] = 0;
        dfs(1);
        ans.clear();
        work(1);
        printf("%d\n", (int) ans.size());
        for (auto u:ans)
            printf("%d %d %d %d\n", u.first.first, u.first.second, u.second.first, u.second.second);
        for (int i = 1; i <= n; i ++) g[i].clear(), bz[i] = 0;
    }
    return 0;
}