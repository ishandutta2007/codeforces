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
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] == k) ans = 1;
    }
    sort(a, a + n);

    ll g = a[1] - a[0];
    for(int i = 2; i < n; i++)
        g = __gcd(g, a[i] - a[i-1]);


    for(int i = 0; i < n; i++)
        ans |= (abs(k - a[i]) % g == 0);

    puts(ans ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}