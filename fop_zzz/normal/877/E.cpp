#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define pb push_back
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
int poi[400001],nxt[400001],f[400001],cnt,n,m;
char opt[10];
struct tree{int v,sz;}	tr[1000001];
int tag[1000001];
int in[400001],out[400001],tim,on[400001],to[400001];
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=f[x];f[x]=cnt;}
inline void dfs(int x,int fa)
{
	in[x]=++tim;to[tim]=x;
	for(int i=f[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		dfs(poi[i],x);
	}
	out[x]=tim;
}
inline void up(int x)
{
	tr[x].v=tr[x<<1|1].v+tr[x<<1].v;
	tr[x].sz=tr[x<<1|1].sz+tr[x<<1].sz;
}
inline void build(int x,int l,int r)
{
	if(l==r)	{tr[x].v=on[to[l]];tr[x].sz=1;return;}
	int mid=l+r>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	up(x);
}
inline void push(int x)
{
	if(tag[x])
	{
		tag[x<<1]^=1;tag[x<<1|1]^=1;
		tr[x<<1].v=tr[x<<1].sz-tr[x<<1].v;tr[x<<1|1].v=tr[x<<1|1].sz-tr[x<<1|1].v;
		tag[x]=0;
	}
}
inline int ask(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)	return tr[x].v;
	int mid=l+r>>1;
	push(x);
	int sum=0;
	if(ql<=mid)	sum+=ask(x<<1,l,mid,ql,qr);
	if(qr >mid)	sum+=ask(x<<1|1,mid+1,r,ql,qr);
	up(x);
	return sum;	
}
inline void change(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		tr[x].v=tr[x].sz-tr[x].v;
		tag[x]^=1;
		return;
	}
	int mid=l+r>>1;
	push(x);
	if(ql<=mid)	change(x<<1,l,mid,ql,qr);
	if(qr >mid)	change(x<<1|1,mid+1,r,ql,qr);
	up(x);
}
int main()
{
	n=read();
	For(i,1,n-1)	add(read(),i+1);
	For(i,1,n)	on[i]=read();
	dfs(1,1);
	build(1,1,n);
	m=read();
	For(i,1,m)
	{
		scanf("%s",opt+1);
		if(opt[1]=='g')	
		{	
			int x=read();
			printf("%d\n",ask(1,1,n,in[x],out[x]));
		}
		else
		{
			int x=read();
			change(1,1,n,in[x],out[x]);
		}
	}
}