#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, L, R, c[maxn], cnt1[maxn], cnt2[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &L, &R);
        fill(cnt1 + 1, cnt1 + n + 1, 0);
        fill(cnt2 + 1, cnt2 + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
            if (i <= L) cnt1[c[i]]++;
            else cnt2[c[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int t = min(cnt1[i], cnt2[i]);
            cnt1[i] -= t, cnt2[i] -= t;
        }
        int s1 = 0, s2 = 0;
        int s1_l = 0, s1_r = 0;
        int s2_l = 0, s2_r = 0;
        for (int i = 1; i <= n; i++) {
            s1_l += cnt1[i] % 2, s1_r += cnt1[i];
            s2_l += cnt2[i] % 2, s2_r += cnt2[i];
        }
        if (max(s1_l, s2_l) <= min(s1_r, s2_r)) {
            ans += (s1_r + s2_r) / 2;
        } else if (s1_r < s2_l) {
            ans += s1_r + s2_l - s1_r + (s2_r - s2_l) / 2;
        } else { // s1_l > s2_r
            ans += s2_r + s1_l - s2_r + (s1_r - s1_l) / 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}