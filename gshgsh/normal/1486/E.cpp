#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define Pair pair<int,int>
#define Thair pair<ll,Pair>
#define mp make_pair
#define F first
#define S second
#define MAXN 400001
int N,M,fst[MAXN],cnt,to[MAXN],len[MAXN],nxt[MAXN];ll dis[MAXN][51];bool vis[MAXN][51];
void add(int u,int v,int l){to[++cnt]=v,len[cnt]=l,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,len[cnt]=l,nxt[cnt]=fst[v],fst[v]=cnt;}
int main()
{
	cin>>N>>M;For(i,1,M){int u,v,l;cin>>u>>v>>l;add(u,v,l);}
	priority_queue<Thair,vector<Thair>,greater<Thair> >q;memset(dis,0x3f,sizeof(dis));dis[1][0]=0;q.push(mp(0,mp(1,0)));
	while(!q.empty())
	{
		while(!q.empty()&&vis[q.top().S.F][q.top().S.S])q.pop();if(q.empty())break;int u=q.top().S.F,t=q.top().S.S;q.pop();vis[u][t]=1;
		FOR(i,u)if(dis[to[i]][t?0:len[i]]>dis[u][t]+len[i]*len[i]+2*t*len[i])dis[to[i]][t?0:len[i]]=dis[u][t]+len[i]*len[i]+2*t*len[i],q.push(mp(dis[to[i]][t?0:len[i]],mp(to[i],t?0:len[i])));
	}
	For(i,1,N)cout<<(dis[i][0]==0x3f3f3f3f3f3f3f3f?-1:dis[i][0])<<' ';return 0;
}