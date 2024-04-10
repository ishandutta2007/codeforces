#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k;
int Tree[1000001],a[100001],ans,x,R[1000001],vis[1000001];
int lowbit(int x){ return x&-x;}
int ask(int x)
{ int sum=0;
   for (;x;x-=lowbit(x)) (sum+=Tree[x])%=Mo; return sum; }
int power(int x,int y)
{ int sum=1;
  for (;y;y>>=1)
  {   if (y&1) sum=1ll*sum*x%Mo; 
      x=1ll*x*x%Mo;
}
return sum;
}
void update(int x,int y)
{
   for (;x<=1000000;x+=lowbit(x)) (Tree[x]+=y)%=Mo; }
int main()
{ scanf("%d",&n);
  for(i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++)
  {    x=1ll*(ask(a[i]))*a[i]%Mo;
       x-=1ll*R[a[i]]*a[i]%Mo;
       x=(x+Mo)%Mo;
       if (!vis[a[i]]) vis[a[i]]=1,(x+=a[i])%=Mo;
             (ans+=x)%=Mo;
       R[a[i]]=ask(a[i]);
       update(a[i],x);
   }
  printf("%d\n",ans);
}