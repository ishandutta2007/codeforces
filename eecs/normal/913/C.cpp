#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;
int n, L;
long long ans, res = 1e18, c[maxn], s[maxn];

int main() {
    scanf("%d %d", &n, &L);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        if (i > 1) c[i] = min(c[i], c[i - 1] << 1);
    }
    for (int i = n + 1; i <= 30; i++) {
        c[i] = c[i - 1] << 1;
    }
    for (int i = 1; i <= 30; i++) {
        s[i] = s[i - 1];
        if (L >> (i - 1) & 1) s[i] += c[i];
    }
    for (int i = 30; i; i--) {
        ans += s[i] - s[i - 1];
        if (c[i] <= s[i - 1]) {
            res = min(res, ans + c[i]);
        }
    }
    printf("%lld\n", min(res, ans));
    return 0;
}