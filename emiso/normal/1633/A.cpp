#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    if (n % 7 == 0) printf("%lld\n", n);
    else for (int i = 0; i <= 9; i++) {
        ll x = n / 10 * 10 + i;
        if (x % 7 == 0) {
            printf("%lld\n", x);
            break;
        }
    }
    if(--t) goto st;
    return 0;
}