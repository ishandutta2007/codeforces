#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,M,K,deg[MAXN],u[MAXN],v[MAXN],ans,res[MAXN];vector<int>E[MAXN];map<int,map<int,int>>vis;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get(),K=get();For(i,1,M)deg[u[i]=get()]++,deg[v[i]=get()]++,E[u[i]].push_back(v[i]),E[v[i]].push_back(u[i]),vis[u[i]][v[i]]=vis[v[i]][u[i]]=1;
	ans=N;queue<int>q;For(i,1,N)if(deg[i]<K)q.push(i);
	while(!q.empty()){int u=q.front();q.pop();ans--;for(auto v:E[u])if(vis[u][v]){if(--deg[v]==K-1)q.push(v);vis[u][v]=vis[v][u]=0;}}
	FOR(i,M,1)
	{
		res[i]=ans;if(!vis[u[i]][v[i]])continue;deg[u[i]]--;deg[v[i]]--;vis[u[i]][v[i]]=vis[v[i]][u[i]]=0;if(deg[u[i]]==K-1)q.push(u[i]);if(deg[v[i]]==K-1)q.push(v[i]);
		while(!q.empty()){int u=q.front();q.pop();ans--;for(auto v:E[u])if(vis[u][v]){if(--deg[v]==K-1)q.push(v);vis[u][v]=vis[v][u]=0;}}
	}
	For(i,1,M)cout<<res[i]<<'\n';return 0;
}