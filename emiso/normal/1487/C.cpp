#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans[110][110];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);
    memset(ans, 0, sizeof ans);

    for(ll i = 0; i < n; i++) {
        for(int d = 1; i + d < n; d++) {
            if(n % 2 == 0 && d == n / 2) continue;
            if(d <= n / 2) ans[i][i+d] = 1;
            else ans[i][i+d] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++)
            printf("%lld ", ans[i][j]);
    }
    puts("");

    if(--t) goto st;
    return 0;
}