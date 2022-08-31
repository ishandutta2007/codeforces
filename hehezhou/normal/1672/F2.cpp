#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010], b[200010], cnt[200010];
vector <int> son[200010];
int vis[200010];
int dfs(int cur) {
    if (vis[cur] == 2) return 0;
    vis[cur] = 1;
    for (auto i : son[cur]) {
        if (vis[i] == 1 || dfs(i)) return 1;
    }
    vis[cur] = 2;
    return 0;
}
void rmain() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    int maxpos = 1;
    for (int i = 1; i <= n; i++) if (cnt[i] > cnt[maxpos]) maxpos = i;
    for (int i = 1; i <= n; i++) vis[i] = 0, son[i].clear();
    for (int i = 1; i <= n; i++) if (a[i] != maxpos && b[i] != maxpos) son[a[i]].push_back(b[i]);
    for (int i = 1; i <= n; i++) if (dfs(i)) return cout << "WA\n", void();
    cout << "AC\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) rmain();
}