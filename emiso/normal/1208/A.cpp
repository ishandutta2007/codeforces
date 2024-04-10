#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, x, a, b;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &a, &b, &x);
        if(x % 3 == 0) printf("%lld\n", a);
        else if(x % 3 == 1) printf("%lld\n", b);
        else printf("%lld\n", a ^ b);
    }

    return 0;
}