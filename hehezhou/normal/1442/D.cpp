#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
vector < ll > sum[3010];
int len[3010];
ll ans;
inline void solve(int l, int r, ll *dp) {
    if (l == r) {
        for (int j = 0; j <= len[l] && j <= k; j++) {
            ans = max(ans, sum[l][j] + dp[k - j]);
        }
        return;
    }
    int mid = l + r >> 1;
    ll tmp[3010];
    memcpy(tmp, dp, sizeof tmp);
    for (int i = l; i <= mid; i++) {
        for (int j = k; j >= len[i]; j--) tmp[j] = max(tmp[j], tmp[j - len[i]] + sum[i][len[i]]);
    }
    solve(mid + 1, r, tmp);
    memcpy(tmp, dp, sizeof tmp);
    for (int i = mid + 1; i <= r; i++) {
        for (int j = k; j >= len[i]; j--) tmp[j] = max(tmp[j], tmp[j - len[i]] + sum[i][len[i]]);
    }
    solve(l, mid, tmp);
}
ll qwq[3010];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int len;
        scanf("%d", &len);
        ::len[i] = len;
        sum[i].resize(len + 1);
        sum[i][0] = 0;
        for (int j = 1; j <= len; j++) {
            int a;
            scanf("%d", &a);
            sum[i][j] = sum[i][j - 1] + a;
        }
    }
    solve(1, n, qwq);
    printf("%lld\n", ans);
}