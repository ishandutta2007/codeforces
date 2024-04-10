#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,*f[MAXN],mx[MAXN],son[MAXN],ans[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs0(int u,int f){for(auto v:E[u])if(v!=f)dfs0(v,u),mx[u]<mx[v]+1&&(mx[u]=mx[v]+1,son[u]=v);}
void dfs(int u,int p)
{
	f[u][0]=1;if(!son[u])return;f[son[u]]=f[u]+1;dfs(son[u],u);ans[u]=ans[son[u]]+1;
	for(auto v:E[u])if(v!=p&&v!=son[u]){f[v]=new int[mx[v]+1];dfs(v,u);For(i,0,mx[v])f[u][i+1]+=f[v][i],(f[u][i+1]>f[u][ans[u]]||(f[u][i+1]==f[u][ans[u]]&&i+1<ans[u]))&&(ans[u]=i+1);}
	if(f[u][ans[u]]==1)ans[u]=0;
}
int main()
{
	N=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	dfs0(1,0);f[1]=new int[mx[1]+1];dfs(1,0);For(i,1,N)cout<<ans[i]<<'\n';return 0;
}