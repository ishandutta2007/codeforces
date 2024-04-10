#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,size,t,l,r,x;
long long ans;
struct Node{long long add,sum;}Tree[1000001];
void down(int t,int m)
{ if (!Tree[t].add) return;
   Tree[ls].sum+=1ll*Tree[t].add*(m-(m>>1));
   Tree[rs].sum+=1ll*Tree[t].add*(m>>1);
   Tree[ls].add+=Tree[t].add;
   Tree[rs].add+=Tree[t].add;
  Tree[t].add=0;
}
void update(int ll,int rr,int x,int l,int r,int t)
{ if (ll<=l&&r<=rr) { Tree[t].add+=x; Tree[t].sum+=1ll*(r-l+1)*x; return; }
  down(t,r-l+1);
  if (ll<=mid) update(ll,rr,x,l,mid,ls);
  if (rr>mid) update(ll,rr,x,mid+1,r,rs);
  Tree[t].sum=Tree[ls].sum+Tree[rs].sum;
}
void Update(int ll,int rr,int x,int l,int r,int t)
{ if (ll<=l&&r<=rr) { Tree[t].sum=x; return; }
  down(t,r-l+1);
  if (ll<=mid) Update(ll,rr,x,l,mid,ls);
  if (rr>mid) Update(ll,rr,x,mid+1,r,rs);
  Tree[t].sum=Tree[ls].sum+Tree[rs].sum;
}
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr) { ans+=Tree[t].sum; return;}
  down(t,r-l+1);
  if (ll<=mid) ask(ll,rr,l,mid,ls);
  if (rr>mid) ask(ll,rr,mid+1,r,rs);
}
int main()
{  scanf("%d",&n); size=1;
   for (i=1;i<=n;i++)
  { scanf("%d",&t);
    if (t==1)
    {  scanf("%d%d",&r,&x);
       update(1,r,x,1,n+1,1);
    }
    else if (t==2)
     { size++; scanf("%d",&x);
       Update(size,size,x,1,n+1,1);
 }
  else {  size--; } 
   ans=0;  
    if (size>0)
  ask(1,size,1,n+1,1);
   if (!size) printf("0.000000\n"); else printf("%.6lf\n",(double)ans/(double)size);
}
}