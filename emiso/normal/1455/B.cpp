#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ll ans = 0, sum = 0;
    for(int i = 1; sum < n; i++) {
        ans++;
        sum += i;
    }

    if(sum == n + 1) ans++;

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}