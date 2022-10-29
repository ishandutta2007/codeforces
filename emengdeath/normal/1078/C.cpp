#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long f[300001][3], e[3];
int n;
vector<int>g[300001];
void dfs(int x, int fa) {
    bool tag = 0;
    for (auto u:g[x])
        if (u != fa) {
            tag = 1;
            dfs(u, x);
        }
    if (!tag) {
        f[x][0] = 1;
        return;
    }
    tag = 0;
    for (auto u:g[x])
        if (u != fa) {
            if (!tag) {
                tag = 1;
                f[x][0] = (f[u][0] + f[u][1])%mod;
                f[x][1] = (f[u][0] + f[u][2])%mod;
                f[x][2] = f[u][1];
                continue;
            }
            e[0] = f[x][0] * ((f[u][0] + f[u][1])%mod) % mod;
            e[1] = (f[x][0] * ((f[u][0] + f[u][2])%mod) % mod + f[x][1] * ((f[u][0] + f[u][1]*2)%mod) % mod + f[x][2] * ((f[u][0] + f[u][2])%mod) % mod) % mod;
            e[2] = (f[x][0] * f[u][1] % mod + f[x][2] * ((f[u][1]*2 + f[u][0])%mod) % mod) % mod;
            f[x][0] = e[0];
            f[x][1] = e[1];
            f[x][2] = e[2];
        }
    
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x,y;
        scanf("%d %d",&x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    printf("%lld", (f[1][0] + f[1][1]) % mod);
    return 0;
}