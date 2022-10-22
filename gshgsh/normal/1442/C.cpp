#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,t) for(int i=fst[u][t];i;i=nxt[i][t])
#define Pair pair<int,int>
#define mp make_pair
#define INF 0x3fffffff
#define P 998244353
#define MAXN 200001
int N,M,fst[MAXN][2],cnt,to[MAXN][2],nxt[MAXN][2],dis[MAXN][20],ans,Dis[MAXN];bool in[MAXN][20];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt][0]=v,nxt[cnt][0]=fst[u][0],fst[u][0]=cnt;to[cnt][1]=u,nxt[cnt][1]=fst[v][1],fst[v][1]=cnt;}
int main()
{
	N=get(),M=get();For(i,1,M){int u=get(),v=get();add(u,v);}For(i,1,N)For(j,0,18)if(i!=1||j)dis[i][j]=INF;queue<Pair>q;q.push(mp(1,0));in[1][0]=1;
	while(!q.empty())
	{
		int u=q.front().first,t=q.front().second;q.pop();in[u][t]=0;if(t<18&&dis[u][t+1]>dis[u][t]+(1<<t))dis[u][t+1]=dis[u][t]+(1<<t),!in[u][t+1]?q.push(mp(u,t+1)),in[u][t+1]=1:0;
		FOR(i,u,t&1)if(dis[to[i][t&1]][t]>dis[u][t]+1)dis[to[i][t&1]][t]=dis[u][t]+1,!in[to[i][t&1]][t]?q.push(mp(to[i][t&1],t)),in[to[i][t&1]][t]=1:0;
	}
	ans=INF;For(i,0,18)ans=min(ans,dis[N][i]);if(ans!=INF){cout<<ans<<endl;return 0;}
	For(i,2,N)Dis[i]=INF;queue<int>Q,Q1;Q.push(1),Q1.push(1);
	For(t,0,INF)
	{
		if(Dis[N]!=INF){ans=Dis[N];int tmp=1;For(i,1,t-1)tmp=1ll*tmp*2%P;ans=(ans+tmp-1)%P;break;}
		while(!Q.empty()){int u=Q.front();Q.pop();FOR(i,u,t&1)if(Dis[to[i][t&1]]>Dis[u]+1)Dis[to[i][t&1]]=Dis[u]+1,Q.push(to[i][t&1]),Q1.push(to[i][t&1]);}
		while(!Q1.empty())Q.push(Q1.front()),Q1.pop();
	}
	cout<<ans<<endl;return 0;
}