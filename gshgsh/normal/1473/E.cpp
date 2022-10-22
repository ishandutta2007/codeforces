#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define Pair pair<int,int>
#define Tair pair<ll,Pair>
#define mp make_pair
#define F first
#define S second
#define MAXN 200001
int N,M,fst[MAXN],cnt,to[MAXN*2],len[MAXN*2],nxt[MAXN*2];ll dis[MAXN][4];bool vis[MAXN][4];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,int l){to[++cnt]=v,len[cnt]=l,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,len[cnt]=l,nxt[cnt]=fst[v],fst[v]=cnt;}
int main()
{
	N=get(),M=get();For(i,1,M){int u=get(),v=get(),l=get();add(u,v,l);}memset(dis,0x3f,sizeof(dis));dis[1][0]=0;priority_queue<Tair,vector<Tair>,greater<Tair> >q;q.push(mp(0,mp(1,0)));
	while(!q.empty())
	{
		int u=q.top().S.F,f=q.top().S.S;q.pop();while(!q.empty()&&vis[u][f])u=q.top().S.F,f=q.top().S.S,q.pop();vis[u][f]=1;
		FOR(i,u)
		{
			if(dis[to[i]][f]>dis[u][f]+len[i])dis[to[i]][f]=dis[u][f]+len[i],q.push(mp(dis[to[i]][f],mp(to[i],f)));
			if((f+1&1)&&dis[to[i]][f+1]>dis[u][f])dis[to[i]][f+1]=dis[u][f],q.push(mp(dis[to[i]][f+1],mp(to[i],f+1)));
			if(f<2&&dis[to[i]][f+2]>dis[u][f]+len[i]*2)dis[to[i]][f+2]=dis[u][f]+len[i]*2,q.push(mp(dis[to[i]][f+2],mp(to[i],f+2)));
		}
	}
	For(i,2,N)cout<<min(dis[i][0],dis[i][3])<<' ';return 0;
}