#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    ll sum = 0, maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        maxi = max(maxi, a[i]);
    }

    printf("%.9f\n", maxi + (sum - maxi + 0.0) / (n - 1));
    if(--t) goto st;
    return 0;
}