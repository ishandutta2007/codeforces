#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,q,l,r,st;
char c[N];
struct Node{int sum[26],add;}tree[400005],Ans;
void up(Node &a,Node &b,Node &c)
{
	  int i;
	  for (i=0;i<26;++i) a.sum[i]=b.sum[i]+c.sum[i];
}
void build_tree(int l,int r,int t)
{
	  tree[t].add=-1;
	  if (l==r) tree[t].sum[c[l]-'a']++;
	  else 
	  {
	     build_tree(l,mid,ls);
		 build_tree(mid+1,r,rs);
		 up(tree[t],tree[ls],tree[rs]);
	 }
}
void down(int t,int len)
{
	  if (tree[t].add==-1) return;
	  int i; int c=tree[t].add;
	  for (i=0;i<26;++i) tree[ls].sum[i]=tree[rs].sum[i]=0;
	  tree[ls].add=tree[rs].add=c;
	  tree[ls].sum[c]=(len-(len>>1));
	  tree[rs].sum[c]=(len>>1);
	  tree[t].add=-1;
}
void ask(int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) up(Ans,Ans,tree[t]);
	  else 
	  {
	  	  down(t,r-l+1);
	  	  if (ll<=mid) ask(ll,rr,l,mid,ls);
	  	  if (rr>mid)  ask(ll,rr,mid+1,r,rs);
	  }
}
void update(int ll,int rr,int c,int l,int r,int t)
{
	  if (ll<=l&&r<=rr)
	  {
	  	   int i;
	  	   for (i=0;i<26;++i) tree[t].sum[i]=0;
	  	   tree[t].sum[c]=r-l+1;
	  	   tree[t].add=c;
	  }
	  else 
	  {
	  	   down(t,r-l+1);
	  	   if (ll<=mid) update(ll,rr,c,l,mid,ls);
	  	   if (rr>mid)  update(ll,rr,c,mid+1,r,rs);
	  	   up(tree[t],tree[ls],tree[rs]);
	  }
}
void F(int l,int r,int t)
{
	  if (l==r) 
	  {
	  	  int i;
	  	  for (i=0;i<26;++i) if (tree[t].sum[i]) break;
	  	  printf("%c",i+'a');
	  }
	  else 
	  {
	  	 down(t,r-l+1);
	  	 F(l,mid,ls);
	  	 F(mid+1,r,rs);
	  }
}
int main()
{
	  scanf("%d%d",&n,&q);
	  scanf("%s",c);
	  for (i=n;i;--i) c[i]=c[i-1];
	  build_tree(1,n,1);
	  for (;q--;)
	  {
	  	for (i=0;i<26;++i) Ans.sum[i]=0;
	  	scanf("%d%d%d",&l,&r,&k);
	  	ask(l,r,1,n,1);
	  	st=l;
	  	if (k==1)
	  	{
	  	   for (i=0;i<26;++i) if (Ans.sum[i]) update(st,st+Ans.sum[i]-1,i,1,n,1),st+=Ans.sum[i];
	    }
	  	else for (i=25;i>=0;--i) if (Ans.sum[i]) update(st,st+Ans.sum[i]-1,i,1,n,1),st+=Ans.sum[i];
	  }
	  F(1,n,1);
}