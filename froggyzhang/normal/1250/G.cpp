#include<bits/stdc++.h>
using namespace std;
#define N 3003
const int mod=1e9+7;
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
int n,m,a[N],vis[N<<1],dep[N],tot,ans;
vector<pair<int,int> > G[N];
void dfs(int u){
	for(auto [v,id]:G[u]){
		if(vis[id])continue;
		if(v==1){
			a[++tot]=dep[u]+1;
			vis[id]=1;
			continue;
		}
		dep[v]=dep[u]+1;
		vis[id]=1;
		dfs(v);
	}
}
void Solve_1(){
	static int dp[N][N<<1];
	dp[0][n]=1;
	for(int i=1;i<=tot;++i){
		for(int j=a[i];j<=(n<<1);++j){
			dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
		}
		for(int j=(n<<1)-a[i];j>=0;--j){
			dp[i][j]=(dp[i][j]+dp[i-1][j+a[i]])%mod;
		}
	}
	ans=dp[tot][n];
}
vector<array<int,2> > calc(vector<array<int,2> > dp,int l,int r){
	for(int i=l;i<=r;++i){
		vector<array<int,2> > F(n<<1|1,{0,0});
		for(int p=0;p<=1;++p){
			for(int j=a[i];j<=(n<<1);++j){
				F[j][p]=(F[j][p]+dp[j-a[i]][p])%mod;
			}
			for(int j=(n<<1)-a[i];j>=0;--j){
				F[j][p]=(F[j][p]+dp[j+a[i]][p])%mod;
			}
			for(int j=0;j<=(n<<1);++j){
				F[j][1]=(F[j][1]+dp[j][p])%mod;
			}
		}
		dp=F;
	}
	return dp;
}
void Solve(int L,int R,vector<array<int,2> > &dp){
	if(L==R){
		for(int x=1;x<a[L];++x){
			ans=(ans+2LL*(dp[n+a[L]-2*x][0]+dp[n+a[L]-2*x][1]))%mod;
		}
		for(int x=0;x<a[L];++x){
			ans=(ans+2LL*dp[n+a[L]-1-2*x][0])%mod;		
		}
		for(int x=1;x<a[L]-1;++x){
			ans=(ans+2LL*dp[n+a[L]-1-2*x][1])%mod;		
		}
		return;	
	}
	int mid=(L+R)>>1;
	auto dpL=calc(dp,L,mid),dpR=calc(dp,mid+1,R);
	Solve(L,mid,dpR),Solve(mid+1,R,dpL);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
	}
	dfs(1);
	Solve_1();
	vector<array<int,2> > beg(n<<1|1,{0,0});
	beg[n][0]=1;
	Solve(1,tot,beg);
	printf("%d\n",ans);
	return 0;
}