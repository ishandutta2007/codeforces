#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 200001
int T,N,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],deg[MAXN],siz[MAXN];ll ans;bool vis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v){deg[u]++,deg[v]++;to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
void dfs(int u,int f){siz[u]=1;FOR(i,u)if(vis[to[i]]&&to[i]!=f)dfs(to[i],u),siz[u]+=siz[to[i]];}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)fst[i]=0,siz[i]=0,vis[i]=0,deg[i]=0;cnt=0;For(i,1,N)add(get(),get());ans=1ll*N*(N-1);queue<int>q;For(i,1,N)if(deg[i]==1)q.push(i),vis[i]=1;
		while(!q.empty()){int u=q.front();q.pop();FOR(i,u)if(!vis[to[i]])deg[to[i]]--,deg[to[i]]==1?q.push(to[i]),vis[to[i]]=1:0;}For(i,1,N)if(!vis[i])dfs(i,0),ans-=1ll*siz[i]*(siz[i]-1)/2;put(ans),putchar('\n');
	}
	return 0;
}