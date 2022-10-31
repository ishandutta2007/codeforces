#include <bits/stdc++.h>
#define MN 100100
#define MK 21

using namespace std;
typedef long long ll;

ll n, K, a[MN], dp[MK][MN], optK[MK][MN], f[MN], cost, l, r = -1;

ll co;


void build(int le, int ri) {
    if(l < le)
    for(int k = l ; k < le; k++) {
        f[a[k]]--;
        cost -= f[a[k]];
    }

    else
    for(int k = l - 1; k >= le; k--) {
        cost += f[a[k]];
        f[a[k]]++;
    }

    if(r < ri)
    for(int k = r + 1; k <= ri; k++) {
        cost += f[a[k]];
        f[a[k]]++;
    }

    else
    for(int k = r; k > ri; k--) {
        f[a[k]]--;
        cost -= f[a[k]];
    }

    l = le;
    r = ri;
}

ll c(ll l, ll r) {
    if(l > r) return 999999999;
    build(l, r);
    return cost;
}

void limpa(int l, int r) {
    for(int i = l; i <= r; i++)
        f[a[i]] = 0;
    cost = 0;
    l = r + 1;
}

void calc(int d, int l, int r) {
    if(l > r) return;

    int m = (l + r) / 2;
    int L = optK[d][l-1];
    int R = optK[d][r+1];

    for(int k=L; k<=min(R, m); k++) {
        ll co = c(k+1, m);
        if(dp[d][m] > dp[d-1][k] + co) {
            dp[d][m] = dp[d-1][k] + co;
            optK[d][m] = k;
        }
    }

    calc(d, l, m-1);
    calc(d, m+1, r);
}

int main() {
    scanf("%lld %lld", &n, &K);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int d=0; d<MK; d++)
        for(int i=0; i<MN; i++)
            dp[d][i] = 9999999999999999;
    dp[0][0] = 0;

    for(int d=1; d<=K; d++) {
        optK[d][0] = 0;
        optK[d][n+1] = n;
        calc(d, 1, n);
    }

    printf("%lld\n", dp[K][n]);

    return 0;
}