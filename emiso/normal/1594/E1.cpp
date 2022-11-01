#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

ll t = 1, n, a[MN];
//char s[MN]; string str;

typedef long long ll;
#define MOD 1'000'000'007

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

int main() {
    scanf("%lld", &n);
    printf("%lld\n", 6LL * expo(4, (1LL << n) - 2) % MOD);
    return 0;
}