#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,Len,l,r;
char c[1000001];
struct Node{int l,r,sum;}Tree[4000001];
Node Ans;
void update(Node &A,Node B,Node C)
 { A.sum=B.sum+C.sum;
   A.sum+=min(B.l,C.r);
   A.l=C.l+max(0,B.l-C.r);
   A.r=B.r+max(0,C.r-B.l);
 }
void build_tree(int l,int r,int t)
{ if (l==r) 
   {  if (c[l-1]=='(') Tree[t].l=1; else Tree[t].r=1; }
else {  build_tree(l,mid,ls);
        build_tree(mid+1,r,rs);
        update(Tree[t],Tree[ls],Tree[rs]);
     }
}
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr) update(Ans,Ans,Tree[t]);
   else {  if (ll<=mid) ask(ll,rr,l,mid,ls);
           if (rr>mid) ask(ll,rr,mid+1,r,rs);
        }
}
int main()
{ scanf("%s",&c);
  Len=strlen(c);
  build_tree(1,Len,1);
  scanf("%d",&m);
  for (i=1;i<=m;i++)
  { scanf("%d%d",&l,&r);
     Ans.l=Ans.r=Ans.sum=0;
     ask(l,r,1,Len,1);
     printf("%d\n",Ans.sum*2);
  }
}