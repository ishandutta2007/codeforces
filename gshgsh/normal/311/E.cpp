#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=now[u];i;i=nxt[i])
#define INF 0x3fffffff
#define MAXN 20001
#define MAXM 1000001
int N,M,G,s,t,a[MAXN],fst[MAXN],now[MAXN],cnt=1,to[MAXM],flow[MAXM],nxt[MAXM],dep[MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,int f){to[++cnt]=v,flow[cnt]=f,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,flow[cnt]=0,nxt[cnt]=fst[v],fst[v]=cnt;}
bool bfs()
{
	memset(dep,-1,sizeof(dep));queue<int>q;dep[s]=0;q.push(s);
	while(!q.empty()){int u=q.front();q.pop();now[u]=fst[u];if(u==t)return 1;FOR(i,u)if(flow[i]&&dep[to[i]]==-1)dep[to[i]]=dep[u]+1,q.push(to[i]);}return 0;
}
int dfs(int u,int in)
{
	if(u==t||!in)return in;int tmp,ans=0;
	FOR(i,u){now[u]=i;if(flow[i]&&dep[to[i]]==dep[u]+1){tmp=dfs(to[i],min(in,flow[i]));if(!tmp)dep[to[i]]=-1;else in-=tmp,ans+=tmp,flow[i]-=tmp,flow[i^1]+=tmp;if(!in)break;}}return ans;
}
int main()
{
	N=get(),M=get(),G=get(),s=0,t=N+M+1;For(i,1,N)a[i]=get();For(i,1,N)a[i]?add(s,i,get()):add(i,t,get());
	For(i,1,M){int b=get(),w=get(),cnt=get();ans+=w;For(j,1,cnt){int c=get();b?add(i+N,c,INF):add(c,i+N,INF);}int c=get();b?add(s,i+N,w+c*G):add(i+N,t,w+c*G);}
	while(bfs())ans-=dfs(s,INF);cout<<ans<<endl;return 0;
}