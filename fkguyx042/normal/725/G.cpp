#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 200005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
const int inf=(int)(1e9)+N*10;
int i,j,m,n,p,k,a[N],fa[N],st[N],deep[N],son[N],top[N],size[N],tot,Que[N],ma[N];
vector<int>v[N];
struct Node{
		int x,t;
}Q[N];
struct gao{
		int x,y,id;
}A[N];
void dfs(int x)
{
		int i;
		for (i=0;i<(int)v[x].size();++i)
		{
				int p=v[x][i];
				deep[p]=deep[x]+1;
				dfs(p);
				size[x]+=size[p];
				if (!son[x]||size[son[x]]<size[p]) son[x]=p;
		}
		size[x]++;
}
void Dfs(int x,int tp)
{
		int i;
		st[x]=++tot; Que[tot]=x;
		top[x]=tp;
		if (son[x]) Dfs(son[x],tp);
		for (i=0;i<(int)v[x].size();++i)
		{
				int p=v[x][i];
				if (p==son[x]) continue;
				Dfs(p,p);
		}
}
inline int cmp(gao a,gao b)
{
		if (a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
}
struct Tre{
		int sum,add;
}tree[N*4];
void down(int t,int l,int r)
{
		tree[ls].add=max(tree[ls].add,tree[t].add);
		tree[ls].sum=max(tree[ls].sum,tree[ls].add+2*deep[Que[mid]]);
		tree[rs].add=max(tree[rs].add,tree[t].add); 
		tree[rs].sum=max(tree[rs].sum,tree[rs].add+2*deep[Que[r]]);
}
void build_tree(int l,int r,int t)
{
		tree[t].add=-inf;
		if (l==r) 
		{
				if (l==1) tree[t].sum=inf;
				else tree[t].sum=-inf;
		}
		else 
		{
				build_tree(l,mid,ls);
				build_tree(mid+1,r,rs);
				tree[t].sum=max(tree[ls].sum,tree[rs].sum);
		}
}
int getMax(int ll,int rr,int l,int r,int t)
{
		if (ll<=l&&r<=rr) return tree[t].sum;
		else 
		{
				down(t,l,r);
				int S=-1000000;
				if (ll<=mid) S=max(S,getMax(ll,rr,l,mid,ls));
				if (rr>mid)  S=max(S,getMax(ll,rr,mid+1,r,rs));
				return S; 
		}
}
int Find(int ll,int rr,int c,int l,int r,int t)
{
		if (tree[t].sum<c) return 0;
		if (l==r) return r;
		else if (ll<=l&&r<=rr)
		{
				down(t,l,r);
				if (tree[rs].sum>=c) return Find(ll,rr,c,mid+1,r,rs);
				return Find(ll,rr,c,l,mid,ls);
		}
		else 
		{
				down(t,l,r);
				if (rr>mid)
				{
					 int ID=Find(ll,rr,c,mid+1,r,rs);
					 if (ID) return ID;
				}
				if (ll<=mid)
				{
					 int ID=Find(ll,rr,c,l,mid,ls);
					 if (ID) return ID;
				}
				return 0;
		}
}
void ins(int ll,int rr,int c,int l,int r,int t)
{
		if (ll<=l&&r<=rr)
		{	
			tree[t].add=max(tree[t].add,c);
			tree[t].sum=max(tree[t].sum,tree[t].add+2*deep[Que[r]]);
		}
		else 
		{
			down(t,l,r);
			if (ll<=mid) ins(ll,rr,c,l,mid,ls);
			if (rr>mid)  ins(ll,rr,c,mid+1,r,rs);
			tree[t].sum=max(tree[ls].sum,tree[rs].sum); 
		}
}
int main()
{
	  scanf("%d%d",&n,&m);
	  for (i=1;i<=n;++i) scanf("%d",&fa[i]),v[fa[i]].pb(i);
	  dfs(0);
	  Dfs(0,0);
	  for (i=1;i<=m;++i) scanf("%d%d",&Q[i].x,&Q[i].t),A[i]=(gao){Q[i].t+deep[Q[i].x],Q[i].x,i};
	  sort(A+1,A+m+1,cmp);
	  build_tree(1,tot,1);
	  for (i=1;i<=m;++i)
	  {
	  		int now=Q[A[i].id].x,ti=Q[A[i].id].t,guan=ti+deep[now],x=now,ID;
	  			for (;;)
	  		{
	  				int ans=getMax(st[top[x]],st[x],1,tot,1);
	  				if (ans>=guan) 
					{
						ID=Que[Find(st[top[x]],st[x],guan,1,tot,1)];
						break;
					}
					x=fa[top[x]];
	  		}
	  		ma[A[i].id]=ID;
	  		int goal=ti+deep[now]-deep[ID]-1-deep[ID];
	  		for (;top[now]!=top[ID];)
	  		{
	  				ins(st[top[now]],st[now],goal,1,tot,1);
	  				now=fa[top[now]];
	  		}
	  		ins(st[ID],st[now],goal,1,tot,1);
	  }
	  for (i=1;i<=m;++i) printf("%d ",Q[i].t+2*(deep[Q[i].x]-deep[ma[i]]));
}