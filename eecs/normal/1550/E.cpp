#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, f[1 << 17], nxt[17][maxn];
char s[maxn];

int main() {
    scanf("%d %d %s", &n, &K, s + 1);
    auto chk = [&](int x) {
        memset(nxt, 0x3f, sizeof(nxt));
        for (int i = 0; i < K; i++) {
            int cur = 0, lst = -1;
            for (int j = n; j; j--) {
                if (s[j] == '?' || s[j] == i + 'a') cur++;
                if (j + x <= n && (s[j + x] == '?' || s[j + x] == i + 'a')) cur--;
                if (cur == x) lst = j;
                if (~lst) nxt[i][j] = lst;
            }
        }
        memset(f, 0x3f, sizeof(f)), f[0] = 0;
        for (int i = 1; i < 1 << K; i++) {
            for (int j = 0; j < K; j++) if (i >> j & 1) {
                int t = f[i ^ (1 << j)];
                if (t < n && nxt[j][t + 1] <= n) f[i] = min(f[i], nxt[j][t + 1]);
            }
            f[i] += x - 1;
        }
        return f[(1 << K) - 1] <= n;
    };
    int l = 0, r = n / K, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}