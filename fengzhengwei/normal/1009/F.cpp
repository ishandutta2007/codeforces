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
const int xx=1e6+5;
int n;
struct node
{
	int next,to;
}e[xx<<1];
int h[xx];
int cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int d[xx];
int son[xx];
int md[xx];
void dfs(int x,int y)
{
	d[x]=d[y]+1;
	md[x]=d[x];
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		md[x]=max(md[x],md[e[i].to]);
		if(md[e[i].to]>maxx)maxx=md[e[i].to],son[x]=e[i].to;
	}
}
int g[xx];
int *f[xx];
int *id;
int ans[xx];
void dfss(int x,int y)
{
	if(son[x])
	{
		f[son[x]]=f[x]+1;
		dfss(son[x],x);
	}
	ans[x]=ans[son[x]]+1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||e[i].to==son[x])continue;
		f[e[i].to]=id;
		id+=(md[e[i].to]-d[e[i].to]+1);
		dfss(e[i].to,x);
		for(int j=0;j<=md[e[i].to]-d[e[i].to];j++)
		{
			f[x][j+1]+=f[e[i].to][j];
			if(f[x][j+1]>f[x][ans[x]]||(f[x][j+1]==f[x][ans[x]]&&j+1<ans[x]))ans[x]=j+1;
		}
	}
	f[x][0]++;
	if(f[x][0]>f[x][ans[x]]||(f[x][0]==f[x][ans[x]]&&0<ans[x]))ans[x]=0;
}
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	id=g;
	f[1]=id;
	id+=(md[1]-d[1]+1);
	dfss(1,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";
	return 0;
}