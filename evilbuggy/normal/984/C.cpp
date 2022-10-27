#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int n, long long int m){
    if(n == 0 || m == 0)return n+m;
    return gcd(m, n%m);
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        long long int p, q, b;
        scanf("%lld",&p);
        scanf("%lld",&q);
        scanf("%lld",&b);
        p %= q;
        long long int m = gcd(p, q);
        q /= m;
        while(true){
            if(q == 1)break;
            m = gcd(b,q);
            if(m == 1)break;
            while(q%m == 0){
                q /= m;
            }
        }
        if(q == 1){
            printf("Finite\n");
        }else{
            printf("Infinite\n");
        }
    }
}