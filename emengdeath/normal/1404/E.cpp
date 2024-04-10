#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 300;
namespace HopcroftKarp {
#define inf 0x3f3f3f3f
    const int N = 210 * 210;
    vector<int>g[N];
    int matchx[N], matchy[N], vis[N], dx[N], dy[N];
    int dis;
    int nx, ny;
    void init(int _nx, int _ny){
        nx = _nx;
        ny = _ny;
        for (int i = 1; i <= nx; i ++) g[i].clear();
    }
    void add_edge(int x, int y) {
        g[x].push_back(y);
    }
    bool search_path()
    {
        queue<int> q;
        while (!q.empty()) q.pop();
        dis=inf;
        for (int i = 1; i <= ny; i ++)
            dy[i] = -1;
        for (int i = 1; i <= nx ; i ++)
            if (matchx[i] == -1) {
                q.push(i);
                dx[i] = 0;
            } else  dx[i] = -1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (dx[u] > dis) break;
            for (auto v : g[u])
                if (dy[v] == -1)
                {
                    dy[v] = dx[u] + 1;
                    if (matchy[v] == -1) dis = dy[v];
                    else
                    {
                        dx[matchy[v]] = dy[v] + 1;
                        q.push(matchy[v]);
                    }
                }
        }
        return dis != inf;
    }
    bool dfs(int x)
    {
        for (auto u : g[x])
            if (!vis[u] && dy[u] == dx[x] + 1)
            {
                vis[u] = 1;
                if (matchy[u] != -1 && dy[u] == dis) continue;
                if (matchy[u] == -1 || dfs(matchy[u]))
                {
                    matchy[u] = x;
                    matchx[x] = u;
                    return 1;
                }
            }
        return 0;
    }
    int solve()
    {
        int cnt = 0;
        for (int i = 1; i <= nx; i ++)
            matchx[i] = -1;
        for (int i = 1; i <= ny; i ++)
            matchy[i] = -1;
        while (search_path())
        {
            for (int i = 1; i <= ny; i ++) vis[i] = 0;
            for (int i = 1; i <= nx; i ++)
                if (matchx[i] == -1 && dfs(i)) cnt ++;
        }
        return cnt;
    }
}
char a[N][N];
int n, m;
bool sigL[N * N], sigR[N * N];
int id(int x, int y) {
    return (x - 1) * m + y;
}
int main() {
    scanf("%d %d", &n, &m);
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            scanf(" %c", &a[i][j]);
        }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            if (a[i][j] == '#' && a[i + 1][j] == '#')
                ans--, sigL[id(i, j)] = 1;
            if (a[i][j] == '#' && a[i][j + 1] == '#')
                ans--, sigR[id(i, j)] = 1;
        }
    HopcroftKarp::init(n*m, n*m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            if (a[i][j] == '#') {
                ans++;
                if (i != 1 && j != 1 && sigL[id(i - 1, j)] && sigR[id(i, j - 1)])
                    HopcroftKarp::add_edge(id(i - 1, j), id(i, j -1));
                if (i != 1&& sigL[id(i - 1, j)] && sigR[id(i, j)])
                    HopcroftKarp::add_edge(id(i - 1, j), id(i, j) );
                if (j != 1&& sigL[id(i, j)] && sigR[id(i, j - 1)])
                    HopcroftKarp::add_edge(id(i, j), id(i, j -1));
                if (sigL[id(i, j)] && sigR[id(i, j)])
                    HopcroftKarp::add_edge(id(i, j), id(i, j));
            }
        }
    ans += HopcroftKarp::solve();
    printf("%d\n", ans);
    return 0;
}