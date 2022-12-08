#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long int64;
typedef unsigned long long qword;
typedef unsigned int uint;

const int INFI_INT = 1<<30;
const int64 INFI_INT64 = (int64)(1<<30) * (int64)(1<<30);
const double PI = 3.14159265358979323846264338;

template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

const int maxn = 100010;
const int maxedges = 300010;

int g[maxn], g_link[maxedges*2], g_next[maxedges*2];
int dfn[maxn], low[maxn], vis[maxn], ttt;
int ansx[maxedges], ansy[maxedges], ansi;
bool flag;
int n, m;

void dfs(int x, int fa) {
    //printf("x=%d fa=%d\n", x, fa);
    low[x] = dfn[x] = ++ ttt;
    vis[x] = -1;
    for (int e = g[x], y; e > 0; e = g_next[e])
        if ((y = g_link[e]) != fa) {
            //printf("   y=%d\n", y);
            if (vis[y] > 0)
                continue;
            ansi ++, ansx[ansi] = x, ansy[ansi] = y;
            if (vis[y] == 0) {
                dfs(y, x);
                if (low[y] > dfn[x])
                    flag = false;
                low[x] = min(low[x], low[y]);
            } else
                low[x] = min(low[x], dfn[y]);
        }
    vis[x] = 1;
}

void solve() {
    scanf("%d%d", &n, &m);
    fillchar(g, 0);
    for (int e = 0, im = 1; im <= m; ++ im) {
        int a, b;
        scanf("%d%d", &a, &b);
        g_link[++ e] = b, g_next[e] = g[a], g[a] = e;
        g_link[++ e] = a, g_next[e] = g[b], g[b] = e;
    }
    fillchar(vis, 0);
    ttt = 0;
    ansi = 0;
    flag = true;
    dfs(1, 0);
    if (flag) {
        forint (i, 1, m)
            printf("%d %d\n", ansx[i], ansy[i]);
    } else
        printf("0\n");
}

int main() {
    /*
    5 6
    1 2 1 3 1 4 1 5 2 3 4 5
    
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
    //*/
    /*
  	for (;;)
    //*/
    solve();
    return 0;
}