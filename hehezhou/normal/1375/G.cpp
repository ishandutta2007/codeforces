#include <bits/stdc++.h>
using namespace std;
vector < int > v[200010];
int a[200010], b[200010];
inline void dfs(int now, int fa) {
    for (auto i : v[now]) {
        if (i == fa) continue;
        dfs(i, now);
        if (v[i].size() == 1) a[now]++;
        else a[now] += b[i] + 1, b[now] += a[i] + 1;
    }
    if (a[now]) a[now]--;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        ::v[u].push_back(v);
        ::v[v].push_back(u);
    }
    dfs(1, 0);
    return cout << min(a[1], b[1]) << endl, 0;
}