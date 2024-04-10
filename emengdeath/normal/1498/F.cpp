#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, m;
vector<int> g[N];
long long f[N][41], F[N], tmp[41];
int v[N];
void dfs(int x, int fa) {
    for (int i = 0; i < g[x].size(); i ++)
        if (g[x][i] == fa) {
            swap(g[x][i], g[x][g[x].size() - 1]);
            g[x].pop_back();
            break;
        }
    f[x][0] ^= v[x];
    for (auto u:g[x]) {
        dfs(u, x);
        for (int i = 0; i < m * 2; i ++)
            f[x][(i + 1) % (m * 2)] ^= f[u][i];
    }
}
void dfs(int x, long long * uf) {
    long long uff[41];
    for (int i = m; i < 2 * m ; i ++)
        F[x] ^= f[x][i] ^ uf[i];
    for (auto u:g[x]) {
        for (int i = 0; i < m * 2; i ++)
            uff[(i + 1) % (m * 2)] = uf[i];
        for (int i = 0; i < m * 2; i ++)
            uff[(i + 1) % (m * 2)] ^= f[x][i];
        for (int i = 0; i < m * 2; i ++)
            uff[(i + 2) % (m * 2)] ^= f[u][i];
        dfs(u, uff);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &v[i]);
    }
    dfs(1, 0);
    dfs(1, tmp);
    for (int i = 1; i <= n; i ++)
        if (F[i])
            printf("1 ");
        else printf("0 ");
    return 0;
}