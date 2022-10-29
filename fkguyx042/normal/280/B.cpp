#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,l,r,Mid,ans,x;
int Tree[400001],a[100001];
int Ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr) return Tree[t];
   if (rr<=mid) return Ask(ll,rr,l,mid,ls);
   if (ll>mid) return Ask(ll,rr,mid+1,r,rs);
   return max(Ask(ll,rr,l,mid,ls),Ask(ll,rr,mid+1,r,rs));
}
void build_tree(int l,int r,int t)
{   if (l==r) Tree[t]=a[l];
else { build_tree(l,mid,ls);build_tree(mid+1,r,rs);Tree[t]=max(Tree[ls],Tree[rs]); }
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  build_tree(1,n,1);
  for (i=1;i<=n;i++)
 {   if (i>1)
    { if (Ask(1,i-1,1,n,1)>a[i])
      {   l=1;
          r=i; Mid=0;
          for (;(l+r)>>1!=Mid;)
          { Mid=(l+r)>>1;
            if (Ask(Mid,i-1,1,n,1)>a[i])
                l=Mid; else r=Mid;
          }
          ans=max(a[i]^a[l],ans);
      }
   }
    if (i<n)
    {  if (Ask(i+1,n,1,n,1)>a[i])
       {  l=i+1; r=n+1; Mid=0;
         for (;(l+r)>>1!=Mid;)
         {   Mid=(l+r)>>1;
            if ((x=Ask(i+1,Mid,1,n,1))>a[i])
              r=Mid; else l=Mid;
         }
         ans=max(a[i]^a[r],ans);
}
}
}
printf("%d\n",ans);
}