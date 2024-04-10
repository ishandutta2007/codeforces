#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,k;
struct node
{
	int next,to;
}e[200005];
int h[100005];
int cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[100005];
int sef[100005];
int pos[100005];
int c[100005];
void dfs(int x,int y)
{
	if(c[x])f[x]=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		if(f[e[i].to]!=-1)
		{
			if(f[e[i].to]+1>f[x])
			{
				sef[x]=f[x];
				pos[x]=e[i].to;
				f[x]=f[e[i].to]+1;
			}
			else if(f[e[i].to]+1>sef[x])
			{
				sef[x]=f[e[i].to]+1;
			}
		}
	}
//	cout<<x<<" "<<f[x]<<" "<<sef[x]<<endl;
}
int ddp[100005];
int res;
void dp(int x,int y)
{
	if(c[x])ddp[x]=max(ddp[x],0);
	int ans=0;
	ans=max(ans,f[x]);
	ans=max(ans,ddp[x]);
//	cout<<x<<" "<<ans<<endl;
	if(ans<=k)res++;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(ddp[x]!=-1)
		ddp[e[i].to]=max(ddp[e[i].to],ddp[x]+1);
		if(pos[x]==e[i].to)
		{
			if(sef[x]!=-1)
			{
				ddp[e[i].to]=max(ddp[e[i].to],sef[x]+1);
			}
		}
		else 
		{
			if(f[x]!=-1)
			{
				ddp[e[i].to]=max(ddp[e[i].to],f[x]+1);
			}
		}
		dp(e[i].to,x);
	}
}
int main(){
	memset(f,-1,sizeof(f));
	memset(ddp,-1,sizeof(ddp));
	memset(sef,-1,sizeof(sef));
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		c[read()]=1;
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	dp(1,0);
	cout<<res<<endl;
	return 0;
}