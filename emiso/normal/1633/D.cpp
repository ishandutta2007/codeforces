#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, k, ans, b[MN], c[MN], cost[2010], dp[1000100];

int main() {
    memset(cost, 0x7f, sizeof cost);
    cost[1] = 0;
    queue<int> fila({1});
    while (!fila.empty()) {
        int u = fila.front(); fila.pop();
        for (int x = 1; x <= u; x++) {
            int nu = u + u/x;
            if (nu <= 1000 && cost[nu] > cost[u] + 1) {
                cost[nu] = cost[u] + 1;
                fila.push(nu);
            }
        }
    }

    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }

    k = min(k, 20*n);
    
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++)
        for (int co = k; co >= cost[b[i]]; co--)
            dp[co] = max(dp[co], dp[co-cost[b[i]]] + c[i]);

    printf("%lld\n", dp[k]);
    if(--t) goto st;
    return 0;
}