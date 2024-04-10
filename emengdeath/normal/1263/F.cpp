#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 3e3;
int fa[N][N], fb[N][N];
int n, a, b;
struct node{
    vector<int>g[N];
    int fa[N][15], deep[N];
    void dfs(int x) {
        for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
        deep[x] ++;
        for (auto u:g[x])
            deep[u] = deep[x], fa[u][0] = x,dfs(u);
    }
    int getlca(int x, int y) {
        int i = 14;
        if (deep[x] < deep[y]) swap(x, y);
        while (deep[x] > deep[y]) {
            while (deep[fa[x][i]] < deep[y]) i --;
            x =  fa[x][i];
        }
        i = 14;
        while (x != y){
            while (i && fa[x][i] == fa[y][i]) i --;
            x = fa[x][i], y = fa[y][i];
        }
        return x;
    }
    int get(int x, int y) {
        return deep[y] - deep[getlca(x, y)];
    }
}t1, t2;
int da[N], db[N];
void update(int&x, int y){
    x = min(x, y);
}
int main() {
    scanf("%d", &n);
    scanf("%d", &a);
    for (int i = 2; i <= a; i ++) {
        int x;
        scanf("%d", &x);
        t1.g[x].push_back(i);
    }
    for (int i = 1; i <= n; i ++)
        scanf("%d", &da[i]);
    scanf("%d", &b);
    for (int i = 2; i <= b; i ++) {
        int x;
        scanf("%d", &x);
        t2.g[x].push_back(i);
    }
    for (int i = 1; i <= n; i ++)
        scanf("%d", &db[i]);
    t1.dfs(1);
    t2.dfs(1);
    int alla = t1.deep[da[1]] - 1, allb = t2.deep[db[1]] - 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j++)
            fa[i][j] = fb[i][j] = 1e9;

    for (int i = 2; i <= n;i ++) {
        update(fa[i][i - 1], allb + t1.deep[da[i]] - 1);
        update(fb[i][i - 1], alla + t2.deep[db[i]] - 1);
        for (int j = 1; j < i - 1; j ++) {
                update(fa[i][j], fa[i - 1][j] + t1.get(da[i - 1], da[i]));
                update(fb[i][i - 1], fa[i - 1][j] + t2.get(db[j], db[i]));
                update(fb[i][j], fb[i - 1][j] + t2.get(db[i - 1], db[i]));
                update(fa[i][i - 1], fb[i - 1][j] + t1.get(da[j], da[i]));
        }
        alla += t1.get(da[i - 1], da[i]);
        allb += t2.get(db[i - 1], db[i]);
    }
    int ans = min(alla, allb);
    for (int i = 1; i <= n; i ++)
        ans = min(ans, min(fa[n][i], fb[n][i]));
    printf("%d\n", a + b - 2 - ans);
    return 0;
}