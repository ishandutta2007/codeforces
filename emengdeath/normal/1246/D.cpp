#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int len[N];
int n;
vector<int> ans;
bool bz[N];
void dfs(int x) {
    bz[x] = (g[x].size() > 1);
    for (auto u:g[x])
    {
        dfs(u);
        bz[x] |= bz[u];
        len[x] = max(len[u], len[x]);
    }
    len[x] ++;
    sort(g[x].begin(), g[x].end(), [](int x, int y) {
        return len[x] < len[y];
    });
}
void dfs1(int x) {
    while (g[x].size() > 1 || (g[x].size() && bz[g[x][0]])) {
        if (g[x].size() == 1) {
            dfs1(g[x][0]);
        } else {
            ans.push_back(g[x][g[x].size() - 1]);
            g[g[x][g[x].size() - 2]].push_back(g[x][g[x].size() - 1]);
            g[x].pop_back();
            dfs1(g[x][g[x].size() - 1]);
        }
    }
    bz[x] = 0;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ; i ++) {
        int x;
        scanf("%d", &x);
        g[x].push_back(i);
    }
    dfs(0);
    dfs1(0);
    int x = 0;
    printf("%d", x);
    while (g[x].size()) {
        printf(" %d", x = g[x][0]);
    }
    puts("");
    reverse(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%d ", u);
    return 0;
}