#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)

#define seed 23333
#define Mo 998244353 
#define maxlen 1200000
#define N 2400005
#define M 20

using namespace std;
int i,j,m,n,p,k,len,hash[N],ans,pow[N];
char c[N];
struct Node{int x,y;}tree[4*N];
void up(Node &a,Node b,Node c)
{
	 a.x=c.x;
	 a.y=b.y;
	 a.x+=max(0,b.x-c.y);
	 a.y+=max(0,c.y-b.x);
}
void build_tree(int l,int r,int t)
{
	  if (l==r) 
	  {
	  	  if (c[l]=='(') tree[t].x=1;
	  	  else tree[t].y=1;
	  }
	  else 
	  { 
	    build_tree(l,mid,ls);
	    build_tree(mid+1,r,rs);
	    up(tree[t],tree[ls],tree[rs]);
	  }
}
void ask(Node &x,int ll,int rr,int l,int r,int t)
{ 
  if (ll<=l&&r<=rr) up(x,x,tree[t]);
  else 
  {
  	  if (ll<=mid) ask(x,ll,rr,l,mid,ls);
  	  if (rr>mid)  ask(x,ll,rr,mid+1,r,rs);
  }
}
int get(int x,int y){ return (hash[y]-1ll*hash[x-1]*pow[y-x+1]%Mo+Mo)%Mo; }
inline bool compare(int x,int y)
{
	  if (get(x,x+len/2-1)==get(y,y+len/2-1)) return 0;
	  int l=0,r=len/2+1,Mid=0;
	  while ((l+r)>>1!=Mid)
	  {
	  	  Mid=(l+r)>>1;
	  	  if (get(x,x+Mid-1)==get(y,y+Mid-1)) l=Mid; else r=Mid;
	  }
	  return c[x+l]<c[y+l];
}
int main()
{ 
   pow[0]=1;
   for (i=1;i<N;++i) pow[i]=1ll*pow[i-1]*seed%Mo;
   scanf("%s",c);
   len=strlen(c); 
   for (i=len;i;--i) c[i]=c[i-1];  
   for (i=len+1;i<=2*len;++i) c[i]=c[i-len]; len*=2;
   for (i=1;i<=len;++i) hash[i]=(1ll*hash[i-1]*seed%Mo+c[i])%Mo;
   build_tree(1,len,1); Node y;
   for (i=1;i<=len/2;++i)
     {
     	 Node x; x.x=x.y=0;
     	 ask(x,i,i+len/2-1,1,len,1);
     	 if (!x.x||!x.y)
     	 {
     	 	   if (!ans||compare(i,ans)) ans=i;
     	 	   y=x;
     	 }
     }
  if (y.y) for (i=1;i<=y.y;++i) printf("(");
  for (i=ans;i<ans+len/2;++i) printf("%c",c[i]);
  if (y.x) for (i=1;i<=y.x;++i) printf(")");
}