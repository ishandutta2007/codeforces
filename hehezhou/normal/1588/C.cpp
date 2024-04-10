#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
ll a[300010];
ll sum[300010];
int sta[300010];
ll k[300010];
int r[300010], id[300010];
int top;
inline void solve(ll *a, int *r, int n, int tag) {
    // for (int i = 1; i <= n; i++) cerr << a[i] << " \n"[i == n];
    top = 0;
    sta[0] = n + 1;
    k[0] = -LLONG_MAX;
    for (int i = n, j = n; i >= 0; i--) {
        // for (int j = 0; j <= top; j++) cerr << sta[j] << " \n"[j == top];
        // cerr << lower_bound(k, k + top + 1, a[i]) - k - 1 << endl;
        r[i] = min(r[i], sta[lower_bound(k, k + top + 1, a[i]) - k - 1] - 1);
        if ((i & 1) == tag) {
            while (top && a[sta[top]] >= a[i]) top--;
            sta[++top] = i;
            k[top] = a[i];
        }
    }
    
}
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), r[i] = n;
    r[0] = n;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1];
        if (i & 1) sum[i] += a[i];
        else sum[i] -= a[i];
    }
    solve(sum, r, n, 1);
    // for (int i = 0; i <= n; i++) cerr << r[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) sum[i] = -sum[i];
    solve(sum, r, n, 0);
    // for (int i = 0; i <= n; i++) cerr << r[i] << " \n"[i == n];
    for (int i = 0; i <= n; i++) id[i] = i;
    sort(id, id + 1 + n, [](int a, int b) {
        return sum[a] == sum[b] ? a < b : sum[a] < sum[b];
    });
    ll ans = 0;
    for (int l = 0, r; l <= n; l = r + 1) {
        for (r = l; r < n && sum[id[r + 1]] == sum[id[l]]; r++);
        for (int i = l; i <= r; i++) {
            // cerr << id[i] << ' ' << ::r[id[i]] << ' ' << sum[id[i]] << endl;
            int curr = ::r[id[i]];
            int pos = upper_bound(id + l, id + r + 1, curr) - id - 1;
            ans += pos - i;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}