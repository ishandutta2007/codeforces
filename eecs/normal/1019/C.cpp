#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, mark[maxn];
vector<int> ans, G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    for (int i = n; i; i--) if (!mark[i]) {
        for (int j : G[i]) if (i > j) mark[j] = 1;
    }
    for (int i = 1; i <= n; i++) if (!mark[i]) {
        mark[i] = 1, ans.push_back(i);
        for (int j : G[i]) mark[j] = 1;
    }
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    return 0;
}