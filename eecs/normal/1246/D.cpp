#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, cnt, fa[maxn], dep[maxn];
bool mark[maxn];
vector<int> V, op, G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]), fa[i]++;
        G[fa[i]].push_back(i);
        dep[i] = dep[fa[i]] + 1;
    }
    int x = max_element(dep + 1, dep + n + 1) - dep;
    while (x) mark[x] = 1, x = fa[x];
    function<void(int)> dfs = [&](int u) {
        V.push_back(u);
        while (cnt) op.push_back(u), cnt--;
        int son = 0;
        for (int v : G[u]) {
            if (mark[v]) son = v;
            else dfs(v);
        }
        if (son) dfs(son);
        cnt++;
    };
    dfs(1);
    for (int x : V) printf("%d ", x - 1);
    printf("\n%d\n", op.size());
    for (int x : op) printf("%d ", x - 1);
    return 0;
}