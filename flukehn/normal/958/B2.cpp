#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
struct node
{
	int from;
	int to;
	int next;
}edge[200005];
int tot,head[100005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
struct segtree
{
	int ls;
	int rs;
	int maxx;
	int pla;
	int mark;
}tree[400005];
int cnt=1,sum;
int n,rt,dep[100005],size[100005];
int pos[100005],npos[100005],tim,fa[100005];
bool vis[100005];
void dfs(int x,int v,bool ac)
{
	dep[x]=dep[v]+1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].to!=v)
		{
			dfs(edge[i].to,x,ac);
		}
	}
	if(ac)
	if(dep[x]>dep[rt]) rt=x;
}
void dfs2(int x)
{
	pos[x]=++tim;
	npos[tim]=x;
	size[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].to!=fa[x])
		{
			fa[edge[i].to]=x;
			dfs2(edge[i].to);
			size[x]+=size[edge[i].to];
		}
	}
}
void build(int p,int l,int r)
{
	int mid=l+r>>1;
	if(l==r)
	{
		tree[p].maxx=dep[npos[mid]];
		tree[p].pla=l;
		return;
	}
	tree[p].ls=++cnt;
	tree[p].rs=++cnt;
	build(tree[p].ls,l,mid);
	build(tree[p].rs,mid+1,r);
	if(tree[tree[p].ls].maxx>tree[tree[p].rs].maxx)
	{
		tree[p].maxx=tree[tree[p].ls].maxx;
		tree[p].pla=tree[tree[p].ls].pla;
	}
	else
	{
		tree[p].maxx=tree[tree[p].rs].maxx;
		tree[p].pla=tree[tree[p].rs].pla;
	}
}
void modify(int p,int l,int r,int x,int y,int z)
{
	int mid=l+r>>1;
	if(l==x&&r==y)
	{
		tree[p].mark+=z;
		tree[p].maxx-=z;
		return;
	}
	if(tree[p].mark)
	{
		tree[tree[p].ls].mark+=tree[p].mark;
		tree[tree[p].rs].mark+=tree[p].mark;
		tree[tree[p].ls].maxx-=tree[p].mark;
		tree[tree[p].rs].maxx-=tree[p].mark;
		tree[p].mark=0;
	}
	if(y<=mid) modify(tree[p].ls,l,mid,x,y,z);
	else if(x>mid) modify(tree[p].rs,mid+1,r,x,y,z);
	else
	{
		modify(tree[p].ls,l,mid,x,mid,z);
		modify(tree[p].rs,mid+1,r,mid+1,y,z);
	}
	if(tree[tree[p].ls].maxx>tree[tree[p].rs].maxx)
	{
		tree[p].maxx=tree[tree[p].ls].maxx;
		tree[p].pla=tree[tree[p].ls].pla;
	}
	else
	{
		tree[p].maxx=tree[tree[p].rs].maxx;
		tree[p].pla=tree[tree[p].rs].pla;
	}
}
int query(int p,int l,int r,int x,int y)
{
	int mid=l+r>>1;
	if(l==x&&r==y)
	return tree[p].maxx;
	if(tree[p].mark)
	{
		tree[tree[p].ls].mark+=tree[p].mark;
		tree[tree[p].rs].mark+=tree[p].mark;
		tree[tree[p].ls].maxx-=tree[p].mark;
		tree[tree[p].rs].maxx-=tree[p].mark;
		tree[p].mark=0;
	}
	if(y<=mid) return query(tree[p].ls,l,mid,x,y);
	else if(x>mid) return query(tree[p].rs,mid+1,r,x,y);
	else return max(query(tree[p].ls,l,mid,x,mid),query(tree[p].rs,mid+1,r,mid+1,y));
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0,1);
	
	dfs(rt,0,0);
	dfs2(rt);//for(int i=1;i<=n;i++) cout<<npos[i]<<" ";cout<<endl;
	build(1,1,n);
	printf("1 ");
	vis[rt]=1;
	//cout<<rt<<" ";
	sum=1;
	modify(1,1,n,1,n,1);
	for(int i=2;i<=n;i++)
	{
		sum+=query(1,1,n,1,n);
		printf("%d ",sum);
		int temp=npos[tree[1].pla];
		//cout<<temp<<endl;
		if(!tree[1].maxx) continue;
		while(temp)
		{
			if(vis[temp]) break;
			//cout<<pos[temp]<<" "<<pos[temp]+size[temp]-1<<endl;
			modify(1,1,n,pos[temp],pos[temp]+size[temp]-1,1);
			vis[temp]=1;//for(int j=1;j<=n;j++)
		//query(1,1,n,2,n);
			temp=fa[temp];//for(int j=1;j<=n;j++)
		//printf("%d ",query(1,1,n,j,j));
		//printf("\n");
		}
		
	}
}
/*
6
1 2
2 3
3 4
2 6
3 5
*/