#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
int a[300010];
int dp[300010];
ll ans;
struct node {
    int ls, rs, key;
} t[300010 * 20];
int rt[300010], tot;
void add(int &x, int l, int r, int k, int v) {
    if (x == 0) x = ++tot, t[x].ls = t[x].rs = 0;
    if (l == r) return t[x].key = v, void();
    int mid = l + r >> 1;
    if (k <= mid) add(t[x].ls, l, mid, k, v);
    else add(t[x].rs, mid + 1, r, k, v);
}
int query(int x, int l, int r, int k) {
    if (x == 0) return 0;
    if (l == r) return t[x].key;
    int mid = l + r >> 1;
    if (k <= mid) return query(t[x].ls, l, mid, k);
    return query(t[x].rs, mid + 1, r, k);
}
void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    ans = tot = 0;
    for (int i = 1; i <= n; i++) {
        int qwq = query(rt[i - 1], 1, n, a[i]);
        if (qwq != 0) dp[i] = dp[qwq - 1] + 1, rt[i] = rt[qwq - 1];
        else rt[i] = 0, dp[i] = 0;
        add(rt[i], 1, n, a[i], i);
        ans += dp[i];
    }
    printf("%lld\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}