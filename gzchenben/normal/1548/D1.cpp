#include<cstdio>
#include<algorithm>
using namespace std;
int n,Px[6005],Py[6005];
long long C[4],ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&Px[i],&Py[i]);
        Px[i]/=2; Py[i]/=2;
        C[(Px[i]%2*2)+Py[i]%2]++;
    }
    for(int i=0;i<4;i++)
    {
        ans+=C[i]*(C[i]-1)*(C[i]-2)/6;
    }
    for(int i=0;i<4;i++)
    {
        ans+=C[i]*(C[i]-1)/2*(n-C[i]);
    }
    printf("%lld\n",ans);
}