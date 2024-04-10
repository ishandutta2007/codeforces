#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, ans = INT_MAX, vis[maxn * 5];
array<int, 6> a[maxn];
vector<pair<int, vector<int>>> cand;

int main() {
    scanf("%d %d", &n, &m);
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]), V.push_back(a[i][j]);
        }
        scanf("%d", &a[i][0]);
    }
    sort(a + 1, a + n + 1);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = lower_bound(V.begin(), V.end(), a[i][j]) - V.begin() + 1;
        }
    }
    vector<int> st;
    function<void(int)> dfs = [&](int cur) {
        int p = 0;
        while (p < n) {
            int flag = 0;
            for (int i = 1; i <= m; i++) flag |= vis[a[p + 1][i]];
            if (flag) p++;
            else break;
        }
        if (p) cand.emplace_back(p, st);
        if (p == n || cur == m) return;
        for (int i = 1; i <= m; i++) {
            vis[a[p + 1][i]]++, st.push_back(a[p + 1][i]);
            dfs(cur + 1);
            vis[a[p + 1][i]]--, st.pop_back();
        }
    };
    dfs(0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) vis[a[i][j]]++;
        int mx = 0;
        for (auto &p : cand) {
            bool flag = 1;
            for (int x : p.second) flag &= vis[x];
            if (flag) mx = max(mx, p.first);
        }
        if (mx < n) ans = min(ans, a[i][0] + a[mx + 1][0]);
        for (int j = 1; j <= m; j++) vis[a[i][j]]--;
    }
    printf("%d\n", ans == INT_MAX ? -1 : ans);
    return 0;
}