#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lx x + x
#define rx lx + 1
#define ly y + y
#define ry ly + 1
typedef long long LL;

const int N = 2005;
const int M = 1005;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-6;

int e[N][N], inz[N], z[N], fa[N], dfn[N], low[N], top, v[N], tim, n;

void Pop(int x){
    int l = inz[x];
    for (int i = l; i <= top; i++){
        fa[z[i]] = x;
        inz[z[i]] = 0;
    }
    top = l - 1;
}

void Dfs(int x, int par){
    v[x] = 1;
    dfn[x] = low[x] = ++tim;
    z[++top] = x; inz[x] = top;
    for (int y = 1; y <= n; y++)
    if (e[x][y]){
        if (!v[y]){
            Dfs(y, x);
            low[x] = min(low[x], low[y]);
        }else if (inz[y]) low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) Pop(x);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        scanf("%d", &e[i][j]);
    for (int i = 1; i <= n; i++)
    if (!v[i]) Dfs(i, 0);
    for (int i = 1; i <= n; i++) if (fa[i] != fa[1]){
        puts("NO");
        return 0;
    }
    puts("YES");
}