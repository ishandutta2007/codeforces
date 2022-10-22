#include<cstdio>
using namespace std;
bool cnt[31];
int n,t,a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            for(int j=0;j<30;j++)
            {
                if(a[i] & (1<<j)) cnt[j]=true;
            }
        }
        int ans=0;
        for(int i=0;i<30;i++)
        {
            if(cnt[i]) ans+=(1<<i);
            cnt[i]=false;
        }
        printf("%d\n",ans);
    }
}