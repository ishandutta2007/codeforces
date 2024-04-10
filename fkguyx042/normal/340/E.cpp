#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=1000000007;
int i,j,m,n,p,k,ans;
int vis[100001];
int a[100001],RP[2001],Q[2001];
int power(int x,int y)
{  int sum=1;
   for (;y;y>>=1)
   { if (y&1) sum=1ll*sum*x%Mo;
      x=1ll*x*x%Mo; } return sum;
}
int Go(int a,int b,int c)
{ int sum=1,i;  for (i=b;i>a;i--) sum=1ll*sum*i%Mo;
   //  for (i=2;i<=b-a;i++) sum=1ll*sum*power(i,Mo-2)%Mo;
   if (b-a>=2) sum=1ll*sum*RP[b-a]%Mo;
    // for (i=2;i<=c;i++) sum=1ll*sum*i%Mo;
    if (c>1)
    sum=1ll*sum*Q[c]%Mo;
    return sum;
}  
void doit(int x,int y)
{  for (i=1;i<=x;i++) if (i&1) ans=(ans+Mo-Go(i,x,y-i))%Mo;
  else ans=(ans+Go(i,x,y-i))%Mo;
}
int main()
{ scanf("%d",&n); 
  Q[1]=1; 
  for (i=2;i<=n;i++) Q[i]=1ll*Q[i-1]*i%Mo;
  RP[1]=1;
  for (i=2;i<=n;i++) RP[i]=1ll*RP[i-1]*power(i,Mo-2)%Mo;
  for (i=1;i<=n;i++) {
      scanf("%d",&a[i]);
      if (a[i]==i) { printf("0\n"); return 0; }
      vis[a[i]]++; if (a[i]==-1) p++; }
  for (i=1;i<=n;i++)
   if (a[i]==-1&&vis[i]==0) k++;
   ans=1;
    for (i=1;i<=p;i++) ans=1ll*ans*i%Mo;
  doit(k,p);
  printf("%d\n",ans);
}