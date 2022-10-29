#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 +10;
vector<pair<int, pair<int, int> > > g[N];
int edgev[N];
int s[N], remain[N];
bool bz[N];
int n, m;
void dfs(int x) {
    bz[x] = 1;
    remain[x] = s[x];
    for (auto u:g[x])
        if (!bz[u.first]) {
            dfs(u.first);
            edgev[u.second.first] += remain[u.first] * u.second.second;
            remain[x] += remain[u.first];
        }
}
int main() {
    scanf("%d", &n);
    int all = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &s[i]), all += s[i];
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++ ){
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(make_pair(y, make_pair(i, 1)));
        g[y].push_back(make_pair(x, make_pair(i, -1)));
    }
    if (all) {
        printf("Impossible");
        return 0;
    }
    dfs(1);
    printf("Possible\n");
    for (int i = 1; i <= m; i ++)
        printf("%d\n", edgev[i]);
    return 0;
}