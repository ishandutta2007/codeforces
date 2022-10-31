#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
ll a[755], x, ans[755];

int resp(ll x) {
    int ret = 0;
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++) {
        if(a[i] < 0) pq.push(-a[i]);
        x += a[i];
        while(x < 0) {
            ret++;
            x += pq.top();
            pq.pop();
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

    for(int k = 0; k <= n; k++) {
        ll l = 0, r = 1000000000000000LL, m;
        while(l < r) {
            m = (l + r) / 2;
            if(resp(m) <= k) r = m;
            else l = m + 1;
        }
        ans[k] = l;
    }

    for(int j = 0; j < m; j++) {
        scanf("%lld", &x);

        int resp = 0;
        while(ans[resp] > x) resp++;

        printf("%d\n", resp);
    }
    return 0;
}