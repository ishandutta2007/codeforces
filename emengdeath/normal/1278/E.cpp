#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6;
int L[N], R[N];
vector<int> g[N];
int sz[N];
int fa[N], d[N];
int n;
int cnt;
void dfs(int x) {
    sz[x] = 1;
    for (auto u:g[x])
        if (u!=fa[x]) {
            fa[u] = x;
            dfs(u);
            sz[x] += sz[u];
        }
}
void dfs(int x, int st) {
    int sum = g[x].size();
    if (x != 1) sum --;
    R[x] = st + sum + 1;
    int all = 0;
    int allsz = 0;
    for (auto u:g[x])
        if (u!=fa[x]) {
            L[u] = R[x] - (++all);
            dfs(u, R[x] + allsz);
            allsz += sz[u] * 2 - 1;
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ; i  ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    L[1] = 1;
    dfs(1, 1);
    for (int i = 1;i <= n;  i++)
        printf("%d %d\n", L[i], R[i]);
    return 0;
}