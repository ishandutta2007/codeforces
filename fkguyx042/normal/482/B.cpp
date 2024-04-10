#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
struct Tre{int add,sum;}Tree[400001];
int ans[100001];
struct Node{int l,r,q;}Q[100001];
int x[31],i,j,m,n,p,k,q,l,r,sum;
void down(int t)
{  if (!Tree[t].add) return;
   Tree[ls].add|=Tree[t].add;
   Tree[ls].sum|=Tree[t].add;
   Tree[rs].add|=Tree[t].add;
   Tree[rs].sum|=Tree[t].add;
   Tree[t].add=0;
}
void update(int ll,int rr,int c,int l,int r,int t)
{ if (ll<=l&&r<=rr) { Tree[t].sum|=c; Tree[t].add|=c; }
  else {  down(t);
  	  if (ll<=mid) update(ll,rr,c,l,mid,ls);
  	  if (rr>mid)  update(ll,rr,c,mid+1,r,rs);
  	  Tree[t].sum=Tree[ls].sum&Tree[rs].sum;
  }
}
void ask(int ll,int rr,int l,int r,int t)
{ if (ll<=l&&r<=rr)  sum&=Tree[t].sum;
  else {
  	     down(t);
  	  if (ll<=mid) ask(ll,rr,l,mid,ls);
  	  if (rr>mid)  ask(ll,rr,mid+1,r,rs);
  }
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
 {scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].q);
 update(Q[i].l,Q[i].r,Q[i].q,1,n,1);
 }
 for (i=1;i<=m;i++)
{  
     sum=(1<<30)-1;
    ask(Q[i].l,Q[i].r,1,n,1); if (sum!=Q[i].q) { printf("NO\n"); return 0;}
  }
for (i=1;i<=n;i++)
{   sum=(1<<30)-1;
    ask(i,i,1,n,1);
    ans[i]=sum;
}
printf("YES\n");
for (i=1;i<=n;i++) printf("%d ",ans[i]);
}