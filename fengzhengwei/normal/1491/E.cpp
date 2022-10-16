#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
int n,m;
const int xx=2e5+5;
struct node{int next,to;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[29],vis[xx<<1],size[xx];
map<int,int>mp;
vector<int>now;
void dfs(int x,int y)
{
	size[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[i])continue;
		now.push_back(i);
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
	}
}
bool check(int x)
{
	now.clear();
	dfs(x,0);
	if(!mp[size[x]])return 0;
	if(size[x]==1)return 1;
	for(auto it:now)
	if(mp[size[e[it].to]]&&mp[size[x]-size[e[it].to]])
	{
		vis[it]=vis[it^1]=1;
		return check(e[it].to)&check(e[it^1].to);
	}
	return 0;
}
signed main(){
	f[0]=1;f[1]=1;mp[1]=1;
	for(int i=2;i<=28;i++)f[i]=f[i-1]+f[i-2],mp[f[i]]=1;
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	
	if(check(1))puts("YES");
	else puts("NO");
	return 0;
}