#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN],dep[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){dep[u]=dep[f]+1;for(auto v:E[u])if(v!=f)dfs(v,u);}
void dfs2(int u,int f){for(auto v:E[u])if(v!=f)a[u]-=a[v];for(auto v:E[u])if(v!=f)dfs2(v,u);}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)E[i].clear();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
		dfs(1,0);a[1]=0;For(i,2,N)a[i]=dep[i]&1?1:-1;dfs2(1,0);For(i,1,N)cout<<a[i]<<" \n"[i==N];
	}
}