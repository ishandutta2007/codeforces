#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, ans, a[maxn];
vector<int> G[maxn];

void dfs(int v, int d) {
    a[d] ^= 1;
    for (int u : G[v]) dfs(u, d + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 2, p; i <= n; i++) {
        scanf("%d", &p), G[p].push_back(i);
    }
    dfs(1, 1);
    printf("%d\n", accumulate(a + 1, a + n + 1, 0));
    return 0;
}