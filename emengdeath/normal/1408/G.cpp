#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 5000;
vector<pair<int, pair<int, int> > > d;
int n;
const int mod = 998244353;
int fa[N], son[N][2], sum[N];
bool can[N];
int b[N][N];
int tot;
int f[N][N];
int fa1[N];
int getfa(int x) {
    return fa[x] == x? x : fa[x] = getfa(fa[x]);
}
void dfs(int x) {
    if (x <= n) {
        f[x][1] = 1;
        return;
    }
    dfs(son[x][0]), dfs(son[x][1]);
    int y = son[x][0], z = son[x][1];
    for (int i = 0; i <= sum[y]; i ++)
        for (int j = 0; j <= sum[z]; j++)
            f[x][i + j] = (f[x][i + j] + 1ll * f[y][i] * f[z][j]) % mod;
    if (can[x])
        f[x][1] = (f[x][1] + 1) % mod;
}
void dfs(int x, int u, int&mx) {
    mx = max(mx, b[x][u]);
    if (x <= n) return;
    dfs(son[x][0], u, mx);
    dfs(son[x][1], u, mx);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n;i ++) {
        vector<pair<int, int> > w;
        for (int j = 1; j <= n;j ++){
            int x;
            scanf("%d", &x);
            w.push_back({x, j});
        }
        sort(w.begin(), w.end());
        for (int j = 1; j < n ;j ++)
            b[w[j].second][i]= b[i][w[j].second] = max(b[i][w[j].second], j + 1);
    }
    for (int i =1; i <= n;i ++)
        for (int j = 1; j < i; j ++)
            d.push_back({b[i][j], {i, j}});
    for (int i = 1; i <= n; i++)
        can[i] = 1, sum[i] = 1,fa[i] = i;
    sort(d.begin(), d.end());
    tot = n;
    for (auto u:d)
        if (getfa(u.second.first) != getfa(u.second.second)) {
            ++tot;
            fa[tot] = tot;
            fa1[getfa(u.second.first)] = fa1[getfa(u.second.second)] = tot;
            sum[tot] = sum[getfa(u.second.first)] + sum[getfa(u.second.second)];
            son[tot][0] = getfa(u.second.first), son[tot][1] = getfa(u.second.second);
            can[son[tot][0]] &= u.first > sum[son[tot][0]];
            can[son[tot][1]] &= u.first > sum[son[tot][1]];
            fa[getfa(u.second.first)] = fa[getfa(u.second.second)] = tot;
            can[tot] = (sum[tot] >= u.first);
        }
    for (int i = 1; i <= n; i ++) {
        int x = i;
        int mx = 0;
        while (x != tot) {
            int y = fa1[x];
            if (son[y][0] != x) dfs(son[y][0], i, mx);
            else
                dfs(son[y][1], i, mx);
            can[y] &= (sum[y] >= mx);
            x = y;
        }
    }
    dfs(tot);
    for (int i= 1; i <= n; i++)
        printf("%d%c", f[tot][i], " \n"[i == n]);
    return 0;
}