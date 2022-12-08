#include <iostream>
#include <cstdio>

#include <bitset>

using namespace std;

typedef long long ll;

const int NUMPRIMES = 16500000;
const int MAXN = 303000000;
const int MAXN6 = MAXN/6;
const ll MOD = 1LL<<32;

int A, B, C, D, N, Nd6;

ll ans;
bitset<MAXN6> tp1, tp5;

ll f(ll p) {return (A * ((((p * p)%MOD) * p)%MOD) + B * ((p * p)%MOD) + C * p + D)%MOD;}
void runprime(ll p) {
    ll ap = 0;
    for(int j = N/p;j > 0;j=j/p) ap = (ap + j)%MOD;
    ans = (ans + ap * f(p))%MOD;
    
    if(p%6 == 1) {
        for(ll i = p/6;i <= Nd6;i += p) tp1.set(i, false);
        for(ll i = (p * 5)/6;i <= Nd6;i += p) tp5.set(i, false);
    }
    if(p%6 == 5) {
        for(ll i = (p * 5)/6;i <= Nd6;i += p) tp1.set(i, false);
        for(ll i = p/6;i <= Nd6;i += p) tp5.set(i, false);
    }
}

int main() {
    scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);
    Nd6 = N/6;
    
    ans = 0;
    
    tp1.set();
    tp5.set();
    
    runprime(2);
    runprime(3);
    runprime(5);
    for(int i = 1;i <= Nd6;i++) {
        if(tp1.test(i)) runprime(i * 6 + 1);
        if(tp5.test(i)) runprime(i * 6 + 5);
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}