#include<cstdio>
#include<algorithm>
using namespace std;
long long t,p,q;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&p,&q);
        long long ans=1e18;
        for(long long i=2;i*i<=q;i++)
        {
            if(q%i!=0) continue;
            long long tmp1=1,tmp2=1,tmp3=p;
            while(q%i==0)
            {
                q/=i;   
                tmp1*=i;
            }
            while(tmp3%tmp1==0)
            {
                tmp3/=i;
                tmp2*=i;
            }
            ans=min(ans,tmp2);
        }
        if(q!=1)
        {
            int i=q;
            if(q%i!=0) continue;
            long long tmp1=1,tmp2=1,tmp3=p;
            while(q%i==0)
            {
                q/=i;   
                tmp1*=i;
            }
            while(tmp3%tmp1==0)
            {
                tmp3/=i;
                tmp2*=i;
            }
            ans=min(ans,tmp2);
        }
        printf("%lld\n",p/ans);
    }
}