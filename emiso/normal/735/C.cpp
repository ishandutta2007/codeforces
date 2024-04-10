#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

ll s(ll a) {
    return a * (a+1) / 2;
}

ll fib[1000100];

int main() {
    ll n;
    int ans = 0;
    scanf("%lld",&n);
    n--;

    fib[0] = 1;
    fib[1] = 1;
    for(int i=2;;i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] > 1000000000000000000LL) break;
    }

    while(1) {
        if(n < fib[ans]) break;
        n -= fib[ans++];
    }

    printf("%d\n", ans);
    return 0;
}