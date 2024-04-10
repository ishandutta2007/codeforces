#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,g,a[1000001];
long long ans,sum[2];
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=sum[0]=sum[1]=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            ans+=a[i]>0? a[i]:-a[i];
        }
        cin>>g;
        for(int i=1;i<m;++i)
        {
            int x;
            cin>>x;
            g=gcd(g,x);
        }
        for(int i=1;i<=g;++i)
        {
            int cnt=0,minn=1e9+7;
            for(int j=i;j<=n;j+=g)
            {
                cnt+=a[j]<0;
                minn=min(minn,a[j]>0? a[j]:-a[j]);
            }
            sum[cnt&1]+=minn;
        }
        printf("%lld\n",ans-(min(sum[0],sum[1])<<1));
    }
    return 0;
}