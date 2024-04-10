#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,s;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&s);
        int t=n,sm=0,q=1,ans=0;
        while(t)
        {
            sm+=t%10;
            t/=10;
        }
        while(sm>s)
        {
            ans+=q*(10-n%10);
            n+=10-n%10;
            sm=0;
            while(n%10==0)
            {
                n/=10;
                q*=10;
            }
            t=n;
            while(t)
            {
                sm+=t%10;
                t/=10;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}