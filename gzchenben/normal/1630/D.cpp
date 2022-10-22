#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,t,B;
long long a[1000005];
int gcd(int x,int y)
{
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        B=0;
        for(int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            B=gcd(B,x);
        }
        long long ans1=0,ans2=0;
        for(int i=1;i<=B;i++)
        {
            long long Minn=2e9,sum=0,nag=0;
            for(int j=i;j<=n;j+=B)
            {
                if(a[j]<0)
                {
                    nag++;
                    Minn=min(Minn,-a[j]);
                    sum+=(-a[j]);
                }
                if(a[j]>=0)
                {
                    Minn=min(Minn,a[j]);
                    sum+=a[j];
                }
            }
            ans1+=sum;
            if(nag%2==0 && B!=1) ans1-=2*Minn;
        }
        for(int i=1;i<=B;i++)
        {
            long long Minn=2e9,sum=0,nag=0;
            for(int j=i;j<=n;j+=B)
            {
                if(a[j]<0)
                {
                    nag++;
                    Minn=min(Minn,-a[j]);
                    sum+=(-a[j]);
                }
                if(a[j]>=0)
                {
                    Minn=min(Minn,a[j]);
                    sum+=a[j];
                }
            }
            ans2+=sum;
            if(nag%2==1 && B!=1) ans2-=2*Minn;
        }
        printf("%lld\n",max(ans1,ans2));
    }
}