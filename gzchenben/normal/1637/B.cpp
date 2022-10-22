#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[105],dp[105];
bool flag[105];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) ans+=i*(n-i+1)*2;
            else ans+=i*(n-i+1);
        }
        printf("%d\n",ans);
    }
}