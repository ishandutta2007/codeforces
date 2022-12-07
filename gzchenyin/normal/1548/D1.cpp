#include<cstdio>
#include<algorithm>
using namespace std;
int n,Px[6005],Py[6005];
long long cnt[2][2],ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&Px[i],&Py[i]);
        Px[i]/=2; Py[i]/=2;
        cnt[Px[i]%2][Py[i]%2]++;
    }
    for(int i=0;i<=1;i++) for(int j=0;j<=1;j++)
    {
        ans+=cnt[i][j]*(cnt[i][j]-1)*(cnt[i][j]-2)/6;
    }
    for(int i=0;i<=1;i++) for(int j=0;j<=1;j++)
    {
        ans+=cnt[i][j]*(cnt[i][j]-1)/2*(n-cnt[i][j]);
    }
    printf("%lld\n",ans);
}