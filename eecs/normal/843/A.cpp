#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], b[maxn], vis[maxn];
vector<vector<int>> ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), b[i] = i;
    }
    sort(b + 1, b + n + 1, [&](int x, int y) { return a[x] < a[y]; });
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vector<int> V;
        for (int j = i; !vis[j]; vis[j] = 1, j = b[j]) V.push_back(j);
        ans.push_back(V);
    }
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d", p.size());
        for (auto q : p) printf(" %d", q);
        putchar('\n');
    }
    return 0;
}