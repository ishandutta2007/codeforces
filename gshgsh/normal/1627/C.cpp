#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,u[MAXN],v[MAXN],deg[MAXN],ans[MAXN];vector<pair<int,int>>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f,int p){for(auto v:E[u])if(v.first!=f)ans[v.second]=p,dfs(v.first,u,5-p);}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)deg[i]=0,E[i].clear();For(i,1,N-1)u[i]=get(),v[i]=get(),deg[u[i]]++,deg[v[i]]++;
		int mx=0;For(i,1,N)mx=max(mx,deg[i]);if(mx>2){cout<<"-1\n";continue;}
		For(i,1,N-1)E[u[i]].push_back({v[i],i}),E[v[i]].push_back({u[i],i});int x=1;while(deg[x]==2)x++;
		dfs(x,0,2);For(i,1,N-1)cout<<ans[i]<<" \n"[i==N-1];
	}
	return 0;
}