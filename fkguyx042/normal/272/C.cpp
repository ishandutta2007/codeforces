#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
struct Node{long long sum,add;}Tree[500001];
int a[100001],i,j,m,n,p,k,w,h;
long long ans;
void down(int t)
{ if (!Tree[t].add) return;
    Tree[ls].add=Tree[rs].add=Tree[ls].sum=Tree[rs].sum=Tree[t].add;
    Tree[t].add=0;
}
void ask(int ll,int rr,int l,int r,int  t)
{ if (ll<=l&&r<=rr) ans=max(ans,Tree[t].sum);
   else {
      down(t);
      if (ll<=mid) ask(ll,rr,l,mid,ls);
      if (rr>mid) ask(ll,rr,mid+1,r,rs);
   }
}
void update(int ll,int rr,long long x,int l,int r,int t)
{ if (ll<=l&&r<=rr) {Tree[t].add=Tree[t].sum=x; return; }
else { down(t);
     if (ll<=mid) update(ll,rr,x,l,mid,ls);
     if (rr>mid)  update(ll,rr,x,mid+1,r,rs);
     Tree[t].sum=max(Tree[ls].sum,Tree[rs].sum);
}
}
void build_tree(int l,int r,int t)
{ if (l==r) Tree[t].sum=a[l];
 else{ build_tree(l,mid,ls),build_tree(mid+1,r,rs);
   Tree[t].sum=max(Tree[ls].sum,Tree[rs].sum); }
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  build_tree(1,n,1); scanf("%d",&m);
  for (i=1;i<=m;i++)
  { scanf("%d%d",&w,&h);
    ans=0; ask(1,w,1,n,1);
    printf("%I64d\n",ans);
    update(1,w,h+ans,1,n,1);
  }
}