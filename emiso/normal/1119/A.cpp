#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    if(a[0] != a[n-1]) ans = n-1;
    else {
        for(ll i = 0; i < n; i++) {
            if(a[i] != a[0]) ans = max(ans, i);
            if(a[i] != a[n-1]) ans = max(ans, (n-1)-i);
        }
    }

    printf("%lld\n", ans);
    return 0;
}