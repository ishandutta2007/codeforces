#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,type,l,r,x;
long long ans;
struct Node{int sum,all;long long add,Sum;}Tree[400001];
void build_tree(int l,int r,int t)
{  if (l==r) { Tree[t].sum=l; Tree[t].all=1; return; }
   build_tree(l,mid,ls);
   build_tree(mid+1,r,rs);
    Tree[t].sum=Tree[ls].sum;
}
void down(int t,int m)
{  if (!Tree[t].add) return;
   Tree[ls].add+=Tree[t].add;
   Tree[rs].add+=Tree[t].add;
   Tree[ls].sum=Tree[rs].sum=Tree[t].sum;
   Tree[ls].Sum+=1ll*Tree[t].add*(m-(m>>1));
   Tree[rs].Sum+=1ll*Tree[t].add*(m>>1);
   Tree[t].add=0;
}
void change(int ll,int rr,int x,int l,int r,int t)
{  if (ll<=l&&r<=rr)
  {  if (!Tree[t].all) { change(ll,rr,x,l,mid,ls); change(ll,rr,x,mid+1,r,rs); }
     else { Tree[t].add+=abs(Tree[t].sum-x); 
	 Tree[t].Sum+=1ll*abs(Tree[t].sum-x)*(r-l+1); 
	 Tree[t].sum=x; return; }
   }
   else {  down(t,r-l+1);
      if (ll<=mid) change(ll,rr,x,l,mid,ls);
      if (rr>mid) change(ll,rr,x,mid+1,r,rs);
}
  Tree[t].Sum=Tree[ls].Sum+Tree[rs].Sum;
  Tree[t].all=Tree[ls].all&Tree[rs].all&(Tree[ls].sum==Tree[rs].sum);
  Tree[t].sum=Tree[ls].sum;
}
void ask(int ll,int rr,int l,int r,int t)
{ if (ll<=l&&r<=rr) {  ans+=Tree[t].Sum;  return; }
   down(t,r-l+1); 
   if (ll<=mid) ask(ll,rr,l,mid,ls);
   if (rr>mid) ask(ll,rr,mid+1,r,rs);
}
int main()
{ scanf("%d%d",&n,&m);
  build_tree(1,n,1);
  for (i=1;i<=m;i++)
  { scanf("%d",&type);
    if (type==1)
    { scanf("%d%d%d",&l,&r,&x);
      change(l,r,x,1,n,1);
    }
   else if (type==2)
   { scanf("%d%d",&l,&r);
     ans=0;
     ask(l,r,1,n,1);
     printf("%I64d\n",ans);
}
}
}