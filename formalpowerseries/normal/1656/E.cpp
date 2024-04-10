#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
vector<int> G[100005];
int n,val[100005],sp[100005];
void dfs(int u,int pre)
{
	val[u]=sp[u]*int(G[u].size());
	for(auto v:G[u])
	{
		if(v==pre)	continue;
		sp[v]=sp[u]*-1;
		dfs(v,u);
	}
}
void Solve()
{
	n=read();
	for(int i=1;i<=n;++i)	G[i].clear(),val[i]=0;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sp[1]=1;
	dfs(1,0);
	for(int i=1;i<=n;++i)	write(val[i]),putchar(i==n?'\n':' ');
}
int main(){
	int T=read();
	while(T-->0)	Solve();
	return 0;
}