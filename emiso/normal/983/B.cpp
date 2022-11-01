#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define MN 5005

using namespace std;
typedef long long ll;

int n, p, q, Q, a[MN], dp[MN][MN], val[MN][MN];

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);

        val[i][i] = a[i];
        dp[i][i] = a[i];
    }

    for(int w = 1; w < n; w++) {
        for(int i = 1; i + w <= n; i++) {
            val[i][i+w] = val[i][i+w-1] ^ val[i+1][i+w];
            dp[i][i+w] = max(val[i][i+w], max(dp[i][i+w-1], dp[i+1][i+w]));
        }
    }

    scanf("%d", &Q);
    while(Q--) {
        scanf("%d %d", &p, &q);
        printf("%d\n", dp[p][q]);
    }

    return 0;
}