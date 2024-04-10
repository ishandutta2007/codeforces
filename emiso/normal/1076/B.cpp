#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];

int main() {
    scanf("%lld", &n);

    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ans++;
            n -= i;
            break;
        }
    }

    if(ans == 0) {
        printf("1\n");
    } else {
        ans += (n / 2);
        printf("%lld\n", ans);    
    }
    return 0;
}