#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls(x) Tree[x].l
#define rs(x) Tree[x].r
#define Mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,root[100001],tot,l,r,w,L,R,mid;
struct Node{int sum,suml,sumr,l,r;}Tree[5000001];
int Ans,Ansr;
struct Nde{int x,y;}a[100001];
inline bool cmp(Nde a,Nde b) {return a.x>b.x;}
void up(Node &a,Node b,Node c,int m)
{  if (b.suml==(m-(m>>1))) a.suml=b.suml+c.suml; else a.suml=b.suml;
   if (c.sumr==(m>>1)) a.sumr=b.sumr+c.sumr; else a.sumr=c.sumr;
   a.sum=max(b.sum,max(c.sum,b.sumr+c.suml));
}
void update(int ll,int l,int r,int t,int t1)
{ if (l==r) Tree[t].sum=Tree[t].suml=Tree[t].sumr=1;
 else {
 	    if (ll<=Mid) { 
 	       ls(t)=++tot;
 	       Tree[tot]=Tree[ls(t1)];
 	       update(ll,l,Mid,ls(t),ls(t1));
 	      }
 	    else { rs(t)=++tot;
 	           Tree[tot]=Tree[rs(t1)];
 	           update(ll,Mid+1,r,rs(t),rs(t1));
 	         }
 	    up(Tree[t],Tree[ls(t)],Tree[rs(t)],r-l+1);
 	}
}
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr) { Ans=max(Ans,max(Tree[t].sum,Ansr+Tree[t].suml));  
   if (Tree[t].sumr==(r-l+1)) Ansr+=Tree[t].sumr; else Ansr=Tree[t].sumr;
    }
else {  if (ll<=Mid) ask(ll,rr,l,Mid,ls(t));
        if (rr>Mid)  ask(ll,rr,Mid+1,r,rs(t));
    }
}
bool check(int x)
{ Ans=Ansr=0;  ask(l,r,1,n,root[x]);
   return Ans>=w; }
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].y=i;
  sort(a+1,a+n+1,cmp);
  for (i=1;i<=n;i++)
  { root[i]=++tot;
    Tree[root[i]]=Tree[root[i-1]];
    update(a[i].y,1,n,root[i],root[i-1]);
  }
  scanf("%d",&m);
  for (i=1;i<=m;i++)
  { scanf("%d%d%d",&l,&r,&w);
    mid=0;
    L=1,R=n+1;
    while ((L+R)>>1!=mid)
    {  mid=(L+R)>>1;
       if (check(mid)) R=mid;
       else L=mid;
    }
    printf("%d\n",a[R].x);
}
}