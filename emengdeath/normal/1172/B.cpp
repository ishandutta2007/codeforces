#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
using namespace std;
const int N = 2e5  + 1;
const int mod = 998244353;
vector<int>g[N];
int n;
int sz[N + 1];
int a[N], ni[N + 1];
long long calc(long long x, long long y) {
    long long z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y /= 2;
    }
    return z;
}
long long C(int x, int y) {
    return a[x] * ni[y] % mod * ni[x - y] % mod;
}
void dfs(int x, int y) {
    sz[x] =1;
    for (auto u:g[x])
        if (y != u) {
            dfs(u, x);
            sz[x] += sz[u];
        }
}
long long dfs1(int x, int fa) {
    long long v = 1;
    int sum = 1;
    if (!fa) sum = 0;
    for (auto u:g[x])
        if (u != fa) {
            v = v *dfs1(u, x) % mod;
            sum++;
            v = v * sum % mod;
        }
    return v;
}
int main(){
    a[0] = 1;
    for (int i = 1;  i<= N; i ++)
        a[i] = a[i  -1] * i % mod;
    ni[N] = calc(a[N], mod - 2);
    for (int i = N - 1; i >= 0; i --)
        ni[i] = ni[i + 1] * (i + 1) % mod;
    scanf("%d", &n);
    for (int i = 1; i <  n ; i ++)  {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int x = 1;
    for (int i = 1; i <= n ; i ++)
        if (max(sz[x], n - sz[x]) > max(sz[i], n - sz[i])) x = i;
    dfs(x, 0);
    printf("%lld\n", dfs1(x, 0) * n % mod);
    return 0;
}