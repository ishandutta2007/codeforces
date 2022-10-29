#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1e6;
vector<int>g[N];
int p[N];
vector<pair<int, int> > f[N];
int b[N][2][2];
int n;
void dfs(int x, int fa) {
    for (auto u:g[x])
        if (u != fa) {
            dfs(u, x);
            if (b[u][0][1] + 1 > b[x][0][1]) {
                b[x][1][1] = b[x][0][1];
                b[x][1][0] = b[x][0][0];
                b[x][0][1] = b[u][0][1] + 1;
                b[x][0][0] = u;
            } else
                if (b[u][0][1] + 1 > b[x][1][1]) {
                    b[x][1][1] = b[u][0][1] + 1;
                    b[x][1][0] = u;
                }
        }
}
void dfs(int x, int fa, int v) {
    if (fa)
        f[x].push_back(make_pair(v, 1));
    for (auto u:g[x])
        if (u != fa)
        {
            f[x].push_back(make_pair(b[u][0][1] + 1, 1));
            if (b[x][0][0] != u)
                dfs(u, x, max(v, b[x][0][1]) + 1);
            else
                dfs(u, x, max(v, b[x][1][1]) + 1);

        }
}
void update(int x, int v) {
    p[x] = max(p[x], v);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        p[i] = 1;
    }
    p[n] = 1;
    dfs(1, 0);
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i ++){
        sort(f[i].begin(), f[i].end());
        update(1, f[i].size() + 1);
        reverse(f[i].begin(), f[i].end());
        int l = 0;
        for (int j = 1; j < f[i].size(); j ++)
            if (f[i][j].first!=f[i][l].first)
                f[i][++l] = f[i][j];
            else
                f[i][l].second ++;
        f[i].resize(l + 1);
        int sum = 0;
        for (auto v:f[i])
        {
            if (sum)
                update(v.first * 2 + 1, sum + 1);
            sum += v.second;
            update(v.first * 2, sum);
        }
    }
    for (int i = n - 1; i>= 1; i --)
        p[i] = max(p[i], p[i + 1]);
    for (int i = 1;i  <= n ; i ++)
        for (auto u:g[i])
            if (u < i) {
                int x = i , y = u;
                vector<pair<int, int> > d;
                int l1 = 0, l2 = 0;
                while (l1 < f[x].size() || l2 < f[y].size()) {
                    if (l2 == f[y].size() || (l1 != f[x].size() && f[x][l1].first >= f[y][l2].first)) {
                        d.push_back(f[x][l1 ++]);
                    } else
                        if (d.size() && d[d.size() - 1].first == f[y][l2].first) {
                            d[d.size() - 1].second += f[y][l2 ++].second;
                        }else
                            d.push_back(f[y][l2 ++]);
                }
                int sum = -2;
                for (auto v:d)
                {
                    sum += v.second;
                    update(v.first * 2, sum);
                }
            }
    for (int i = n - 2; i>= 1; i --)
        p[i] = max(p[i], p[i + 2]);
    for (int i = 1; i <= n; i ++)
        printf("%d%c", p[i], " \n"[i == n]);
    return 0;
}