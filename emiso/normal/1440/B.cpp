#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    ans = 0;
    for(int i = 0; i < n*k; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = n*k-1, z = 0; i >= 0, z < k; z++) {
        for(int j = 0; j <= n/2; j++, i--) {
            if(j == n/2) ans += a[i];
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}