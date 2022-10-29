#include<cstdio>
#include<algorithm>
#include<cstring>
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,a[2000001],Q;
long long f[41][2],ans;
void dfs(int l,int r,int dep)
{  if (l==r) return;
   dfs(l,mid,dep-1);dfs(mid+1,r,dep-1);
   int i;
   for (i=l;i<=mid;i++) {
   f[dep][0]+=lower_bound(a+mid+1,a+r+1,a[i])-(a+mid+1),
   f[dep][1]+=r-mid-(upper_bound(a+mid+1,a+r+1,a[i])-(a+mid+1)); }
   sort(a+l,a+r+1);
} 
int main()
{ 
  scanf("%d",&n); 
  int Maxn=1<<n;
  for (i=1;i<=Maxn;i++) scanf("%d",&a[i]);
  dfs(1,Maxn,n);
  scanf("%d",&Q);
  for (;Q--;)
  { scanf("%d",&k); ans=0;
    for (i=1;i<=k;i++) swap(f[i][0],f[i][1]);
    for (i=0;i<=20;i++) ans+=f[i][0];
    printf("%I64d\n",ans);
}
}