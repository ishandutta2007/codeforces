#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[300005],pre[300005],ans1[300005],ans2[300005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            pre[i]=ans1[i]=0;
            ans2[i]=1e9;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ans1[a[i]]=max(ans1[a[i]],i-pre[a[i]]);
            pre[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            ans1[i]=max(ans1[i],n-pre[i]+1);
//            printf("ans1[%d]=%d\n",i,ans1[i]);
        }
        for(int i=1;i<=n;i++)
        {
            ans2[ans1[i]]=min(ans2[ans1[i]],i);
        }
        for(int i=1;i<=n;i++)
        {
            ans2[i]=min(ans2[i],ans2[i-1]);
            if(ans2[i]==1e9) printf("-1 ");
            else printf("%d ",ans2[i]);
        }
    }
}