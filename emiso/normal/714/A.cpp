#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int main() {
    long long l1,r1,l2,r2,k;
    long long r3,l3;
    scanf("%lld %lld %lld %lld %lld",&l1,&r1,&l2,&r2,&k);

    l3 = max(l1,l2);
    r3 = min(r1,r2);

    if(l3 > r3) printf("0\n");
    else {
        if(k >= l3 && k <= r3) printf("%lld\n",r3 - l3);
        else printf("%lld\n", r3 - l3 + 1);
    }
    return 0;
}