#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
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
int n,f[xx][2],vis[xx<<1],ds[xx];
vector<int>Bl[xx][2];// 
//01 
void dfs(int x,int y)
{
	int g[3]={0,0,0};//01,2 
	int bl[3][2]={0,0,0,0,0,0};
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		if(g[2]+min(f[e[i].to][0],f[e[i].to][1])+1>g[1]+f[e[i].to][1])bl[2][0]=bl[1][0],bl[2][1]=i;
		g[2]=min(g[2]+min(f[e[i].to][0],f[e[i].to][1])+1,g[1]+f[e[i].to][1]);
		if(g[1]+min(f[e[i].to][0],f[e[i].to][1])+1>g[0]+f[e[i].to][1])bl[1][0]=i;
		g[1]=min(g[1]+min(f[e[i].to][0],f[e[i].to][1])+1,g[0]+f[e[i].to][1]);
		g[0]+=min(f[e[i].to][0],f[e[i].to][1])+1;
	}
	Bl[x][0].clear();
	Bl[x][1].clear();
	ds[x]=0;
	f[x][0]=g[2];
	f[x][1]=min(g[0],g[1]);
	if(f[x][1]==g[1])Bl[x][1].push_back(bl[1][0]);
	Bl[x][0].push_back(bl[2][0]),Bl[x][0].push_back(bl[2][1]);
}
void dfss(int x,int y,int op)
{
	if(op==2)
	{
		if(f[x][0]<f[x][1])op=0;
		else op=1;
	}
	for(auto it:Bl[x][op])if(it)vis[it]=vis[it^1]=1,ds[e[it].to]++,ds[x]++,dfss(e[it].to,x,1);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[i])continue;
		dfss(e[i].to,x,2); 
	}
}
int last=0;
int vs[xx];
void dfsss(int x,int y)
{
	last=x;vs[x]=1;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y&&vis[i])dfsss(e[i].to,x);
}
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		memset(vis,0,sizeof(vis[0])*(cnt+1));
		memset(vs,0,sizeof(vs[0])*(n+1));
		memset(e,0,sizeof(e[0])*(cnt+1));
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=1;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
			add(a,b),add(b,a);
		}
		dfs(1,0);
		dfss(1,0,2);
		vector<pair<int,int> >v;
		vector<pair<int,int> >v1;
		for(int i=2;i<=cnt;i+=2)
		{
			if(vis[i])continue;
			v.push_back(make_pair(e[i].to,e[i^1].to));
		}
		last=0;
		for(int i=1;i<=n;i++)
		{
			if((ds[i]==1||ds[i]==0)&&!vs[i])
			{
				if(last)v1.push_back(make_pair(last,i));
//				cout<<i<<" ss "<<last<<"\n";
				dfsss(i,0);
			}
		}
		cout<<min(f[1][0],f[1][1])<<"\n";
//		for(auto it:v)cout<<it.first<<" "<<it.second<<"\n";
		for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<" "<<v1[i].first<<" "<<v1[i].second<<"\n";
	}
	return 0;
}