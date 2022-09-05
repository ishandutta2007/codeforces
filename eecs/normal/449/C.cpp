#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, mn[maxn];
bool prime[maxn], vis[maxn];
vector<pair<int, int>> ans;

int main() {
    scanf("%d", &n);
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 2; i <= n; i++) if (!prime[i]) {
        for (int j = i + i; j <= n; j += i) prime[j] = 1;
        for (int j = i; j <= n; j += i) mn[j] = min(mn[j], i);
    }
    for (int i = n; i > 1; i--) if (!prime[i]) {
        int lst = 0;
        for (int j = i; j <= n; j += i) if (!vis[j] && mn[j] >= i) {
            if (!lst) lst = j;
            else ans.emplace_back(lst, j), vis[j] = vis[lst] = 1, lst = 0;
        }
        for (int j = i; j <= n; j += i) if (!vis[j] && mn[j] < i) {
            if (!lst) lst = j;
            else ans.emplace_back(lst, j), vis[j] = vis[lst] = 1, lst = 0;
        }
    }
    printf("%d\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}