#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5005;
struct Enode{
    int y, next;
    long long d;
} e[N * 2];
int n, x, y, d, i, tot, a[N], cnt;
long long ans, f[N][2], s[N], res, r1, r2, c1, c2, s1, s2, sum;
void Addedge(int x, int y, int d){
    e[++tot].y = y; e[tot].d = d; e[tot].next = a[x]; a[x] = tot;
    e[++tot].y = x; e[tot].d = d; e[tot].next = a[y]; a[y] = tot;
}
void Dfs1(int x, int par){
    int p = a[x];
    s[x] = 1; f[x][1] = 0;
    while (p != -1){
        int y = e[p].y;
        if (y != par){
            Dfs1(y, x);
            s[x] += s[y];
            f[x][1] += f[y][1] + e[p].d * s[y];
        }
        p = e[p].next;
    }
}
void Dfs2(int x, int par){
    int p = a[x];
    while (p != -1){
        int y = e[p].y;
        if (y != par){
            f[y][0] = f[x][0] + f[x][1] - f[y][1] - s[y] * e[p].d + (cnt - s[y]) * e[p].d;
            Dfs2(y, x);
        }
        p = e[p].next;
    }
    res = min(res, f[x][1] + f[x][0]);
    sum += f[x][1] + f[x][0];
}
void solve(int x, int y){
    memset(s, 0, sizeof(s));
    memset(f, 0, sizeof(f));
    Dfs1(x, y);
    cnt = s[x];
    Dfs2(x, y);
}
int main(){
    scanf("%d", &n);
    tot = -1; memset(a, -1, sizeof(a));
    for (i = 1; i < n; i++){
        scanf("%d%d%d", &x, &y, &d);
        Addedge(x, y, d);
    }
    ans = 1e18;
    for (i = 0; i <= tot; i += 2){
        res = 1e18; sum = 0;
        solve(e[i].y, e[i ^ 1].y);
        c1 = s[e[i].y]; r1 = res; s1 = sum / 2;
        res = 1e18; sum = 0;
        solve(e[i ^ 1].y, e[i].y);
        c2 = s[e[i ^ 1].y]; r2 = res; s2 = sum / 2;
        ans = min(ans, s1 + s2 + c1 * c2 * e[i].d + r1 * c2 + r2 * c1);
    }
    cout << ans << endl;
}