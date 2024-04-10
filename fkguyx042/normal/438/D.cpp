#include<cstdio>
#include<algorithm>
#include<cstring>
#define mid ((l+r)>>1)
#define ls (t<<1)
#define rs ((t<<1)+1)
using namespace std;
int i,j,m,n,p,k,L,R,x;
long long ans;
struct node{long long sum,Max;}tree[400001];
long long a[100001];
void update(long long c,int ll,int l,int r,int t)
{  if (l==r) { tree[t].Max=tree[t].sum=c; return;}
   if (ll<=mid) update(c,ll,l,mid,t<<1);
   else update(c,ll,mid+1,r,(t<<1)+1);
   tree[t].Max=max(tree[t<<1].Max,tree[(t<<1)+1].Max);
   tree[t].sum=tree[t<<1].sum+tree[(t<<1)+1].sum;
}
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr){ans+=tree[t].sum; return;}
   if (ll<=mid) ask(ll,rr,l,mid,ls);
   if (rr>mid) ask(ll,rr,mid+1,r,rs);
}
void doit(int ll,int rr,int c,int l,int r,int t)
{ if (tree[t].Max<c) return;
  if (l==r)  { tree[t].Max%=c; tree[t].sum%=c; return;}
   if (ll<=mid) doit(ll,rr,c,l,mid,ls);
   if (rr>mid) doit(ll,rr,c,mid+1,r,rs);
  tree[t].Max=max(tree[ls].Max,tree[rs].Max);
  tree[t].sum=tree[ls].sum+tree[rs].sum;
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
   scanf("%I64d",&a[i]),update(a[i],i,1,n,1);
 for (i=1;i<=m;i++)
 { scanf("%d",&p);
  if (p==1)
   { ans=0;scanf("%d%d",&L,&R); ask(L,R,1,n,1); 
     printf("%I64d\n",ans);
   }
  else if(p==2)
  { scanf("%d%d%d",&L,&R,&x); 
     doit(L,R,x,1,n,1);
  }
  else {
       scanf("%d%d",&x,&p); update((long long)p,x,1,n,1);
       }
}
}