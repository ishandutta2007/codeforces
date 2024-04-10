#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 0x3fffffffffffffff
#define MAXN 601
int N,M;ll dis[MAXN];bool vis[MAXN];vector<Pair>E[MAXN*MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dij(int s)
{
	For(i,0,N-1)dis[i]=INF,vis[i]=0;for(auto i:E[s])dis[i.F]=i.S;
	For(i,1,N)
	{
		int u=-1;For(j,0,N-1)if(!vis[j]&&(u==-1||dis[j]<dis[u]))u=j;if(u==-1)break;vis[u]=1;
		if(dis[u])dis[(u+1)%N]=min(dis[(u+1)%N],dis[u]+1);for(auto j:E[u])dis[(j.F+dis[u])%N]=min(dis[(j.F+dis[u])%N],dis[u]+j.S);
	}
	For(i,0,N-1)cout<<(i==s?0:dis[i])<<" \n"[i==N-1];
}
int main(){N=get(),M=get();For(i,1,M){int u=get(),v=get(),w=get();E[u].pb({v,w});}For(i,0,N-1)dij(i);return 0;}