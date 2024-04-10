#include<cstdio>
#include<vector>
using namespace std;
vector<vector<int> > a;
long long cnt[100005],sum[100005];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    a.resize(n+1);
    for(int i=0;i<=n;i++) a[i].resize(m+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans+=i*cnt[a[i][j]]-sum[a[i][j]];
            cnt[a[i][j]]++;
            sum[a[i][j]]+=i;
        }
    }
    for(int i=1;i<=100000;i++) cnt[i]=sum[i]=0;
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            ans+=j*cnt[a[i][j]]-sum[a[i][j]];
            cnt[a[i][j]]++;
            sum[a[i][j]]+=j;
        }
    }
    printf("%lld\n",ans);
}