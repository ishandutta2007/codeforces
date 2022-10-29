#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
const int Mo=95542721;
const int R=48;
int i,j,m,n,p,k,l,r,a[100001],v[48],ans;
struct Node{int val[48],add;}Tree[400001];
void up(int t)
{ int i; for (i=0;i<48;i++) Tree[t].val[i]=(Tree[ls].val[i]+Tree[rs].val[i])%Mo; }
void down(int t)
{  if (!Tree[t].add) return; int i;
   Tree[ls].add+=Tree[t].add; Tree[rs].add+=Tree[t].add;
   memcpy(v,Tree[ls].val,sizeof(v));
   for (i=0;i<48;i++)Tree[ls].val[i]=v[(i+Tree[t].add)%R];
   memcpy(v,Tree[rs].val,sizeof(v));
   for (i=0;i<48;i++) Tree[rs].val[i]=v[(i+Tree[t].add)%R];
   Tree[t].add=0;
}
void build_tree(int l,int r,int t)
{  if (l==r)
{  int i;
   Tree[t].val[0]=a[l];
   for (i=1;i<48;i++)
   {  int x=Tree[t].val[i-1];
      Tree[t].val[i]=1ll*x*x%Mo*x%Mo;
   }
}
else { build_tree(l,mid,ls); build_tree(mid+1,r,rs); up(t); }
}
void update(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr){  memcpy(v,Tree[t].val,sizeof(v));Tree[t].add++;
     int i; for (i=0;i<48;i++) Tree[t].val[i]=v[(i+1)%R]; 
 }  else {  down(t);
 	  if (ll<=mid) update(ll,rr,l,mid,ls);
 	  if (rr>mid) update(ll,rr,mid+1,r,rs);
 	  up(t);
 }
}
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr)  ans=(ans+Tree[t].val[0])%Mo; 
else {  down(t);
   if (ll<=mid) ask(ll,rr,l,mid,ls);
   if (rr>mid) ask(ll,rr,mid+1,r,rs);
}
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),a[i]%=Mo; 
  build_tree(1,n,1); scanf("%d",&m);
  for (i=1;i<=m;i++)
{  scanf("%d%d%d",&p,&l,&r);
  if (p==2) update(l,r,1,n,1);
  else { ans=0; ask(l,r,1,n,1);
     printf("%d\n",ans); }
}
}