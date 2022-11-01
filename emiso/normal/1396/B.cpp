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

    ll sum = 0, maxi = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        maxi = max(maxi, a[i]);
    }

    if(n == 1) puts("T");
    else if(n == 2) puts((2*maxi > sum) ? "T" : "HL");
    else {
        ll other = sum - maxi;
        if(maxi > other) puts("T");
        else if(maxi == other) puts("HL");
        else puts(((maxi % 2) != (other % 2)) ? "T" : "HL");
    }

    if(--t) goto st;
    return 0;
}