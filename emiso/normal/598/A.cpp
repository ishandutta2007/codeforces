#include <stdio.h>

typedef long long ll;
ll t,n;
ll s,x,m;

ll next2(ll a) {
    a |= a>>1;
    a |= a>>2;
    a |= a>>4;
    a |= a>>8;
    a |= a>>16;
    a |= a>>32;
    a++;
    return a;
}

int main() {
    scanf("%I64d",&t);
    while(t--) {
        s = 0,x=0,m=1;
        scanf("%I64d",&n);
        s = n*(n+1)/2;
        x = next2(n) - 1;
        printf("%I64d\n",s-2*x);
    }
    return 0;
}