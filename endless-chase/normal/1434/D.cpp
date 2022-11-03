#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=1e6;
int n,x[555555],y[555555],t[555555],cnt,beg[555555],en[555555],dep[555555],crt,vl[555555],b[555555],e[555555],id,Log[1111111],ww[555555],q;
struct treenode
{
	int lazy,x0,y0,x1,y1,mx0,mx1;
	treenode()
	{
		x0=y0=x1=y1=-1;
		mx0=mx1=-1e9;
		lazy=0;
	}
}tree[2222222];
vector<pair<int,int> > g[555555];
int arr[1111111],st[22][1111111];
void dfs(int i,int fa)
{
	dep[i]=dep[fa]+1;
	beg[i]=++cnt;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		vl[to]=vl[i]^val;
		dfs(to,i);
	}
	en[i]=cnt;
}
void rfs(int i,int fa)
{
	++crt;b[i]=crt;
	arr[crt]=dep[i];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa) continue;
		rfs(to,i);
		++crt;arr[crt]=dep[i];
	}
	e[i]=crt;
}
int get(int l,int r)
{
	int x=Log[r-l+1];
	return min(st[x][l],st[x][r-(1<<x)+1]);
}
int dist(int x,int y)
{
	if (x==-1 || y==-1) return -1e9;
	if (b[x]>b[y]) swap(x,y);
	return dep[x]+dep[y]-(get(b[x],e[y])<<1);
}
void pushup(int node)
{
	int mx=-2e9,cr;
	if (tree[node<<1].mx0>mx)
	{
		mx=tree[node<<1].mx0;
		tree[node].x0=tree[node<<1].x0;tree[node].y0=tree[node<<1].y0;
	}
	if (tree[(node<<1)|1].mx0>mx)
	{
		mx=tree[(node<<1)|1].mx0;
		tree[node].x0=tree[(node<<1)|1].x0;tree[node].y0=tree[(node<<1)|1].y0;
	}
	cr=dist(tree[node<<1].x0,tree[(node<<1)|1].x0);
	if (cr>mx)
	{
		mx=cr;
		tree[node].x0=tree[node<<1].x0;tree[node].y0=tree[(node<<1)|1].x0;
	}
	cr=dist(tree[node<<1].x0,tree[(node<<1)|1].y0);
	if (cr>mx)
	{
		mx=cr;
		tree[node].x0=tree[node<<1].x0;tree[node].y0=tree[(node<<1)|1].y0;
	}
	cr=dist(tree[node<<1].y0,tree[(node<<1)|1].x0);
	if (cr>mx)
	{
		mx=cr;
		tree[node].x0=tree[node<<1].y0;tree[node].y0=tree[(node<<1)|1].x0;
	}
	cr=dist(tree[node<<1].y0,tree[(node<<1)|1].y0);
	if (cr>mx)
	{
		mx=cr;
		tree[node].x0=tree[node<<1].y0;tree[node].y0=tree[(node<<1)|1].y0;
	}
	tree[node].mx0=mx;
	mx=-2e9;
	if (tree[node<<1].mx1>mx)
	{
		mx=tree[node<<1].mx1;
		tree[node].x1=tree[node<<1].x1;tree[node].y1=tree[node<<1].y1;
	}
	if (tree[(node<<1)|1].mx1>mx)
	{
		mx=tree[(node<<1)|1].mx1;
		tree[node].x1=tree[(node<<1)|1].x1;tree[node].y1=tree[(node<<1)|1].y1;
	}
	cr=dist(tree[node<<1].x1,tree[(node<<1)|1].x1);
	if (cr>mx)
	{
		mx=cr;
		tree[node].x1=tree[node<<1].x1;tree[node].y1=tree[(node<<1)|1].x1;
	}
	cr=dist(tree[node<<1].x1,tree[(node<<1)|1].y1);
	if (cr>mx)
	{
		mx=cr;
		tree[node].x1=tree[node<<1].x1;tree[node].y1=tree[(node<<1)|1].y1;
	}
	cr=dist(tree[node<<1].y1,tree[(node<<1)|1].x1);
	if (cr>mx)
	{
		mx=cr;
		tree[node].x1=tree[node<<1].y1;tree[node].y1=tree[(node<<1)|1].x1;
	}
	cr=dist(tree[node<<1].y1,tree[(node<<1)|1].y1);
	if (cr>mx)
	{
		mx=cr;
		tree[node].x1=tree[node<<1].y1;tree[node].y1=tree[(node<<1)|1].y1;
	}
	tree[node].mx1=mx;
}
void push(int node)
{
	tree[node].lazy^=1;
	swap(tree[node].x0,tree[node].x1);
	swap(tree[node].y0,tree[node].y1);
	swap(tree[node].mx0,tree[node].mx1);
}
void pushdown(int node)
{
	if (tree[node].lazy)
	{
		push(node<<1);
		push((node<<1)|1);
		tree[node].lazy=0;
	}
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		if (vl[ww[l]]==1)
		{
			tree[node].x0=tree[node].y0=ww[l];
			tree[node].x1=tree[node].y1=-1;
			tree[node].mx0=0;tree[node].mx1=-1e9;
		}
		else
		{
			tree[node].x1=tree[node].y1=ww[l];
			tree[node].x0=tree[node].y0=-1;
			tree[node].mx0=-1e9;tree[node].mx1=0;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
void update(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		push(node);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	update(beg,en,l,mid,node<<1);
	update(beg,en,mid+1,r,(node<<1)|1);
	pushup(node);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&t[i]);
		g[x[i]].push_back(make_pair(y[i],t[i]));
		g[y[i]].push_back(make_pair(x[i],t[i]));
	}
	dfs(1,0);
	rfs(1,0);
	for (int i=2;i<=maxn;i++) Log[i]=Log[i>>1]+1;
	for (int i=1;i<=crt;i++) st[0][i]=arr[i];
	for (int i=1;i<=20;i++)
	{
		for (int j=1;j<=crt;j++)
		{
			st[i][j]=st[i-1][j];
			if (j+(1<<(i-1))<=crt) st[i][j]=min(st[i][j],st[i-1][j+(1<<(i-1))]);
		}
	} 
	for (int i=1;i<=n;i++) ww[beg[i]]=i;
	build(1,n,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&id);
		if (dep[x[id]]<dep[y[id]]) swap(x[id],y[id]);
		update(beg[x[id]],en[x[id]],1,n,1);
		printf("%d\n",max(tree[1].mx0,tree[1].mx1));
	}
	return Accepted;
}