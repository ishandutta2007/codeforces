#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
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
        }
        int maxn=0,ans=0;
        for(int i=1;i<=n;i++) 
        {
            maxn=max(maxn,a[i]);
            if(maxn==i) ans++;
        }
        printf("%d\n",ans);
    }
}