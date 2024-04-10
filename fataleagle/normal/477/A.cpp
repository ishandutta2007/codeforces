#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
long long a, b;

int main()
{
    scanf("%lld%lld", &a, &b);
    long long tmp=((b*(b-1))/2)%MOD;
    long long ans=a;
    for(int j=1; j<=a; j++)
        ans=(ans+b*j%MOD)%MOD;
    printf("%lld\n", ans*tmp%MOD);
    return 0;
}