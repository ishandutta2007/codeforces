#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5  +10;
int f[N], a[N], w[N];
int n;
vector<int>g[N];
void dfs(int x, int fa) {
    f[x] = a[x] * 2 - 1;
    for (auto u:g[x])
    if (u!=fa){
        dfs(u, x);
        if (f[u] > 0)
            f[x] += f[u];
    }
}

void dfs1(int x, int fa, int v) {
    w[x] = f[x] + v;
    for (auto u:g[x])
    if (u!=fa){
        if (f[u] > 0)
            dfs1(u, x, max(w[x] - f[u], 0));
        else
            dfs1(u, x, max(w[x] , 0));
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n;  i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i ++)
    {
        int x, y;
        scanf("%d %d", &x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    dfs1(1, 0, 0);
    for (int i = 1;i <= n ; i ++)
        printf("%d%c", w[i], " \n"[i == n]);
    return 0;
}