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
int n;
struct node
{
	int next,to;
}e[1000005];
int cnt;
int h[1000005];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
void wdd(int x,int y)
{
	add(x,y);
	add(y,x);
}
ll f[1000005];
ll size[1000005];
int res;
void dfs(int x,int y)
{
	size[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		f[x]+=f[e[i].to];
	}
	f[x]+=size[x];
}
ll g[1000005];
ll ans=0;
void dp(int x,int y)
{
	ans=max(ans,f[x]+g[x]-size[x]+size[1]);
//	cout<<x<<' '<<f[x]<<" "<<g[x]<<endl;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		g[e[i].to]=size[1]-size[e[i].to]+f[x]-f[e[i].to]+g[x]-size[x];
		dp(e[i].to,x);
	}
}
int main(){
	n=read();
	for(int i=2;i<=n;i++)wdd(read(),read());
	dfs(1,0);
	dp(1,0);
	cout<<ans<<endl;
	return 0;
}