#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, x, y, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld %lld", &n, &x, &y);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ans += (a[i] % 2);
    }

    if ((x % 2) == (y % 2)) {
        if (ans % 2) puts("Bob");
        else puts("Alice");
    } else {
        if (ans % 2 == 0) puts("Bob");
        else puts("Alice");
    }
    if(--t) goto st;
    return 0;
}