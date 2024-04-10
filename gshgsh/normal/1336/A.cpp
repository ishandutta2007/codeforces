#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,K,siz[MAXN],dep[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){siz[u]=1;for(auto v:E[u])if(v!=f)dep[v]=dep[u]+1,dfs(v,u),siz[u]+=siz[v];}
int main()
{
	N=get(),K=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	dfs(1,0);ll ans=0;priority_queue<pair<int,int>>q;For(i,1,N)q.push({dep[i]-siz[i]+1,i});
	while(K--){auto u=q.top();q.pop();ans+=u.first;}cout<<ans<<'\n';return 0;
}