#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ls Tree[t].l
#define Ls Tree[t1].l
#define Rs Tree[t1].r
#define rs Tree[t].r
#define mid ((l+r)>>1)
using namespace std;
map<int,int>mp;
int root[500001],tot,l,r;
struct Node{int l,r,sum;}Tree[10000001];
int i,j,m,n,p,k,a[500001],ans;
void up(int &x,int y,int z)
{  if (y==0) x=z; else if (z==0) x=y;
   else x=min(y,z);
}
void update(int ll,int c,int l,int r,int t,int t1)
{  if (l==r) up(Tree[t].sum,Tree[t].sum,c);
   else {  if (ll<=mid) 
          {  ls=++tot,Tree[ls]=Tree[Ls];
		     update(ll,c,l,mid,ls,Ls);
          }
           else {  rs=++tot,Tree[rs]=Tree[Rs];
                   update(ll,c,mid+1,r,rs,Rs);
                }
           up(Tree[t].sum,Tree[ls].sum,Tree[rs].sum);
        }
}
void ask(int ll,int rr,int l,int r,int t)
{ if (!t) return;
  if (ll<=l&&r<=rr) up(ans,ans,Tree[t].sum);
  else { if (ll<=mid) ask(ll,rr,l,mid,ls);
         if (rr>mid) ask(ll,rr,mid+1,r,rs);
       }
}
int main()
{ 
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
{scanf("%d",&a[i]);
  root[i]=++tot;
   Tree[root[i]]=Tree[root[i-1]];
  if (mp[a[i]])
 { p=mp[a[i]];   
   update(p,i-p,1,n,root[i],root[i-1]); }
 mp[a[i]]=i;
}
 for (i=1;i<=m;i++)
{ ans=(int)1e9;
  scanf("%d%d",&l,&r);
  ask(l,r,1,n,root[r]);
  if (ans==(int)1e9) printf("-1\n");
  else printf("%d\n",ans);
}
}