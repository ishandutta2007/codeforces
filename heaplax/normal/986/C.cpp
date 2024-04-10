#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int n,m,ans;
bool vis[1<<23],have[1<<22];
void dfs(int u)
{
	if(u<(1<<n) && !have[u])return;
	if(vis[u])return;
	vis[u]=1;
	if(u<(1<<n))
		dfs(u+(1<<n));
	else
	{
		for(int i=0;i<n;++i)
			if(!(u>>i&1))
				dfs(u|(1<<i));
		dfs(u^((1<<n+1)-1));
	}
}
int main()
{
	re(n),re(m);
	for(int i=1,x;i<=m;++i)
	{
		re(x);
		have[x]=1;
	}
	for(int i=0;i<(1<<n);++i)
		if(!vis[i] && have[i])
		{
			++ans;
			dfs(i);
		}
	printf("%d\n",ans);
}