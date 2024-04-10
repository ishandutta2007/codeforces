#include<bits/stdc++.h>
using namespace std;
#define N 55
const int mod=998244353;
const int inv2=(mod+1)/2;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int a[N],n,siz[N];
vector<int> G[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
long double dp[N][N];
void dfs(int u,int fa){
	dp[u][0]=siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		static long double g[N];
		for(int i=0;i<siz[u];++i){
			for(int j=0;j<siz[v];++j){
				long double w=dp[u][i]*dp[v][j];
				g[i+j+1]+=w*(0.5/(j+1)-1);
				g[i+j]+=w;
			}
		}
		siz[u]+=siz[v];
		for(int i=0;i<siz[u];++i)dp[u][i]=g[i],g[i]=0;
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int rt=1;rt<=n;++rt){
		long double ans=1;
		dfs(rt,0);
		for(auto v:G[rt]){
			long double sum=0;
			for(int j=0;j<siz[v];++j){
				sum+=dp[v][j]*0.5/(j+1);
			}
			ans*=sum;
		}
		double tmp=ans;
		printf("%.10lf\n",tmp);
	}
	dfs(1,0);
	return 0;
}