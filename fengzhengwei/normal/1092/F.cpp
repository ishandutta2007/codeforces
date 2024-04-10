#include<bits/stdc++.h>
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
struct node
{
	int next,to;
}e[400005];
int h[200005];
int cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int n;
long long c[200005];
long long size[200005];
long long f[200005];
void dfs(int x,int y,long long d)
{
	f[1]+=d*c[x];
	size[x]=c[x];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x,d+1);
		size[x]+=size[e[i].to];
	}
}
void dp(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		f[e[i].to]=f[x]-size[e[i].to]+size[1]-size[e[i].to];
		dp(e[i].to,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,0,0);
	dp(1,0);
	long long ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}