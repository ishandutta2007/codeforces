#include<iostream>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 200001
int T,N,M,fst[MAXN],cnt,to[MAXN],nxt[MAXN],dep[MAXN],low[MAXN];
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;}
void dfs(int u){low[u]=dep[u];FOR(i,u)dep[u]<dep[to[i]]?low[to[i]]==-1?dfs(to[i]),0:0,low[u]=min(low[u],low[to[i]]):low[u]=min(low[u],dep[to[i]]);}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)fst[i]=0,dep[i]=low[i]=-1;cnt=0;For(i,1,M){int u,v;cin>>u>>v;add(u,v);}
		dep[1]=0;queue<int>q;q.push(1);while(!q.empty()){int u=q.front();q.pop();FOR(i,u)if(dep[to[i]]==-1)dep[to[i]]=dep[u]+1,q.push(to[i]);}
		dfs(1);For(i,1,N)cout<<low[i]<<' ';cout<<endl;
	}
	return 0;
}