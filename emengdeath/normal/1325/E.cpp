#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
int A[N], d[N];
int n;
vector<int>g[N], e[N];
set<pair<int, int> > af;
bool bf[N];
int dis[N], q[N];
int from[N];
int ans;
int f[N][2], id[N][2];
void dfs(int x) {
    f[x][0] = 1e9;
    f[x][1] = 1e9;
    id[x][0] = id[x][1] = 1e9;
    if (bf[x]) f[x][0] = 0, id[x][0] = x;
    for (auto u:e[x]) {
        dfs(u);
        if (f[x][0] >= f[u][0] + 1) {
            f[x][1] = f[x][0];
            id[x][1] = id[x][0];
            f[x][0] = f[u][0] + 1;
            id[x][0] = u;
        } else
            if (f[x][1] > f[u][0] + 1) {
                f[x][1] = f[u][0] +1;
                id[x][1] = u;
            }
    }
    ans = min(ans, f[x][0] + f[x][1] + 2);
}
void dfs(int x, int up) {
    ans = min(ans, f[x][0] + up + 2);
    for (auto u:e[x]) {
        if (id[x][0] == u) {
            dfs(u, min(up, f[x][1]) + 1);
        } else {
            dfs(u, min(up, f[x][0]) + 1);
        }
    }
}
void bfs(int x) {
    for (int i = 1; i <= d[0]; i ++)
        dis[i] = 0, e[i].clear();
    q[0] = 1, q[1] = x;
    dis[x] = 1;
    for (int i = 1; i <= q[0]; i ++) {
        for (auto u:g[q[i]])
            if (!dis[u])
                dis[u] = dis[q[i]] + 1, from[u] = q[i], q[++q[0]] = u, e[q[i]].push_back(u);
            else {
                if (u != from[q[i]])
                    ans = min(ans, dis[u] - 1 + dis[q[i]] - 1 + 1);
            }

    }
    dfs(x);
    dfs(x, 1e9);
}
int main() {
    for (int i = 2; i< N ; i++) {
        if (!A[i])
            d[A[i] = ++d[0]] = i;
        for (int j = 1; j <= A[i] && 1ll * d[j] * i < N ; j ++)
        {
            A[d[j] *i] = j;
        }
    }
    int S = 1;
    while (d[S + 1] <= 1000) ++S;
    ans = 1e9;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        int B[2] = {0, 0};
        int tot = -1;
        while (x != 1) {
            int y = A[x];
            bool sig = 0;
            while (A[x] == y) {
                sig ^= 1;
                x /= d[A[x]];
            }
            if (sig)
                B[++tot] = y;
        }
        if (tot == -1)
            ans = 1;
        else {
            if (tot == 0) {
                if (bf[B[0]]) ans = min(ans, 2);
                else
                    bf[B[0]] = 1;
            } else
            {
                if (af.find(make_pair(B[0], B[1]))!= af.end()) ans = min(ans, 2);
                else
                    af.insert(make_pair(B[0], B[1])),g[B[0]].push_back(B[1]), g[B[1]].push_back(B[0]);
            }
        }
    }
    for (int i = 1; i <= S; i ++) {
        bfs(i);
    }
    if (ans == 1e9) puts("-1");
    else
        printf("%d\n", ans);
    return 0;
}