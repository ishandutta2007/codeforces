#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[200005];
bool flag[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a[0]=a[n+1]=1e9+1;
        for(int i=1;i<=n+2;i++) flag[i]=false;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1]) flag[i]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!flag[i]) continue;
            if(flag[i+2])
            {
                ans++;
                a[i+1]=max(a[i],a[i+2]);
                i+=2;
            } 
            else
            {
                ans++;
                a[i]=max(a[i-1],a[i+1]);
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
    }
}