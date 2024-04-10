#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, K, a[maxn], f[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    auto chk = [&](int d) {
        for (int i = 1; i <= n; i++) {
            f[i] = 1;
            for (int j = 1; j < i; j++) {
                if (abs(a[i] - a[j]) <= 1LL * d * (i - j)) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return *max_element(f + 1, f + n + 1) >= n - K;
    };
    int l = 0, r = 2e9, ans;
    while (l <= r) {
        int mid = (1LL * l + r) / 2;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}