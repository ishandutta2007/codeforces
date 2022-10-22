#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=now[u];i;i=nxt[i])
#define INF 0x3fffffff
#define MAXN 201
#define MAXM 100001
int N,M,goal[26],tot[MAXN][26],s,t,fst[MAXN],now[MAXN],cnt=1,to[MAXM],nxt[MAXM*2],len[MAXM],flow[MAXM],dis[MAXN],ans,cost;bool in[MAXN],vis[MAXN];string a;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,int l,int f){to[++cnt]=v,len[cnt]=l,flow[cnt]=f,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,len[cnt]=-l,flow[cnt]=0,nxt[cnt]=fst[v],fst[v]=cnt;}
bool spfa()
{
	memset(dis,0x3f,sizeof(dis));memset(in,0,sizeof(in));memset(vis,0,sizeof(vis));queue<int>q;dis[s]=0;q.push(s);in[s]=1;
	while(!q.empty()){int u=q.front();q.pop();in[u]=0;now[u]=fst[u];FOR(i,u)if(flow[i]&&dis[to[i]]>dis[u]+len[i]){dis[to[i]]=dis[u]+len[i];if(!in[to[i]])q.push(to[i]),in[to[i]]=1;}}return dis[t]!=0x3f3f3f3f;
}
int dfs(int u,int in)
{
	if(u==t||!in)return in;int tmp,ans=0;vis[u]=1;
	FOR(i,u)if(!vis[to[i]]&&flow[i]&&dis[to[i]]==dis[u]+len[i]){now[u]=i;tmp=dfs(to[i],min(in,flow[i]));if(!tmp)vis[to[i]]=1;else in-=tmp,ans+=tmp,flow[i]-=tmp,flow[i^1]+=tmp,cost+=tmp*len[i];if(!in)break;}vis[u]=0;return ans;
}
int main()
{
	cin>>a>>N,s=0,t=N+27;M=a.length();For(i,0,M-1)goal[a[i]-'a']++;For(i,0,25)add(s,i+1,0,goal[i]);For(i,1,N){int b;cin>>a>>b;add(i+26,t,i,b);int l=a.length();For(j,0,l-1)tot[i][a[j]-'a']++;For(j,0,25)add(j+1,i+26,0,tot[i][j]);}
	while(spfa())ans+=dfs(s,INF);if(ans<M){cout<<-1<<endl;return 0;}cout<<cost<<endl;return 0;
}