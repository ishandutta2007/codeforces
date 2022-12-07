#include<cstdio>
using namespace std;
int n,t,a[400005],b[400005],Reva[400005],Revb[400005];
bool vis[400005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=n;i++)
        {
            Revb[a[i]]=b[i];
            Reva[b[i]]=i;
            vis[i]=false;
        }
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                ans=ans*2%(1000000007);
                vis[i]=true;
                int x=i;
                while(Revb[x]!=i)
                {
                    x=Revb[x];
                    vis[x]=true;
                }
            }
        }
        printf("%d\n",ans);
    }
}