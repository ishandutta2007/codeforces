#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 111111;
const long long INF = 1e18;
struct Enode{
    int y, next;
} e[N + N];
int head[N], tot, a[N];
long long ans, b[N], c[N], f[N];


long long gcd(long long a, long long b){if (!b) return a; return gcd(b, a % b);}
long long lcm(long long a, long long b){if ((double) a / gcd(a, b) * b > INF) return INF; return a / gcd(a, b) * b;}

long long Dfs(int x, int par){
    long long mn = INF, sum = 0, cnt = 0, tmp = 1;
    for (int p = head[x]; p != -1; p = e[p].next)
    if (e[p].y != par){
        long long t = Dfs(e[p].y, x);
        mn = min(t, mn);
        sum += t;
        tmp = lcm(tmp, f[e[p].y]);
        cnt++;
    }
    if (!cnt){
        f[x] = 1;
        return a[x];
    }
    long long tt;
    if (tmp == 1e18) tt = 0; else tt = mn / tmp * tmp * cnt;
    f[x] = cnt * tmp;
    ans += sum - tt;
    return tt;
}
void Addedge(int x, int y){
    e[++tot].y = y; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].next = head[y]; head[y] = tot;
}
int main(){
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    tot = -1; memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        Addedge(x, y);
    }
    ans = 0;
    Dfs(1, 0);
    cout << ans << endl;
}