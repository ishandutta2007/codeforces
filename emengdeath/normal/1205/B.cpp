#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
using namespace std;
vector<int>g[1000], e[100001];
long long a[1000000];
int dis[1000001];
int d[100001];
vector<int>q;
int n;
int bfs(int x, int y){
    int l = 0, r = 1;
    for (auto u:q)
        dis[u] = 0;
    dis[x] = 1;
    d[1] = x;
    while (l != r) {
        for (auto u:e[d[++l]])
            if (!(u == x && d[l] == y ) && !(u == y && d[l] == x) && !dis[u])
                dis[u] = dis[d[l]] + 1, d[++r] = u;
    }
    if (dis[y] == 0) return 1e9;
    return dis[y];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++) {
        scanf("%lld", &a[i]);
        int tag = 0;
        for (long long j = 1; a[i] / j > 0; j *= 2, tag ++)
            if (a[i] & j){
                g[tag].push_back(i);
            }
    }
    for (int i = 0; i < 100; i ++) {
        if (g[i].size() >= 3) {
            printf("3\n");
            return 0;
        }
        if (g[i].size() == 2) {
            int x = g[i][0], y = g[i][1];
            e[x].push_back(y);
            e[y].push_back(x);
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n ; i ++)
        if (e[i].size()) q.push_back(i);
    for (int i = 1; i <= n ; i++)
        for (auto u:e[i])
            ans = min(ans, bfs(i, u));
    if (ans > n )printf("-1");
    else
        printf("%d\n", ans);
    return 0;
}