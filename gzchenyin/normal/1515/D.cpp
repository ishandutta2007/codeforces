#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,t,l,r,a[200005],cntl[200005],cntr[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&l,&r);
        for(int i=1;i<=l;i++)
        {
            scanf("%d",&a[i]);
            cntl[a[i]]++;
        }
        for(int i=1;i<=r;i++)
        {
            scanf("%d",&a[i]);
            cntr[a[i]]++;
        }
        int ans=n/2;
        for(int i=1;i<=n;i++)
        {
            while(cntl[i] && cntr[i])
            {
                cntl[i]--;
                cntr[i]--;
                ans--;
            }
        }
        if(l>=r)
        {
            int dif=(l-r)/2;
            for(int i=1;i<=n;i++)
            {
                while(cntl[i]>=2 && dif)
                {
                    cntl[i]-=2;
                    dif--;
                }
            }
            printf("%d\n",ans+dif);
        }
        else
        {
            int dif=(r-l)/2;
            for(int i=1;i<=n;i++)
            {
                while(cntr[i]>=2 && dif)
                {
                    cntr[i]-=2;
                    dif--;
                }
            }
            printf("%d\n",ans+dif);
        }
        for(int i=1;i<=n;i++) cntl[i]=cntr[i]=0;
    }
}