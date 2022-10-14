#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <utility>
#include <vector>

const int N = 200000;

int n, m, a[N], result[N];
std::vector<std::pair<long long, int>> children[N], stack;

void dfs(int u)
{
    auto depth = stack.back().first;
    result[u] ++;
    auto iterator = std::lower_bound(stack.begin(), stack.end(), std::make_pair(depth - a[u], INT_MIN));
    if (iterator != stack.begin()) {
        iterator --;
        result[iterator->second] --;
    }
    for (auto&& iterator : children[u]) {
        auto&& v = iterator.second;
        stack.emplace_back(depth + iterator.first, v);
        dfs(v);
        result[u] += result[v];
    }
    stack.pop_back();
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("B.in", "r", stdin);
#endif
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
            children[i].clear();
        }
        for (int i = 1; i < n; ++ i) {
            int p, w;
            scanf("%d%d", &p, &w);
            p --;
            children[p].emplace_back(w, i);
        }
        memset(result, 0, sizeof(*result) * n);
        stack.emplace_back(0, 0);
        dfs(0);
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", result[i] - 1, " \n"[i == n - 1]);
        }
    }
}