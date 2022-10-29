#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,l,r,x;
struct Node{int sum,all;}Tree[1200001];
void update(int ll,int rr,int x,int l,int r,int t)
{ 
      if (l==r)
      {   if (!Tree[t].sum||x==0)
         {  
          Tree[t].sum=x;
          Tree[t].all=(x>0)?1:0;
         }
      }
      else  if (ll<=l&&r<=rr)
      { 
           //if (!Tree[t].all)
           if (!Tree[ls].all) update(ll,rr,x,l,mid,ls);
           if (!Tree[rs].all) update(ll,rr,x,mid+1,r,rs);
      }
      else {   
             if (ll<=mid) update(ll,rr,x,l,mid,ls);
             if (rr>mid)  update(ll,rr,x,mid+1,r,rs);
           }
      if (l!=r) Tree[t].all=Tree[ls].all&Tree[rs].all;
}
int ask(int ll,int l,int r,int t)
{ if (l==r) return Tree[t].sum;
else {
	   if (ll<=mid) return ask(ll,l,mid,ls);
	   else return ask(ll,mid+1,r,rs);
    }
}
int main()
{
	  scanf("%d%d",&n,&k);
	  for (i=1;i<=k;i++)
	{
		  // scanf("%d",&n);
		  scanf("%d%d%d",&l,&r,&x);
		  update(l,r,x,1,n,1);
		  update(x,x,0,1,n,1);
	}
	for (i=1;i<=n;i++) printf("%d ",ask(i,1,n,1));
}