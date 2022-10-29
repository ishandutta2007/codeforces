#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e6 + 10;
int du[N];
int a[N];
int n, cnt;
vector<pair<pair<int, int>, int> > g[N];
vector<int> ans;
bool bz[N];
void dfs(int x) {
    while (g[x].size()) {
        if (bz[g[x][0].first.first]) {
            swap(g[x][0], g[x][g[x].size() - 1]);
            g[x].pop_back();
            continue;
        }
        auto u = g[x][0];
        swap(g[x][0], g[x][g[x].size() - 1]);
        g[x].pop_back();
        bz[u.first.first] = bz[u.first.second] = 1;
        dfs(u.second);
        ans.push_back(u.first.second);
        ans.push_back(u.first.first);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; i ++)
        scanf("%d", &a[i]);
    for (int i = 20; i >= 0; i --) {
        for (int j = 0; j < (1 << i); j ++)
            du[j] = 0, g[j].clear();
        for (int j = 1; j <= n * 2; j ++)
            bz[j] = 0;
        for (int j = 1; j <= n * 2; j += 2)
            du[a[j] % (1 << i)] ++, du[a[j + 1] % (1 << i)] ++;
        bool sig = 1;
        for (int j = 0; j < (1 << i); j ++)
            sig &= (!(du[j] & 1));
        if (sig) {
            for (int j = 1; j <= n * 2; j += 2) {
                g[a[j] % (1 << i)].push_back({{j, j + 1}, a[j + 1] % (1 << i)}), g[a[j + 1] % (1 << i)].push_back(
                        {{j + 1, j}, a[j] % (1 << i)});
            }
            ans.clear();
            for (int j = 0; j < (1 << i); j ++)
                if (du[j]) {
                    dfs(j);
                    break;
                }
            if (ans.size() == n + n) {
                printf("%d\n", i);
                for (auto u:ans)
                    printf("%d ", u);
            } else {
                continue;
            }
            return 0;
        }
    }
    return 0;
}