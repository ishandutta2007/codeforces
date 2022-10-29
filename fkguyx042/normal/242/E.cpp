#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,l,r,x,kth;
struct Node{int sum,add;}Tree[32][400001];
int b[32];
void down(int Now,int t,int m)
{  if (!Tree[Now][t].add) return;
   Tree[Now][ls].sum=(m-(m>>1))-Tree[Now][ls].sum;
   Tree[Now][rs].sum=(m>>1)-Tree[Now][rs].sum;
   Tree[Now][ls].add=(Tree[Now][ls].add+1)%2;
   Tree[Now][rs].add=(Tree[Now][rs].add+1)%2;
   Tree[Now][t].add=0;
}
void change(int ll,int rr,int l,int r,int t,int Now)
{  if (ll<=l&&r<=rr) {  Tree[Now][t].sum=(r-l+1)-Tree[Now][t].sum; 
   Tree[Now][t].add=(Tree[Now][t].add+1)%2;  return;}
   down(Now,t,r-l+1);
   if (ll<=mid) change(ll,rr,l,mid,ls,Now);
   if (rr>mid) change(ll,rr,mid+1,r,rs,Now);
   Tree[Now][t].sum=(Tree[Now][ls].sum+Tree[Now][rs].sum);
}
void update(int ll,int l,int r,int t,int Now)
{ if (l==r) { Tree[Now][t].sum++; return; }
if (ll<=mid) update(ll,l,mid,ls,Now);
else update(ll,mid+1,r,rs,Now);
Tree[Now][t].sum=(Tree[Now][ls].sum+Tree[Now][rs].sum);
}
void Query(int ll,int rr,int l,int r,int t,int Now)
{  if (ll<=l&&r<=rr) { kth+=Tree[Now][t].sum; return; }
  down(Now,t,r-l+1);
   if (ll<=mid) Query(ll,rr,l,mid,ls,Now);
   if (rr>mid) Query(ll,rr,mid+1,r,rs,Now);
}
void ask(int l,int r)
{ int sum=1,i;  long long ans=0;
      for (i=1;i<=30;i++)
     { kth=0; Query(l,r,1,n,1,i); ans=(ans+1ll*kth*sum);
        sum*=2;
     }
    printf("%I64d\n",ans);
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
  {  scanf("%d",&p); k=0;
     for (;p;p>>=1)
     {++k;  if (p&1) update(i,1,n,1,k); }
  }
  scanf("%d",&m);
  for (i=1;i<=m;i++) 
  { scanf("%d",&p);
     if (p==1) { scanf("%d%d",&l,&r); ask(l,r); }
     else {  scanf("%d%d%d",&l,&r,&x); k=0; 
       for (;x;x>>=1)
       { ++k; if (x&1) change(l,r,1,n,1,k); }
      }
      }
}