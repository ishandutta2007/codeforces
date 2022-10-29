#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,tot;
int Tree[1000001];
int a[1000001];
void build_tree(int l,int r,int t,int deep)
{ if (l==r) { Tree[t]=a[l]; return; }
  build_tree(l,mid,ls,deep+1);
  build_tree(mid+1,r,rs,deep+1);
  if ((n-deep)&1) Tree[t]=Tree[ls]|Tree[rs];
  else Tree[t]=Tree[ls]^Tree[rs];
}
void update(int ll,int c,int l,int r,int t,int deep)
{ if (l==r) { Tree[t]=c; return; }
  if (ll<=mid) update(ll,c,l,mid,ls,deep+1);
  else update(ll,c,mid+1,r,rs,deep+1);
  if ((n-deep)&1) Tree[t]=Tree[ls]|Tree[rs];
  else Tree[t]=Tree[ls]^Tree[rs];
}
int main()
{ scanf("%d%d",&n,&m);
  tot=1<<n;
  for (i=1;i<=tot;i++) scanf("%d",&a[i]);
  build_tree(1,tot,1,0);
  for (i=1;i<=m;i++)
  { scanf("%d%d",&p,&k);
    update(p,k,1,tot,1,0);
    printf("%d\n",Tree[1]);
  }
}