#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans;

int main() {
    scanf("%lld", &n);

    while(n) {
        ll x = n % 10;
        if(x < 9 && n >= 10) {
            ans += 10 + x;
            n -= 10;
        } else {
            ans += x;
        }
        n /= 10;
    }

    printf("%lld\n", ans);
    return 0;
}