#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN], sz[MN], sum[MN];

int main() {
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a, a + n, greater<ll>());

    ll tmp = 0, ss = 0, i = 0;
    for(; i < n && a[i] >= 0; i++) {
        ans += tmp;
        tmp += a[i];
    }

    priority_queue<ll> pq; pq.push(tmp);
    for(int j = 1; j <= k; j++) pq.push({0});
    for(; i < n; i++) {
        ll best = pq.top();
        pq.pop();
        ans += best;
        pq.push(best + a[i]);
    }

    //if(k >= n) ans = 0;
    printf("%lld\n", ans);
    return 0;
}