#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define Ls Tree[t].l
#define Rs Tree[t].r
using namespace std;
struct Node{int l,r,sum;}Tree[6000001];
int i,j,m,n,p,k,tot,root[100001],tree[500001];
int a[100001],ans,q,b[100001],l,r,Tot;
int gcd(int x,int y) { return y==0?x:gcd(y,x%y);}
void Build_tree(int l,int r,int t)
{ if (l==r) tree[t]=a[l];
 else { 
      Build_tree(l,mid,ls);
      Build_tree(mid+1,r,rs);
      tree[t]=gcd(tree[ls],tree[rs]);
      }
}
void ask(int ll,int rr,int l,int r,int t)
{  if(ll<=l&&r<=rr) 
    ans=gcd(tree[t],ans);
  else { 
         if (ll<=mid) ask(ll,rr,l,mid,ls);
         if (rr>mid) ask(ll,rr,mid+1,r,rs);
      }
}
void update(int ll,int l,int r,int t)
{ if (l==r) Tree[t].sum++;
   else {
          if (ll<=mid) {
                        if (!Ls) Ls=++tot;
                        update(ll,l,mid,Ls);
                        }
          else {  if (!Rs) Rs=++tot;
                        update(ll,mid+1,r,Rs);
               }
          Tree[t].sum=Tree[Ls].sum+Tree[Rs].sum;
        }
}
void Ask(int ll,int rr,int l,int r,int t)
 { if (!t) return;
   if (ll<=l&&r<=rr) ans+=Tree[t].sum;
   else { 
        if (ll<=mid) Ask(ll,rr,l,mid,Ls);
        if (rr>mid) Ask(ll,rr,mid+1,r,Rs);
        }
}
int main()
{ scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
  scanf("%d",&q);
  sort(b+1,b+n+1);
  Tot=unique(b+1,b+n+1)-(b+1);
  for (i=1;i<=n;i++) root[i]=++tot;
  for (i=1;i<=n;i++)
  update(i,1,n,root[lower_bound(b+1,b+Tot+1,a[i])-b]);
  Build_tree(1,n,1);
  for (;q--;)
  { scanf("%d%d",&l,&r);
    ans=0; ask(l,r,1,n,1);
    int wz=lower_bound(b+1,b+Tot+1,ans)-b;
    if (b[wz]!=ans) printf("%d\n",r-l+1);
    else ans=0,Ask(l,r,1,n,root[wz]),printf("%d\n",r-l+1-ans);
  }
}