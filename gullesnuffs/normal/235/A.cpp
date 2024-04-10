#include <stdio.h>

using namespace std;

long long gcd(long long a, long long b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int n;
    scanf("%d", &n);
    long long ans=0;
    long long a, b, c;
    for(a=n; a*a*a > ans; --a)
        for(b=a; a*b*b > ans; --b){
            if(a > 1 && b == a)
                --b;
            for(c=b; a*b*c > ans; --c){
                long long lcm;
                lcm=(a*b)/gcd(a, b);
                lcm=(lcm*c)/gcd(lcm, c);
                if(lcm > ans)
                    ans=lcm;
            }
        }
    printf("%I64d", ans);
    return 0;
}