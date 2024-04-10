#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, K, b, c, a[maxn];
long long ans = LLONG_MAX;

int main() {
    scanf("%d %d %d %d", &n, &K, &b, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), a[i] += 1000000000;
    }
    b = min(b, 5 * c), sort(a + 1, a + n + 1);
    for (int rem = 0; rem < 5; rem++) {
        long long sum = 0;
        priority_queue<long long> Q;
        for (int i = 1; i <= n; i++) {
            long long j = a[i], cost = 0;
            while (j % 5 != rem) j++, cost += c;
            cost -= j / 5 * b;
            if (Q.size() < K) {
                Q.push(cost), sum += cost;
            } else if (Q.top() > cost) {
                sum -= Q.top(), Q.pop();
                Q.push(cost), sum += cost;
            }
            if (Q.size() >= K) ans = min(ans, sum + 1LL * K * (j / 5) * b);
        }
    }
    printf("%lld\n", ans);
    return 0;
}