#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m[maxn], t[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m[i]);
        t[i] = max(t[i - 1], m[i] + 1);
    }
    long long ans = 0;
    for (int i = n; i; i--) {
        if (t[i + 1] - 1 > t[i]) t[i] = t[i + 1] - 1;
        ans += t[i] - m[i] - 1;
    }
    printf("%lld\n", ans);
    return 0;
}