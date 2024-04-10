#include<bits/stdc++.h>
using namespace std;

long long n, k, a, b;

long long gcd(int x, int y)
{
    if(x==0) return y;
    return gcd(y%x, x);
}

int main()
{
    scanf("%lld%lld", &n, &k);

    scanf("%lld%lld", &a, &b);

    long long  Max=1;
    long long Min=n*k;
    long long  diff1 = a-b+k;
    long long  diff2 = a+b;

    for(int i=1; i<=n; i++)
    {
        Max = max(Max, gcd(n*k, diff1));
        Min = min(Min, gcd(n*k, diff1));
        Max = max(Max, gcd(n*k, diff2));
        Min = min(Min, gcd(n*k, diff2));

        diff1+=k;
        diff2+=k;
    }

    printf("%lld %lld", n*k/Max, n*k/Min);
}