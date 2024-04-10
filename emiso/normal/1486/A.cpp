#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ll sum = 0, ans = 1;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        if(sum < (i * (i - 1) / 2)) ans = 0;
    }

    puts(ans ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}