#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, k;

int main() {
    scanf("%lld%lld", &n, &k);
    
    ll ans = (k+1)/2 - 1;
    if(n < k-1) ans -= (k-1 - n);
    if(ans < 0) ans = 0;
    printf("%lld\n", ans);
}