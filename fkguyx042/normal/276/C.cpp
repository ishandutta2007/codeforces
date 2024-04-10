#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,y;
int Tree[200001],a[200001],Q[200001];
long long ans;
int lowbit(int x) { return x&-x;}
void add(int x,int y)
 { for (;x<=n;x+=lowbit(x)) Tree[x]+=y; }
int ask(int x)
{ int sum=0; for (;x;x-=lowbit(x)) sum+=Tree[x]; return sum; }
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=m;i++)
  { scanf("%d%d",&x,&y);
    add(x,1); add(y+1,-1);
  }
  for (i=1;i<=n;i++)
  {  Q[i]=ask(i); }
sort(a+1,a+n+1);
sort(Q+1,Q+n+1);
for (i=1;i<=n;i++)
 ans+=1ll*Q[i]*a[i];
printf("%I64d\n",ans);
}