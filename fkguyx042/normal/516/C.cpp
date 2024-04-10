#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
long long h[200001],d[200001];
struct Node{long long Min,Max,sum;}Tree[2000001];
int N,n,i,m,a,b;
long long ans,Min;
void build_tree(int l,int r,int t)
{  if (l==r) Tree[t].Max=d[l]+2*h[l],Tree[t].Min=d[l]-2*h[r];
   else { build_tree(l,mid,ls);
          build_tree(mid+1,r,rs);
          Tree[t].sum=max(Tree[ls].sum,max(Tree[rs].sum,Tree[rs].Max-Tree[ls].Min));
          Tree[t].Min=min(Tree[ls].Min,Tree[rs].Min);
          Tree[t].Max=max(Tree[ls].Max,Tree[rs].Max);
        }
}
void ask(int ll,int rr,int l,int r,int t)
{ if (ll<=l&&r<=rr) 
  {  ans=max(ans,max(Tree[t].sum,Tree[t].Max-Min));
     Min=min(Min,Tree[t].Min);
  }
  else { if (ll<=mid) ask(ll,rr,l,mid,ls);
         if (rr>mid)  ask(ll,rr,mid+1,r,rs);
       }
}
int main()
{scanf("%d%d",&n,&m); N=2*n;
 for (i=2;i<=n+1;i++) scanf("%I64d",&d[i]);
 for (i=n+2;i<=N;i++) d[i]=d[i-n];
 for (i=1;i<=n;i++) scanf("%I64d",&h[i]),h[i+n]=h[i];
 for (i=2;i<=N;i++) d[i]+=d[i-1];
 build_tree(1,N,1);
 for (i=1;i<=m;i++)
 { scanf("%d%d",&a,&b);
   ans=0; Min=(long long)1e18;
   if (a<=b) ask(b+1,a+n-1,1,N,1);
   else ask(b+1,a-1,1,N,1);
   printf("%I64d\n",ans);
}
}