#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
double ans,f[100001],g[100001];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%lf",&g[i]),ans-=g[i];
  for (i=1;i<=n;i++)
  {  f[i]=f[i-1]*g[i]+g[i];
     ans+=f[i]*2;
}
printf("%.7lf\n",ans);
}