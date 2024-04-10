#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls(x) Tree[x].l
#define rs(x) Tree[x].r
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,tot;
struct Node{int l,r,sum;}Tree[30000001];
int ans,a[1000001],wz[10000001],b[1000001],root[1000001],A,B,C,D,l,r,L,R;
int f(int x)
{  return (x-1+ans)%n+1; }
void update(int ll,int l,int r,int t,int t1)
{  if (l==r) Tree[t].sum++; 
  else {
  	     if (ll<=mid)
  	      {  ls(t)=++tot;
  	         Tree[tot]=Tree[ls(t1)];
  	         update(ll,l,mid,ls(t),ls(t1));
  	      } else
  	      {  rs(t)=++tot;
  	         Tree[tot]=Tree[rs(t1)];
  	         update(ll,mid+1,r,rs(t),rs(t1));
  	      }
  	  Tree[t].sum=Tree[ls(t)].sum+Tree[rs(t)].sum;
     }
}
void ask(int ll,int rr,int l,int r,int t,int t1)
{  if (ll<=l&&r<=rr) ans+=(Tree[t].sum-Tree[t1].sum);
  else {   if (ll<=mid) ask(ll,rr,l,mid,ls(t),ls(t1));
           if (rr>mid)  ask(ll,rr,mid+1,r,rs(t),rs(t1));
       }
}
int main()
{scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),wz[a[i]]=i;
  for (i=1;i<=n;i++) scanf("%d",&b[i]);
  for (i=1;i<=n;i++)
{   root[i]=++tot;
    Tree[root[i]]=Tree[root[i-1]];
    update(wz[b[i]],1,n,root[i],root[i-1]);
}
scanf("%d",&m);
for (i=1;i<=m;i++)
{  scanf("%d%d%d%d",&A,&B,&C,&D);
   l=min(f(A),f(B)); r=max(f(A),f(B));
   L=min(f(C),f(D)); R=max(f(C),f(D));
   ans=0;
   ask(l,r,1,n,root[R],root[L-1]);
   printf("%d\n",ans); ans++;
}
}