#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int t,n,m,p[101],ans,sum;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        ans=sum=0;
        for(register int i=1;i<=n;++i)
        {
            scanf("%lld",&p[i]);
            if(i!=1&&p[i]*100>sum*m)//100p[i]=sum*m+p*m,p=(100p[i]-sum*m)/m(ceil)
            {
                ans+=ceil((p[i]*100-sum*m)*1.0/m);
                sum+=ceil((p[i]*100-sum*m)*1.0/m);
            }
            sum+=p[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}