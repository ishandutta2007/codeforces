#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>

#define M 7000005

#define ls tree[t].l
#define rs tree[t].r
#define mid ((l+r)>>1)

using namespace std;

int i,j,m,n,p,k,type,l,r,ans,tot=1;
map<int,int>mp,vis;
struct Node{int l,r,Ans,Ansl,Ansr,sum;}tree[M];
void up(Node &a,Node b,Node c,int len)
{
       a.sum=b.sum+c.sum;
	   a.Ans=max(b.Ans,max(c.Ans,b.Ansr+c.Ansl));
	   a.Ansl=b.Ansl;
	   if (b.Ansl==len-(len>>1)) a.Ansl+=c.Ansl;
	   a.Ansr=c.Ansr;
	   if (c.Ansr==len>>1) a.Ansr+=b.Ansr;
}
void del(int ll,int l,int r,int t)
{
	  if (l==r) tree[t].sum=0,tree[t].Ans=tree[t].Ansl=tree[t].Ansr=1;
	  else 
	  {
	  	   if (ll<=mid) del(ll,l,mid,ls);
	  	   else del(ll,mid+1,r,rs);
	  	   up(tree[t],tree[ls],tree[rs],r-l+1);
	  }
}
void insert(int ll,int l,int r,int t)
{
	  if (l==r) tree[t].sum=1,tree[t].Ans=tree[t].Ansl=tree[t].Ansr=0;
	  else
	  {
	  	  int len=r-l+1;
	  	  if (!ls)
	  	  {
	  	  	  ls=++tot;
	  	  	  tree[tot].Ans=tree[tot].Ansl=tree[tot].Ansr=len-(len>>1);
		  }
		  if (!rs)
		  {
		  	  rs=++tot;
		  	  tree[tot].Ans=tree[tot].Ansl=tree[tot].Ansr=len>>1;
		  }
		  if (ll<=mid) insert(ll,l,mid,ls); else insert(ll,mid+1,r,rs);
		  up(tree[t],tree[ls],tree[rs],r-l+1);
	  }
}
void ask(int &x,int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) x+=tree[t].sum;
	  else 
	  {
	  	  if (ll<=mid) ask(x,ll,rr,l,mid,ls);
	  	  if (rr>mid)  ask(x,ll,rr,mid+1,r,rs);
	   } 
}
void query(int &x,int l,int r,int t)
{
	  if (l==r) 
	  {
	  	  x=l; return;
	  }
	    int len=r-l+1;
	   if (!ls)
	  	  {
	  	  	  ls=++tot;
	  	  	  tree[tot].Ans=tree[tot].Ansl=tree[tot].Ansr=len-(len>>1);
		  }
		  if (!rs)
		  {
		  	  rs=++tot;
		  	  tree[tot].Ans=tree[tot].Ansl=tree[tot].Ansr=len>>1;
		  }
	  if (tree[rs].Ans==tree[1].Ans) query(x,mid+1,r,rs);
	  else if (tree[ls].Ansr+tree[rs].Ansl==tree[1].Ans) x=mid-tree[ls].Ansr+1;
	  else query(x,l,mid,ls);
}
int Find()
{
	  int x;
	  query(x,1,n,1);
	  return x+tree[1].Ans/2;
}
int main()
{
	 scanf("%d%d",&n,&m);
	 tree[1].Ans=tree[1].Ansl=tree[1].Ansr=n;
	 for (;m--;)
	 {
	 	  scanf("%d",&type);
	 	  if (type)
	 	  {
	 	  	  if (vis[type]&1) del(mp[type],1,n,1);
	 	  	  else  insert(mp[type]=Find(),1,n,1);
	 	  	  vis[type]++;
		   }
		   else 
		   { 
		        scanf("%d%d",&l,&r);
		        ask(ans=0,l,r,1,n,1);
		        printf("%d\n",ans);
		   }
	 }
}