#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long dis[2001][2001],ans=0;
int size[2001],n,k,i,j;
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
    for (j=i+1;j<=n;j++)
    {  scanf("%I64d",&dis[i][j]);
       if (dis[i][j]!=-1) size[i]++,size[j]++,ans+=2ll*dis[i][j];
       dis[j][i]=dis[i][j];
    }
  if (k!=2) printf("%I64d\n",ans/n);
  else { ans=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
       if (i!=j&&dis[i][j]!=-1)
        ans+=1ll*dis[i][j]*(size[i]-1);
    printf("%I64d\n",ans*2ll/(1ll*n*(n-1)));
}
}