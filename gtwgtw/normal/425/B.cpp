#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
char map[105][105];
char f[105][105];
long n,m,k;
int main()
{
    scanf("%ld%ld%ld",&n,&m,&k);
    for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
    {
             scanf("%ld",&map[i][j]);
             map[i][j]+=48;
             }
    if(n>m)
    {
           for(long i=1;i<=m;i++)
           for(long j=1;j<=n;j++)
           f[i][j]=map[j][i];
           long tmp=n;n=m;m=tmp;
           }
    else
    {
           for(long i=1;i<=n;i++)
           for(long j=1;j<=m;j++)
           f[i][j]=map[i][j];
           }
    if(n>k)
    {
           long ans=2100000000;
           for(long i=1;i<=n;i++)
           {
                    long reu=0;
                    for(long j=1;j<=n;j++)
                    {
                             long uu=0;
                             for(long s=1;s<=m;s++)
                             if(f[j][s]==f[i][s])uu++;
                             reu+=min(uu,m-uu);
                             }
                    if(reu<ans)ans=reu;
                    }
           if(ans<=k)printf("%ld\n",ans);else printf("-1\n");
           }
    else
    {
           long ans=2100000000;
           for(long i=0;i<=((1<<n)-1);i++)
           {
                    long reu=0;
                    for(long j=1;j<=m;j++)
                    { 
                             long ps=0;
                             for(long s=1;s<=n;s++)
                             {
                              long y=(((1<<(s-1)))&i);
                              if((y>0)&&(f[s][j]=='1'))ps++;
                              else if((y==0)&&(f[s][j]=='0'))ps++;
                              }
                    reu+=min(ps,n-ps);
                    }
           //printf("%ld %ld\n",i,reu);
           if(reu<ans)ans=reu;
           }
           if(ans<=k)printf("%ld\n",ans);else printf("-1\n");
           }
    return 0;
}