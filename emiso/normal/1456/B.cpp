#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], xo[MN];

int main() {
    scanf("%lld", &n);
    if(n > 200) puts("1");
    else {
        ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            xo[i] = xo[i-1] ^ a[i];
        }

        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                for(int k = i; k + 1 <= j; k++)
                    if((xo[k] ^ xo[i-1]) > (xo[j] ^ xo[k]))
                        ans = min(ans, (j-i-1LL));

        if(ans == INT_MAX) puts("-1");
        else printf("%lld\n", ans);
    }
    return 0;
}