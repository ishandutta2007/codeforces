#include<cstdio>
#include<algorithm>
using namespace std;
int t;
long long n,fac[20];
int BitCount(long long x)
{
    int res=0;
    while(x)
    {
        res+=(x&1);
        x>>=1;
    }
    return res;
}
int main()
{
    fac[0]=1;
    for(int i=1;i<=15;i++) fac[i]=fac[i-1]*i;
    int tot=(1<<16);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        int ans=1000;
        for(int i=0;i<tot;i++)
        {
            long long tmp=0;
            int cnt=0;
            for(int j=0;j<=15;j++)
            {
                if(i & (1<<j)) 
                {
                    tmp+=fac[j];
                    cnt++;
                }
            }
            if(tmp<=n) ans=min(ans,BitCount(n-tmp) + cnt);
        }
        printf("%d\n",ans);
    }
}