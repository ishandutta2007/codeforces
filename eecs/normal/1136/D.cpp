#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, ans, p[maxn], a[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v), G[v].push_back(u);
    }
    for (int i = n; i; i--) {
        if (i < n && a[p[i]] == n - i - ans) ans++;
        else for (int j : G[p[i]]) a[j]++;
    }
    printf("%d\n", ans);
    return 0;
}