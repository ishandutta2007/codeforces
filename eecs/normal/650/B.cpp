#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, ans, A, B, T;
char s[maxn];
long long sum[maxn];

int main() {
    scanf("%d %d %d %d %s", &n, &A, &B, &T, s + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + 1 + (s[i] == 'w' ? B : 0);
    }
    for (int i = 1; i <= n; i++) if (sum[i] + 1LL * A * (i - 1) <= T) {
        int l = i + 1, r = n, pos = n + 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long v = sum[i] + sum[n] - sum[mid - 1] + 1LL * A * (i + n -
                mid + min(i - 1, n - mid + 1));
            if (v <= T) r = (pos = mid) - 1;
            else l = mid + 1;
        }
        ans = max(ans, i + n - pos + 1);
    }
    printf("%d\n", ans);
    return 0;
}