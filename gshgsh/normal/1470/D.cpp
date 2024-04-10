#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 300001
int T,N,M,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],tot,ans[MAXN];bool vis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get(),tot=0;For(i,1,N)fst[i]=vis[i]=0;cnt=0;For(i,1,M)add(get(),get());
		queue<int>q;q.push(1);while(!q.empty()){int u=q.front();q.pop();if(vis[u])continue;vis[u]=1,ans[++tot]=u;FOR(i,u)if(!vis[to[i]]){FOR(j,to[i])q.push(to[j]);vis[to[i]]=1;}}
		int cnt=0;For(i,1,N)cnt+=vis[i];if(cnt<N){cout<<"NO\n";continue;}cout<<"YES\n"<<tot<<endl;sort(ans+1,ans+tot+1);For(i,1,tot)cout<<ans[i]<<' ';cout<<endl;
	}
	return 0;
}