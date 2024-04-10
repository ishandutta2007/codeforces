#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int N = 1e5 + 10;
int sz[N], mxsz[N], d[N];
bool bz[N];
vector<pair<int, int> >g[N];
map<int, int> f;
int n, mod;
int a[N], nia[N];
long long ans = 0;
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
void dfs(int x, int fa){
    sz[x] = 1;
    d[++d[0]] = x;
    mxsz[x] = 0;
    for (auto u:g[x])
        if (!bz[u.first] && u.first != fa) {
            dfs(u.first, x);
            sz[x] += sz[u.first];
            mxsz[x] = max(mxsz[x], sz[u.first]);
        }
}
int did(int x) {
    return max(mxsz[x], d[0] - sz[x]);
}
int root(int x) {
    d[0] = 0;
    dfs(x, 0);
    for (int i = 1; i <= d[0]; i ++)
        if (did(d[i]) < did(x)) x = d[i];
    return x;
}
void dfs1(int x, int fa, int v, int len) {
    ans += f[sub(0, mul(v, nia[len]))];
    for (auto u:g[x])
        if (u.first != fa && !bz[u.first]) {
            dfs1(u.first, x, add(mul(v, 10), u.second), len + 1);
        }
}

void dfs2(int x, int fa, int v, int len) {
    ans += (!v);
    f[v] ++;
    for (auto u:g[x])
        if (u.first != fa && !bz[u.first]) {
            dfs2(u.first, x, add(v, mul(u.second, a[len])), len + 1);
        }
}
void dfs3(int x, int fa, int v, int len) {
    f[v] ++;
    for (auto u:g[x])
        if (u.first != fa && !bz[u.first]) {
            dfs3(u.first, x, add(v, mul(u.second, a[len])), len + 1);
        }
}
void dfs(int x) {
    x = root(x);
    f.clear();
    f[0] = 1;
    for (auto u:g[x])
        if (!bz[u.first]) {
            dfs1(u.first, x, u.second, 1);
            dfs2(u.first, x, u.second, 1);
        }
    f.clear();
    reverse(g[x].begin(), g[x].end());
    for (auto u:g[x])
        if (!bz[u.first]) {
            dfs1(u.first, x, u.second, 1);
            dfs3(u.first, x, u.second, 1);
        }
    bz[x] = 1;
    for (auto u:g[x])
        if (!bz[u.first])
            dfs(u.first);
}
long long exgcd(long long a,long long b,long long &x,long long &y) //ax+by=r
{
    if(b==0) return (x=1,y=0,a);
    if(a==0) return (x=0,y=1,b);
    long long r=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}
long long ni(long long a,long long b) //x*a%b=1
{
    long long x,y;
    if (exgcd(a,b,x,y) != 1) return -1;
    (((x%=b)+=b))%=b;
    return x;
}
int main() {
    scanf("%d %d", &n, &mod);
    a[0] = 1;
    for (int i = 1; i <= n; i ++)
        a[i] = mul(a[i - 1], 10);
    nia[0] = 1;
    nia[1] = ni(10, mod);
    for (int i = 2; i <= n; i ++)
        nia[i] = mul(nia[i - 1], nia[1]);
    for (int i = 1; i < n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        z %= mod;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}