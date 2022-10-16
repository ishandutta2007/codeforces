#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
struct node
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int dep[xx];
int n,m,v[xx],siz[xx],mx[xx],cur;
ll ans;
void dfs(int x,int y)
{
	dep[x]=dep[y]+1;ans+=v[x]*dep[x];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
	}
}
void findc(int x,int y)
{
	siz[x]=v[x];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		findc(e[i].to,x);
		siz[x]+=siz[e[i].to];
		mx[x]=max(mx[x],siz[e[i].to]);
	}
	mx[x]=max(mx[x],m+m-siz[x]);
	if(!cur||mx[x]<mx[cur])cur=x;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m+m;i++)
		v[read()]++;
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	findc(1,0);
	dep[0]=-1;
	dfs(cur,0);
	cout<<ans<<"\n";
	return 0;
}