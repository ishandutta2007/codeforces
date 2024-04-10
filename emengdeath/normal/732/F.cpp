#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 400001;
vector<pair<int, int> >g[N];
int bel[N], sum[N];
int n, m;
bool bz[N], instack[N];
int ans[N][2];
int fath[N], deep[N];
int get(int x) {
    return bel[x] == x? x:bel[x] = get(bel[x]);
}
void up(int x, int y) {
    while (deep[get(y)] > deep[x]) {
        y = get(y);
        int xx = get(fath[y]);
        bel[y] = bel[xx];
        sum[xx] += sum[y];
        y = xx;
    }
}
void dfs(int x, int fa) {
    bz[x] = 1;
    instack[x] = 1;
    deep[x] ++;
    for (auto u:g[x])
        if (u.first != fa) {
            if (bz[u.first]) {
                if (instack[u.first])up(u.first, x);
            } else
                deep[u.first] = deep[x], fath[u.first] = x, dfs(u.first, x);
        }
    instack[x] = 0;
}
void dfs1(int x, int fa) {
    bz[x] = 1;
    instack[x] = 1;
    for (auto u:g[x])
        if (u.first != fa) {
            if (bz[u.first]) {
                if (instack[u.first])ans[u.second][0] = x, ans[u.second][1] = u.first;
            } else {
                dfs1(u.first, x);
                if (get(u.first) == get(x))
                    ans[u.second][0] = x, ans[u.second][1] = u.first;
                else
                    ans[u.second][1] = x, ans[u.second][0] = u.first;
            }
        }
    instack[x] = 0;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back({y,i});
        g[y].push_back({x,i});
    }
    for (int i = 1; i <= n; i ++)
        bel[i] = i, sum[i] = 1;
    dfs(1, 0);
    int x = 1;
    for (int i = 2;i <= n; i ++)
        if (sum[get(x)] < sum[get(i)])
            x = i;
    memset(bz, 0, sizeof(bz));
    printf("%d\n", sum[get(x)]);
    dfs1(x, 0);
    for (int i = 1; i <= m; i ++)
        printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}