#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, K, p[maxn], dep[maxn];
bool mark[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(mark, 0, sizeof(mark));
        scanf("%d %d", &n, &K), dep[1] = 1;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        int id = -1;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &p[i]), G[p[i]].push_back(i);
            dep[i] = dep[p[i]] + 1;
            if (dep[i] == K) id = i;
        }
        if (K == 1) id = 1;
        if (!~id) id = max_element(dep + 1, dep + n + 1) - dep;
        for (int i = id; i; i = p[i]) mark[i] = 1;
        int rem = K - dep[id];
        vector<int> ans;
        function<void(int)> dfs = [&](int v) {
            if (!mark[v]) rem--;
            ans.push_back(v);
            for (int u : G[v]) if (!mark[u] && rem) {
                dfs(u), ans.push_back(v);
            }
            for (int u : G[v]) {
                if (mark[u]) dfs(u);
            }
        };
        dfs(1);
        printf("%d\n", ans.size() - 1);
        for (int x : ans) printf("%d ", x);
        putchar('\n');
    }
    return 0;
}