#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
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
vector<tuple<int,int,int> >v;
int vis[xx],V[xx<<1];// 
void dfs(int x,int y)
{
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
		if(!vis[e[i].to])dfs(e[i].to,x);
	vector<int>to;
	for(int i=h[x];i;i=e[i].next)if(!V[i]&&e[i].to!=y)to.push_back(i);
	int res=0;
	for(int i=h[x];i;i=e[i].next)if(e[i].to==y)res=i;
	for(int i=0;i<to.size();i+=2)
	{
		if(i!=to.size()-1)v.push_back(make_tuple(e[to[i]].to,x,e[to[i+1]].to)),V[to[i]]=V[to[i]^1]=V[to[i+1]]=V[to[i+1]^1]=1;
		else 
		{
			if(!res)break;
			to.push_back(res);
			v.push_back(make_tuple(e[to[i]].to,x,e[to[i+1]].to)),V[to[i]]=V[to[i]^1]=V[to[i+1]]=V[to[i+1]^1]=1;
		}
	}
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i,0);
	cout<<v.size()<<"\n";
	for(auto it:v)cout<<get<0>(it)<<" "<<get<1>(it)<<" "<<get<2>(it)<<"\n";
	return 0;
}