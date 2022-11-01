#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans;

int main() {
    scanf("%lld", &t);
    st:

    ll x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    if(x1 == x2 || y1 == y2) {
        printf("%lld\n", abs(x1 - x2) + abs(y1 - y2));
    } else {
        printf("%lld\n", abs(x1 - x2) + abs(y1 - y2) + 2);
    }

    if(--t) goto st;
    return 0;
}