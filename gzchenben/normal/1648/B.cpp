#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,c;
int a[1000005];
int cnt[2000005],sum[2000005];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&c);
        for(int i=1;i<=2*c;i++) cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        for(int i=1;i<=2*c;i++)
        {
            sum[i]=sum[i-1]+cnt[i];
        }
        bool flag=true;
        for(int i=1;i<=c;i++)
        {
            if(!cnt[i]) continue;
            for(int j=1;i*j<=c;j++)
            {
                if(cnt[j]) continue;
                if(sum[i*j-1]!=sum[i*(j+1)-1]) flag=false;
            }
        }
        printf(flag ? "Yes\n" : "No\n");
    }
}