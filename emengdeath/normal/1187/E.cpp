#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
using namespace std;
const int N = 1e6 + 10;
int sz[N];
long long f[N];
int n;
long long ans;
vector<int>g[N];
void dfs(int x, int fa){
    sz[x]  =1;
    for (auto u:g[x])
        if (u !=fa) {
            dfs(u, x);
            sz[x] += sz[u];
            f[x] += f[u];
        }
    f[x] +=sz[x];
}
void dfs(int x, int fa, long long sum){
    ans = max(ans, sum + f[x] - sz[x] + n);
    for (auto u:g[x])
        if (u !=fa) {
            dfs(u, x, sum + f[x] - sz[x] - f[u] + n - sz[u]);
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ; i  ++){
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    dfs(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}