#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define ll __int128
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 2001
int N,M,K,u[MAXN],v[MAXN],w[MAXN],dis[MAXN][MAXN],x[MAXN],y[MAXN],k[MAXN],b[MAXN];vector<pair<int,int>>E[MAXN];bool vis[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get(),K=get();For(i,1,M)u[i]=get(),v[i]=get(),w[i]=get();
	For(i,1,M)E[u[i]].push_back({v[i],w[i]}),E[v[i]].push_back({u[i],w[i]});
	For(i,1,N)For(j,0,N)dis[i][j]=-1;queue<pair<int,int>>q;q.push({1,0});vis[1][0]=1;dis[1][0]=0;
	while(!q.empty())
	{
		auto tmp=q.front();q.pop();int u=tmp.first,t=tmp.second;if(t==N)continue;
		for(auto i:E[u]){int v=i.first,w=i.second;if(dis[v][t+1]<dis[u][t]+w)dis[v][t+1]=dis[u][t]+w;if(!vis[v][t+1])q.push({v,t+1}),vis[v][t+1]=1;}
	}
	For(i,1,M)k[i]=w[i],b[i]=-2e9;ll ans=0;
	For(i,1,min(N,K))
	{
		For(j,1,M){if(~dis[u[j]][i])b[j]=max(b[j],dis[u[j]][i]-i*k[j]);if(~dis[v[j]][i])b[j]=max(b[j],dis[v[j]][i]-i*k[j]);}
		int tmp=0;For(j,1,M)tmp=max(tmp,k[j]*i+b[j]);ans+=tmp;
	}
	For(i,1,M)
	{
		int l=N+1,r=K;
		For(j,1,M)if(i!=j)
		{
			if(k[i]==k[j]){if(b[i]<b[j]||b[i]==b[j]&&i<j){l=N+1;r=N;break;}}
			else if(k[i]>k[j])l=max(l,(b[j]-b[i])/(k[i]-k[j])+1);
			else r=min(r,(b[j]-b[i])/(k[i]-k[j]));
		}
		if(l<=r)ans+=(ll)(r-l+1)*b[i],ans+=(ll)(r-l+1)*(l+r)/2*k[i];
	}
	cout<<(long long)(ans%P)<<'\n';return 0;
}