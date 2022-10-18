#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,sum;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        sum=0;
        for(register int i=1;i<=n;++i)
        {
            int x;
            scanf("%lld",&x);
            sum=(sum+x)%n;
        }
        sum%=n;
        printf("%lld\n",sum*(n-sum));
    }
    return 0;
}