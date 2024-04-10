#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
const int mod = 998244353;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
int inv(int x) {
    return calc(x, mod - 2);
}
const int N = 5001;
vector<int> f[N];
int n, m;
vector<int> g[N];
void dfs(int x, int fa) {
    f[x] = vector<int> (n, 0);
    f[x][0] = 1;
    for (auto u:g[x]) {
        if (u == fa) continue;
        dfs(u, x);
        vector<int> c(n, 0);
        vector<int> Fu(n, 0), Fx(n, 0);
        Fu[0] = f[u][0];
        for (int i = 1; i < n ; i ++)
            Fu[i] = add(f[u][i], Fu[i - 1]);
        Fx[0] = f[x][0];
        for (int i = 1; i < n ; i ++)
            Fx[i] = add(f[x][i], Fx[i - 1]);
        for (int i = 0; i < n; i ++)
        {
            int r = min(i - 1, m - 1 - i);
            if (r >= 0)
                c[i] = add(c[i], mul(f[x][i], Fu[r]));
            r = min(i, m - 1 - i);
            if (r >= 0 && f[u][i])
                c[i + 1] = add(c[i + 1], mul(f[u][i], Fx[r]));
            
            c[i] = add(c[i], mul(f[x][i], Fu[n - 1]));
        }
        f[x] = c;
    }
}
int main() { 
    scanf("%d %d", &n, &m);
    for (int i= 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 0; i <= m; i ++) ans = add(ans, f[1][i]);
    printf("%d\n", ans);
    return 0;
}