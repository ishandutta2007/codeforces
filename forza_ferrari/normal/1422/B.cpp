#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int t,n,m,a[101][101];
long long ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
                scanf("%d",&a[i][j]);
        for(register int i=1;i<=(n>>1);++i)
            for(register int j=1;j<=(m>>1);++j)
            {
                int b[5]={0};
                b[1]=a[i][j];
                b[2]=a[n-i+1][j];
                b[3]=a[i][m-j+1];
                b[4]=a[n-i+1][m-j+1];
                sort(b+1,b+5);
                ans+=b[2]-b[1]+b[3]-b[2]+b[4]-b[2];
            }
        if(n&1)
            for(register int j=1;j<=(m>>1);++j)
                ans+=abs(a[(n>>1)+1][j]-a[(n>>1)+1][m-j+1]);
        if(m&1)
            for(register int i=1;i<=(n>>1);++i)
                ans+=abs(a[i][(m>>1)+1]-a[n-i+1][(m>>1)+1]);
        printf("%lld\n",ans);
    }
    return 0;
}