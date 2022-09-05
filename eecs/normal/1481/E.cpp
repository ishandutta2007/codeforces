#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, a[maxn], pre[maxn], f[maxn], cnt[maxn];
vector<int> col[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), col[a[i]].push_back(i);
    }
    memset(pre, -1, sizeof(pre));
    for (int i = 1; i <= n; i++) if (!col[i].empty()) {
        pre[col[i].back()] = col[i][0] - 1;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], !~pre[i] ? 0 : (f[pre[i]] + (int)col[a[i]].size()));
    }
    int ans = f[n];
    for (int i = n, mx = 0; i; i--) {
        mx = max(mx, ++cnt[a[i]]);
        ans = max(ans, mx + f[i - 1]);
    }
    printf("%d\n", n - ans);
    return 0;
}