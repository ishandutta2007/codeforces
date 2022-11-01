#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll k, n, ans, a[MN], p[MN], cur[MN];

ll gain(int i) {
    ll nxt = 0, b = a[i] / (p[i] + 1), rem = a[i] % (p[i] + 1);
    nxt = b * b * (p[i] + 1 - rem) + (b + 1) * (b + 1) * rem;
    return cur[i] - nxt;
}

int main() {
    scanf("%lld %lld", &n, &k);

    priority_queue<pair<ll, int>> pq;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        p[i] = 1;
        cur[i] = a[i] * a[i];
        ans += cur[i];
        if(a[i] > p[i]) pq.push({gain(i), i});
    }

    for(int K = n; K < k; K++) {
        auto tt = pq.top(); pq.pop();
        ll g = tt.first, i = tt.second;
        ans -= g;
        p[i]++;
        cur[i] -= g;
        if(a[i] > p[i]) pq.push({gain(i), i});
    }

    printf("%lld\n", ans);
    return 0;
}