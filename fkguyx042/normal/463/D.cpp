#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[3001],b[3001];
int a[6][3001],i,j,m,n,p,k,flag,ans;
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=k;i++)
    for (j=1;j<=n;j++)
    {  scanf("%d",&p);
       a[i][p]=j;
       if (i==1) b[j]=p;
    }
  for (i=1;i<=n;i++)
  {  f[b[i]]=1; 
    for (j=1;j<=n;j++)
      if (f[j]&&b[i]!=j)
    {   flag=0;
        for (int K=1;K<=k;K++)
          if (a[K][j]>a[K][b[i]])
          {  flag=1; break; }
        if (!flag) f[b[i]]=max(f[b[i]],f[j]+1);
  }
  ans=max(ans,f[b[i]]);
}
  printf("%d\n",ans);
}