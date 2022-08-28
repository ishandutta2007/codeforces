#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200010];
void rmain() {
    scanf("%d%d", &n, &k);
    priority_queue <int> pq;
    long long ans = 0;
    for (int i = 1; i <= n; i++) scanf("%d", a + i), ans += a[i];
    for (int i = n; i > k; i--) pq.push(a[i] - n + i);
    for (int i = k; i > 0; i--) {
        pq.push(a[i] - n + i);
        ans -= pq.top() + k - i;
        pq.pop();
    }
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}