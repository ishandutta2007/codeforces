#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,T;
vector<int> G[N]; 
bool ok;
ll dp[N][2],p[N],h[N];
inline ll Abs(ll x){
	return x>=0?x:-x;
}
void dfs(int u,int fa){
	if(!ok)return;
	dp[u][0]=p[u];
	dp[u][1]=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		dp[u][0]+=dp[v][0];
		dp[u][1]+=dp[v][1];
	}
	if(dp[u][1]-dp[u][0]>h[u]||Abs(dp[u][1]-dp[u][0]-h[u])&1){
		ok=false;
		return;
	}
	ll sum=dp[u][0]+dp[u][1];
	dp[u][1]=(sum+h[u])/2,dp[u][0]=(sum-h[u])/2;
	if(dp[u][1]<0||dp[u][0]<0){
		ok=false;
		return;
	}
}
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
	}
	for(int i=1;i<=n;++i){
		h[i]=read();
	}
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ok=true;
	dfs(1,0);
	printf(ok?"YES\n":"NO\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	
	return 0;
}