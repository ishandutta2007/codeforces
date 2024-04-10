#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5;
int n;
int a[N], l[N], r[N];
vector<int>g[N];
vector<pair<int, int> >gg[N];
int father[N], deep[N], fa[N][20], f[N][20];
bool sig[N];
int cnt;
void dfs(int x, int father) {
    bool is_leaf = 1;
    l[x] = n, r[x] = 0;
    for (auto u:g[x])
        if (u != father) {
            dfs(u, x);
            l[x] = min(l[x], l[u]);
            r[x] = max(r[x], r[u]);
            is_leaf = 0;
        }
    if (is_leaf)
        l[x] = r[x] = ++cnt;
}
void dfs(int x) {
    for (int i = 0; fa[fa[x][i]][i]; i ++)
        fa[x][i + 1] = fa[fa[x][i]][i], f[x][i + 1] = max(f[fa[x][i]][i], f[x][i]);
    deep[x] ++;
    for (auto u:gg[x])
        if (u.first != fa[x][0]) {
            deep[u.first] = deep[x];
            fa[u.first][0] = x;
            f[u.first][0] = u.second;
            dfs(u.first);
        }
}
int getfa(int x) {return x == father[x] ? x : father[x] = getfa(father[x]);}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= cnt + 1; i ++) father[i] = i;
    vector<pair<pair<int, int>, pair<int, int> > > d;
    for (int i = 1; i <= n; i ++) {
        d.push_back({{a[i], i}, {l[i], r[i] + 1}});
    }
    sort(d.begin(), d.end());
    long long ans = 0;
    vector<int>ans1;
    for (auto u:d)
    {
        int x = getfa(u.second.first), y  =getfa(u.second.second);
        if (x != y) {
            father[x] = y;
            gg[u.second.first].push_back({u.second.second, u.first.first});
            gg[u.second.second].push_back({u.second.first, u.first.first});
            ans += u.first.first;
            sig[u.first.second] = 1;
            ans1.push_back(u.first.second);
        }
    }
    dfs(1);
    for (auto u:d)
        if (!sig[u.first.second]) {
            int x = u.second.first, y = u.second.second;
            int mx = 0;
            int i = 19;
            if (deep[x] < deep[y]) swap(x, y);
            while (deep[x] != deep[y]) {
                while (deep[fa[x][i]] < deep[y]) i --;
                mx = max(f[x][i], mx), x = fa[x][i];
            }
            i = 19;
            while (x != y) {
                while (i && fa[x][i] == fa[y][i]) i --;
                mx = max(max(mx, f[x][i]), f[y][i]);
                x = fa[x][i], y = fa[y][i];
            }
            if (mx == u.first.first)
                ans1.push_back(u.first.second);
        }
    printf("%lld %d\n", ans, (int)ans1.size());
    sort(ans1.begin(), ans1.end());
    for (auto u: ans1)
        printf("%d ", u);
    return 0;
}