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
int n;
struct node
{
	int next,to;
}e[xx<<1];
int cnt;
int h[xx];
void adds(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int size[xx];
int son[xx];
void dfs(int x,int y)
{
	size[x]=1;
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxx)maxx=size[e[i].to],son[x]=e[i].to;
	}
}
int maxx;
int val[xx];
int t[xx];
ll res;
void clear(int x,int y)
{
	t[val[x]]--;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)clear(e[i].to,x);
}
void add(int x,int y)
{
	t[val[x]]++;
	if(t[val[x]]>maxx)res=0,maxx=t[val[x]];
	if(t[val[x]]==maxx)res+=val[x];
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)add(e[i].to,x);
}
ll ans[xx];
void dfss(int x,int y)
{
//	cout<<x<<endl;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||e[i].to==son[x])continue;
		dfss(e[i].to,x);
		maxx=res=0;
		clear(e[i].to,x);
	}
	if(son[x])dfss(son[x],x);
	t[val[x]]++;
	if(t[val[x]]>maxx)res=0,maxx=t[val[x]];
	if(t[val[x]]==maxx)res+=val[x];
//	cout<<x<<" "<<maxx<<" "<<res<<" "<<t[val[x]]<<endl;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y&&e[i].to!=son[x])add(e[i].to,x);
	ans[x]=res;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		adds(a,b);
		adds(b,a);
	}
	dfs(1,0);
	dfss(1,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return 0;
}