#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
int n,m;
const int xx=1e5+5;
struct node{int next,to;}e[xx<<1];
int h[xx],cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
vector<int>v[2];
int col[xx];
void dfs(int x,int y)
{
	if(col[x]!=-1)
	{
		if(y!=col[x])puts("-1"),exit(0);
		return;
	}
	col[x]=y;
	v[col[x]].push_back(x);
	for(int i=h[x];i;i=e[i].next)dfs(e[i].to,y^1);
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;i++)if(col[i]==-1)dfs(i,0);
	cout<<v[0].size()<<"\n";
	for(auto it:v[0])cout<<it<<" ";
	puts("");
	cout<<v[1].size()<<"\n";
	for(auto it:v[1])cout<<it<<" ";
	return 0;
}