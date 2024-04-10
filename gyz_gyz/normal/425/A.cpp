#include<cstdio>
#include<cstring>
#define INF 200000000
using namespace std;
int n,k,o,u,ans,l,i,j,tem,flag1,flag2,mi,ma;
int a[210];
bool v1[210],v2[210];
int main()
{
 scanf("%d%d",&n,&k);ans=-INF;
 for (i=1;i<=n;i++)scanf("%d",&a[i]);
 for (i=1;i<=n;i++)
  for (j=i;j<=n;j++)
          {
tem=0;memset(v1,false,sizeof(v1));memset(v2,false,sizeof(v2));
for (l=i;l<=j;l++)tem+=a[l];
for (o=1;o<=k;o++){
    ma=flag1=0;
    for (u=1;u<=n;u++)if (u<i||u>j)
           if (ma<a[u]&&(!v1[u])){ma=a[u];flag1=u;}
    mi=flag2=INF;
    for (u=1;u<=n;u++)if (u>=i&&u<=j)
           if (mi>a[u]&&(!v2[u])){mi=a[u];flag2=u;}
    if ((!flag1)||(flag2==INF))break;
    if (a[flag1]<a[flag2])break;
    tem=tem+a[flag1]-a[flag2];v1[flag1]=true;v2[flag2]=true;
                  }if (tem>ans)ans=tem;
          }
printf("%d\n",ans);
return 0;
}