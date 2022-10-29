#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5  +10;
long long all[N], h[N], allh[N];
vector<int> g[N];
int n, m;
bool sig;
int T;
void dfs(int x, int fa) {
    allh[x] = 0;
    for (auto u:g[x])
        if (u != fa){
            dfs(u, x);
            all[x] += all[u];
            allh[x] += h[u];
        }
    if ((all[x] + h[x]) & 1) sig = 0;
    h[x] = (all[x] + h[x]) / 2;
    if (all[x] < h[x]) sig = 0;
    if (allh[x] > h[x]) sig = 0;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++)
            scanf("%lld", &all[i]);
        for (int i = 1; i <= n; i ++)
            scanf("%lld", &h[i]);
        for (int i= 1; i<n; i ++) {
            int x ,y;
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        sig = 1;
        dfs(1, 0);
        sig ?puts("YES"):puts("NO");
        for (int i = 1; i <= n;i ++)
            g[i].clear();
    }
    return 0;
}