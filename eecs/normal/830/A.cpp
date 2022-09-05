#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, K, p, a[maxn], b[maxn];

int main() {
    scanf("%d %d %d", &n, &K, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= K; i++) {
        scanf("%d", &b[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + K + 1);
    int ans = INT_MAX;
    for (int i = 1; i + n - 1 <= K; i++) {
        int mx = 0;
        for (int j = i; j <= i + n - 1; j++) {
            mx = max(mx, abs(a[j - i + 1] - b[j]) + abs(b[j] - p));
        }
        ans = min(ans, mx);
    }
    printf("%d\n", ans);
    return 0;
}