#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, a[maxn];
long long ans;
priority_queue<long long> Q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), Q.push(a[i]);
    }
    while (Q.size() > 1) {
        long long x = Q.top(); Q.pop();
        long long y = Q.top(); Q.pop();
        Q.push(x + y), ans += x + y;
    }
    printf("%lld\n", ans + Q.top());
    return 0;
}