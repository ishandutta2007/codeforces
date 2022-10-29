#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 1;
const int mod = 998244353;
long long f[N][3];
int n;
vector<int>g[N];
void dfs(int x)
{
    if (!g[x].size())
    {
        f[x][2] = 1;
        return;
    }
    f[x][0] = 1;
    long long v = 0;
    for (auto u:g[x]) {
        dfs(u);
        f[x][2] = (f[x][2] * ((f[u][0] + f[u][2] * 2 + f[u][1]) % mod) % mod + v * (f[u][1] + f[u][2]) % mod ) % mod;
        v = (v * (f[u][0] + f[u][2]) % mod + f[x][0] * (f[u][1] + f[u][2]) % mod) %mod;

        f[x][1] = (f[x][0] * (f[u][1] + f[u][2]) % mod + f[x][1] * (f[u][2] + f[u][0]) %mod) %mod;
        f[x][0] = f[x][0] * (f[u][0] + f[u][2]) % mod;
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 2; i <= n  ; i++)
    {
        int x;
        scanf("%d", &x);
        g[x].push_back(i);
    }
    dfs(1);
    printf("%d\n", (f[1][0] + f[1][2]) % mod);
    return 0;
}