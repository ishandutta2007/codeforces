#include <bits/stdc++.h>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

long long n,h,k,a, p = 0;
long long s = 0;

void smash() {
    if(p < k && p) {
        p = 0;
        s++;
    }
    else {
        long long d = p / k;
        p %= k;
        s += d;
    }
}

int main()
{
    scanf("%lld %lld %lld",&n,&h,&k);
    for(int i=0;i<n;i++) {
        scanf("%lld",&a);
        while(p + a > h) smash();
        if(p + a <= h) p += a;
    }
    while(p) smash();
    printf("%lld\n",s);
    return 0;
}