#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 5e5 + 10;
int n, m;
vector<pair<int, int> > g[N];
int dis[N];
int col[N];
int d[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int x ,y, z;
        scanf("%d %d %d", &x ,&y, &z);
        g[y].push_back({x, z});
    }
    dis[n] = 1;
    col[n] = 2;
    d[0] = 1;
    d[1] = n;
    for (int i = 1; i <= d[0]; i ++)
        for (auto u:g[d[i]])
            if (!col[u.first]) {
                col[u.first] = (u.second ^ 1) + 1;
            } else {
                if (col[u.first] - 1 == u.second && !dis[u.first]) {
                    dis[u.first] = dis[d[i]] + 1;
                    d[++d[0]] = u.first;
                }
            }
    printf("%d\n", dis[1] - 1);
    for (int i = 1; i <= n; i ++)
        if (!col[i]) printf("1");
        else
            printf("%d", col[i] - 1);
    return 0;
}