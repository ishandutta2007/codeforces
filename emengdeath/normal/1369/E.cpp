#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n, m;
vector<int> g[N];
bool bz[N];
int w[N];
int a[N][2];
vector<int> ans;
vector<int> d;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        w[x] --;
        w[y] --;
        g[x].push_back(i);
        g[y].push_back(i);
        a[i][0] = x;
        a[i][1] = y;
    }
    for (int i = 1; i <= n; i ++)
        if (w[i] >= 0)
            d.push_back(i);
    for (int i = 0; i < d.size(); i ++)
        for (auto u:g[d[i]])
            if (!bz[u]) {
                ans.push_back(u);
                bz[u] = 1;
                w[a[u][0]] ++;
                if (!w[a[u][0]])
                    d.push_back(a[u][0]);
                w[a[u][1]] ++;
                if (!w[a[u][1]])
                    d.push_back(a[u][1]);
            }
    if (ans.size() == m) {
        puts("ALIVE");
        reverse(ans.begin(), ans.end());
        for (auto u:ans)
            printf("%d ", u);
    } else {
        puts("DEAD");
    }
    return 0;
}