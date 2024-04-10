#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char c;int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
struct node
{
	int next,to,v;
}e[3000005];
int h[3000005];
int cnt;
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	e[cnt].to=y;
	e[cnt].v=z;
	h[x]=cnt;
}
int n,q,s;
int cst;
struct nod
{
	int ls,rs;
}ee[3000005];
void build1(int &k,int l,int r)
{
	if(l==r)
	{
		k=l;
		return ;
	}
	if(!k)k=++cst;
	int mid=l+r>>1;
	build1(ee[k].ls,l,mid);
	build1(ee[k].rs,mid+1,r);
	add(k,ee[k].ls,0);
	add(k,ee[k].rs,0); 
//	cout<<k<<' '<<l<<' '<<r<<' '<<ee[k].ls<<" "<<ee[k].rs<<endl;
}
void build2(int &k,int l,int r)
{
	if(l==r)
	{
		k=l;
		return ;
	}
	if(!k)k=++cst;
	int mid=l+r>>1;
	build2(ee[k].ls,l,mid);
	build2(ee[k].rs,mid+1,r);
	add(ee[k].ls,k,0);
	add(ee[k].rs,k,0); 
}
void change1(int k,int l,int r,int x,int y,int u,int v)
{
	if(r<x||y<l)
	{
		return;
	}
	if(x<=l&&r<=y)
	{
		add(u,k,v);
		return;
	}
	int mid=l+r>>1;
	change1(ee[k].ls,l,mid,x,y,u,v);
	change1(ee[k].rs,mid+1,r,x,y,u,v);
}
void change2(int k,int l,int r,int x,int y,int u,int v)
{
	if(r<x||y<l)
	{
		return;
	}
	if(x<=l&&r<=y)
	{
		add(k,u,v);
		return;
	}
	int mid=l+r>>1;
	change2(ee[k].ls,l,mid,x,y,u,v);
	change2(ee[k].rs,mid+1,r,x,y,u,v);
}
int dis[3000005];
int vis[3000005];
signed main(){
	n=read();
	q=read();
	s=read();
	cst=n;
	int root1=0;
	int root2=0;
	build1(root1,1,n);
	build2(root2,1,n);
//	return  0;
	for(int i=1;i<=q;i++)
	{
		int op=read();
		if(op==1)
		{
			int a,b,c;
			a=read();
			b=read();
			c=read();
			add(a,b,c);
		}
		if(op==2)
		{
			int a,b,c,d;
			a=read();
			b=read();
			c=read();
			d=read();
			change1(root1,1,n,b,c,a,d);
		}
		if(op==3)
		{
			int a,b,c,d;
			a=read();
			b=read();
			c=read();
			d=read();
			change2(root2,1,n,b,c,a,d);
		}
	}
	for(int i=1;i<=cst;i++)
	{
		dis[i]=1e18;
	}
	dis[s]=0;
	vis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=h[x];i;i=e[i].next)
		{
			if(dis[e[i].to]>dis[x]+e[i].v)
			{
				dis[e[i].to]=dis[x]+e[i].v;
				if(!vis[e[i].to])
				{
					q.push(e[i].to);
					vis[e[i].to]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==1e18)
		{
			printf("-1 ");
		}
		else printf("%lld ",dis[i]);
	}
	return 0;
}