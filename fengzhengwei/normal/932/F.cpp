#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int a[xx];
int b[xx];
struct nod
{
	int next,to;
}e[xx<<1];
int cnt;
int h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
struct node
{
	int l,r;
	ll k,b;
}w[xx<<5];
int n;
int root[xx];
int cst;
ll res(ll x,ll k,ll b)
{
	return k*x+b;
}
void insert(int &k,int l,int r,ll x,ll y)
{
	if(!k)return k=++cst,w[k].k=x,w[k].b=y,void();
	int mid=l+r>>1;
	if(w[k].k<=x)
	{
		if(res(mid,w[k].k,w[k].b)<=res(mid,x,y))((l!=r)?insert(w[k].l,l,mid,x,y):void());
		else ((l!=r)?insert(w[k].r,mid+1,r,w[k].k,w[k].b):void()),w[k].k=x,w[k].b=y;
	}
	else 
	{
		if(res(mid,w[k].k,w[k].b)<=res(mid,x,y))((l!=r)?insert(w[k].r,mid+1,r,x,y):void());
		else ((l!=r)?insert(w[k].l,l,mid,w[k].k,w[k].b):void()),w[k].k=x,w[k].b=y;
	}
}
ll ans;
void ask(int k,int l,int r,int x)
{
	if(!k)return;
	ans=min(ans,res(x,w[k].k,w[k].b));
	int mid=l+r>>1;
	if(x<=mid)ask(w[k].l,l,mid,x);
	else ask(w[k].r,mid+1,r,x);
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y)return x+y;
	int mid=l+r>>1;
	w[x].l=merge(w[x].l,w[y].l,l,mid);
	w[x].r=merge(w[x].r,w[y].r,mid+1,r);
	insert(x,l,r,w[y].k,w[y].b);
	return x;
}
ll f[xx];
void dfs(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		root[x]=merge(root[x],root[e[i].to],-100000,100000);
	}
	ans=1e18;
	ask(root[x],-100000,100000,a[x]);f[x]=ans;
	if(!root[x])f[x]=0;
	insert(root[x],-100000,100000,b[x],f[x]);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)cout<<f[i]<<" \n"[i==n];
	return 0;
}