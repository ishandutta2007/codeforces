#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6;
bool bz[N];
int n;
vector<int>g[N];
void dfs(int x, int fa) {
    for (auto u:g[x])
        if (u != fa) {
            bz[u] = (bz[x] ^ 1);
            dfs(u, x);
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int sum[2] = {0, 0};
    for (int i = 1; i <= n; i ++)
        sum[bz[i]] ++;
    printf("%d\n", min(sum[0], sum[1]) - 1);
    return 0;
}