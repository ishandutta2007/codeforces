#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,dep[N],ff[N][20],Q;
ll c[N],a[N];
struct Edge{
	int to;
	ll w1,w2;	
};
vector<Edge> G[N];
struct Matrix{
	ll g[2][2];
	Matrix(){memset(g,0x3f,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=0;i<=1;++i){
			for(int j=0;j<=1;++j){
				c.g[i][j]=min(inf,min(a.g[i][0]+b.g[0][j],a.g[i][1]+b.g[1][j]));		
			}
		}
		return c;
	}
}dp[N][20];
void dfs1(int u,int fa){
	ff[u][0]=fa;
	for(int j=1;j<=19;++j){
		ff[u][j]=ff[ff[u][j-1]][j-1];
	}
	dep[u]=dep[fa]+1;
	c[u]=a[u];
	for(auto t:G[u]){
		int v=t.to;
		if(v==fa)continue;
		dfs1(v,u);
		c[u]=min(c[u],c[v]+t.w1+t.w2);	
	}
}
void dfs2(int u,int fa){
	for(auto t:G[u]){
		int v=t.to;
		if(v==fa)continue;
		c[v]=min(c[v],c[u]+t.w1+t.w2);
		dfs2(v,u);
	}	
}
void dfs3(int u,int fa){
	for(int j=1;j<=19;++j){
		dp[u][j]=dp[u][j-1]*dp[ff[u][j-1]][j-1];
	}
	for(auto t:G[u]){
		int v=t.to;
		if(v==fa)continue;
		dp[v][0].g[0][0]=min(t.w1,t.w2+c[v]+c[u]);
		dp[v][0].g[0][1]=min(t.w1+c[u],t.w2+c[v]);
		dp[v][0].g[1][0]=min(t.w1+c[v],t.w2+c[u]);
		dp[v][0].g[1][1]=min(t.w1+c[u]+c[v],t.w2);
		dfs3(v,u);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<n;++i){
		int u,v;
		ll w1,w2;
		cin>>u>>v>>w1>>w2;
		G[u].push_back({v,w1,w2});
		G[v].push_back({u,w1,w2});
	}
	dfs1(1,0);
	dfs2(1,0);
	dfs3(1,0);
	cin>>Q;
	while(Q--){
		int u,v,tu,tv;
		cin>>u>>v;
		Matrix A,B;
		tu=!(u&1),tv=!(v&1);
		u=(u+1)/2,v=(v+1)/2;
		if(dep[u]<dep[v])swap(u,v),swap(tu,tv);
		A.g[tu][tu]=0,A.g[tu][tu^1]=c[u];
		B.g[tv][tv]=0,B.g[tv][tv^1]=c[v];
		for(int i=19;i>=0;--i){
			if(dep[ff[u][i]]>=dep[v]){
				A=A*dp[u][i];
				u=ff[u][i];
			}
		}
		for(int i=19;i>=0;--i){
			if(ff[u][i]^ff[v][i]){
				A=A*dp[u][i],B=B*dp[v][i];
				u=ff[u][i],v=ff[v][i];
			}
		}
		if(u^v)A=A*dp[u][0],B=B*dp[v][0];
		cout<<min(A.g[tu][0]+B.g[tv][0],A.g[tu][1]+B.g[tv][1])<<'\n';
	}
	return 0;
}