#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, int> >g[N];
int fa[N], dis[N], mx[N], upmx[N], id[N];
vector<int >d;
void dfs(int x){
    mx[x] = dis[x];
    for (auto u:g[x])
        if (u.first != fa[x]) {
            dis[u.first] = dis[x] + u.second;
            fa[u.first] = x;
            dfs(u.first);
            if (mx[x] < mx[u.first])
                mx[x] = mx[u.first], id[x] = u.first;
        }
}
void dfs1(int x){
    mx[x] = dis[x];
    for (auto u:g[x])
        if (u.first != fa[x]) {
            dis[u.first] = dis[x] + u.second;
            fa[u.first] = x;
            int v = upmx[x];
            if (id[x] == u.first) {
                for (auto u:g[x])
                    if (u.first != id[x] && u.first != fa[x])
                        v = max(v, mx[u.first] - dis[x]);
            } else {
                v = max(v, mx[x] - dis[x]);
            }
            upmx[u.first] = v + u.second;
            dfs1(u.first);
            mx[x] = max(mx[x], mx[u.first]);
        }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1 ; i < n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    dfs(1);
    int s = 1;
    for (int i = 1; i <= n; i ++)
        if (dis[i] > dis[s])
            s = i;
    memset(fa, 0, sizeof(fa));
    memset(dis, 0, sizeof(dis));
    dfs(s);
    dfs1(s);
    int t = s;
    for (int i = 1; i <= n; i ++)
        if (dis[i] > dis[t]) {
            t = i;
        }
    while (t!=s) {
        d.push_back(t);
        t = fa[t];
    }
    d.push_back(t);
    reverse(d.begin(), d.end());
    int ans = 2e9;
    int v = 0;
    for (int i = (int)d.size() - 1; i >= 0; i--) {
        for (auto u:g[d[i]])
            if (u.first != d[i + 1] && u.first != fa[d[i]])
                v = max(v, mx[u.first] - dis[d[i]]);
        if (i + k - 1 < d.size())
            for (auto u:g[d[i + k - 1]])
                if (u.first != fa[d[i + k - 1]])
                v = max(v, mx[u.first] - dis[d[i + k - 1]]);
        ans = min(ans, max(v, upmx[d[i]]));
    }
    printf("%d\n", ans);
    return 0;
}