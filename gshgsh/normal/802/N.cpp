#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=now[u];i;i=nxt[i])
#define INF 0x3fffffffffffffff
#define MAXN 5001
#define MAXM 50001
int N,M,s,t,fst[MAXN],now[MAXN],cnt=1,to[MAXM*2],nxt[MAXM*2];ll flow[MAXM*2],len[MAXM*2],dis[MAXN],ans,cost;bool in[MAXN],vis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,ll l,ll f){to[++cnt]=v,len[cnt]=l,flow[cnt]=f,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,len[cnt]=-l,flow[cnt]=0,nxt[cnt]=fst[v],fst[v]=cnt;}
bool spfa()
{
	For(i,s,t)dis[i]=INF,in[i]=vis[i]=0;queue<int>q;dis[s]=0;q.push(s);in[s]=1;
	while(!q.empty()){int u=q.front();q.pop();in[u]=0;now[u]=fst[u];FOR(i,u)if(flow[i]&&dis[to[i]]>dis[u]+len[i]){dis[to[i]]=dis[u]+len[i];if(!in[to[i]])q.push(to[i]),in[to[i]]=1;}}return dis[t]!=INF;
}
ll dfs(int u,ll in)
{
	if(u==t||!in)return in;ll tmp,ans=0;vis[u]=1;
	FOR(i,u)if(!vis[to[i]]&&flow[i]&&dis[to[i]]==dis[u]+len[i]){now[u]=i;tmp=dfs(to[i],min(in,flow[i]));if(!tmp)vis[to[i]]=1;else in-=tmp,ans+=tmp,flow[i]-=tmp,flow[i^1]+=tmp,cost+=tmp*len[i];if(!in)break;}vis[u]=0;return ans;
}
int main(){N=get(),M=get(),s=0,t=N*2+2;For(i,1,N)add(s,i,get(),1);For(i,1,N)add(i,i+N,0,1),add(i+N,N*2+1,get(),1);For(i,1,N-1)add(i+N,i+N+1,0,INF);add(N*2+1,t,0,M);while(spfa())ans+=dfs(s,INF);cout<<cost<<'\n';return 0;}