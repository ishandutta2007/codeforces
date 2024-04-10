#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define Pair pair<int,int>
#define mp make_pair
#define F first
#define S second
#define MAXN 1001
int N,M,K,u[MAXN],v[MAXN],x[MAXN],y[MAXN],fst[MAXN],cnt,to[MAXN*2],len[MAXN*2],nxt[MAXN*2],dis[MAXN][MAXN],ans;bool vis[MAXN];
void add(int u,int v,int l){to[++cnt]=v,len[cnt]=l,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,len[cnt]=l,nxt[cnt]=fst[v],fst[v]=cnt;}
int main()
{
	cin>>N>>M>>K;For(i,1,M){int l;cin>>u[i]>>v[i]>>l;add(u[i],v[i],l);}For(i,1,K)cin>>x[i]>>y[i];
	For(s,1,N)
	{
		memset(dis[s],0x3f,sizeof(dis[s]));memset(vis,0,sizeof(vis));dis[s][s]=0;priority_queue<Pair,vector<Pair>,greater<Pair> >q;q.push(mp(0,s));
		while(!q.empty()){while(!q.empty()&&vis[q.top().S])q.pop();if(q.empty())break;int u=q.top().S;q.pop();vis[u]=1;FOR(i,u)if(dis[s][to[i]]>dis[s][u]+len[i])dis[s][to[i]]=dis[s][u]+len[i],q.push(mp(dis[s][to[i]],to[i]));}
	}
	For(i,1,K)ans+=dis[x[i]][y[i]];For(i,1,M){int sum=0;For(j,1,K)sum+=min(dis[x[j]][y[j]],min(dis[x[j]][u[i]]+dis[v[i]][y[j]],dis[x[j]][v[i]]+dis[u[i]][y[j]]));ans=min(ans,sum);}cout<<ans<<endl;return 0;
}