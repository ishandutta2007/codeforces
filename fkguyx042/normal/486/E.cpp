#include<cstdio>
#include<algorithm>
#include<cstring>
#define Maxn 100005
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,a[100001],All;
struct Node{int size,Max;}ans[100001],Ans[100001];
Node Tree[400001];
void up(Node &a,Node b,Node c) 
{     if (b.Max>c.Max)
         a=b;
      else if (b.Max<c.Max) a=c;
      else { 
                a.Max=b.Max;
                a.size=(b.size+c.size)%Mo;
           }
}
void ask(int ll,int rr,Node &x,int l,int r,int t)
{    if (ll<=l&&r<=rr) up(x,x,Tree[t]);
     else { if (ll<=mid) ask(ll,rr,x,l,mid,ls);
            if (rr>mid)  ask(ll,rr,x,mid+1,r,rs);
           }
}
void insert(int ll,Node x,int l,int r,int t)
{ if (l==r) up(Tree[t],Tree[t],x);
  else { if (ll<=mid) insert(ll,x,l,mid,ls);
         else insert(ll,x,mid+1,r,rs);
         up(Tree[t],Tree[ls],Tree[rs]);
       }
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++) 
  {  ask(0,a[i]-1,ans[i],0,Maxn,1);
     if (ans[i].Max==0) ans[i].size=ans[i].Max=1;
     else ans[i].Max++;
     insert(a[i],ans[i],0,Maxn,1);
  }
  All=Tree[1].size;
  memset(Tree,0,sizeof(Tree));
  for(i=n;i;i--)
{  ask(a[i]+1,Maxn,Ans[i],0,Maxn,1);
   if (Ans[i].Max==0) Ans[i].size=Ans[i].Max=1;
   else Ans[i].Max++;
   insert(a[i],Ans[i],0,Maxn,1);
}
 for (i=1;i<=n;i++)
 if (ans[i].Max+Ans[i].Max-1!=Tree[1].Max) printf("1");
 else if (1ll*ans[i].size*Ans[i].size%Mo==All) printf("3");
 else printf("2");
}