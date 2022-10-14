#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 3000;
const int Q = 400000;
const int D = 13;

int n;
std::vector<int> g[N], ig[N];

void dfs(std::vector<bool>& reach, int u)
{
    if (reach[u]) {
        return;
    }
    reach[u] = true;
    for (auto v : ig[u]) {
        dfs(reach, v);
    }
}

int result[Q];
std::vector<int> stack, child[N];
std::vector<std::pair<int, int>> qs[N][N];

void solve(int t, int u)
{
    stack.push_back(u);
    for (auto it : qs[t][u]) {
        if (it.first < (int)stack.size()) {
            result[it.second] = stack[(int)stack.size() - 1 - it.first] + 1;
        }
    }
    for (auto v : child[u]) {
        solve(t, v);
    }
    stack.pop_back();
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("F.in", "r", stdin);
#endif
    int m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++ i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x --;
        y --;
        g[x].push_back(y);
        ig[y].push_back(x);
    }
    for (int i = 0; i < n; ++ i) {
        std::sort(g[i].begin(), g[i].end());
    }
    for (int i = 0; i < q; ++ i) {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        qs[y - 1][x - 1].emplace_back(k - 1, i);
    }
    memset(result, -1, sizeof(result));
    for (int t = 0; t < n; ++ t) {
        std::vector<bool> reach(n);
        dfs(reach, t);
        for (int i = 0; i < n; ++ i) {
            child[i].clear();
        }
        for (int i = 0; i < n; ++ i) {
            if (i == t) {
                continue;
            }
            int par = i;
            for (auto v : g[i]) {
                if (reach[v]) {
                    par = v;
                    break;
                }
            }
            if (par != i) {
                child[par].push_back(i);
            }
        }
        solve(t, t);
    }
    for (int i = 0; i < q; ++ i) {
        printf("%d\n", result[i]);
    }
}