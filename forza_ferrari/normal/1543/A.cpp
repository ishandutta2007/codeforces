#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int t,a,b;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a==b)
            printf("0 0\n");
        else
            printf("%lld %lld\n",abs(a-b),min(a%abs(a-b),abs(a-b)-a%abs(a-b)));
    }
    return 0;
}