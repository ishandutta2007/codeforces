#include<iostream>
#include<queue>
using namespace std;
#define pb push_back
typedef long long ll;
const ll mod=1e9+7;
const int N=1e5+1,K=201;
int n,k;
ll dp[N][K],dp2[N][K];
ll f[N];
ll st[K][K];
ll tot[K];
int sz[N],dsz[N];
vector<int>adj[N];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
void tmw(){//tmw is very op
	f[0]=1;
	for(int i=1; i<=n ;i++) f[i]=(f[i-1]*i)%mod;
	st[0][0]=1;
	for(int i=1; i<=k ;i++){
		for(int j=1; j<=i ;j++) st[i][j]=(st[i-1][j-1]+j*st[i-1][j])%mod;
	}
}
void dfs(int id,int p){
	sz[id]=1;
	int maxi=0;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs(cur,id);
		sz[id]+=sz[cur];
		if(sz[cur]>sz[maxi]) maxi=cur;
	}
	for(int i=0; i<adj[id].size() ;i++){
		if(adj[id][i]==maxi) swap(adj[id][i],adj[id][0]);
	}
	dsz[id]=min(sz[id],k);
}
void solve(int id,int p){
	dp[id][0]=dp2[id][0]=1;
	int sum=0;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		solve(cur,id);
		for(int i=dsz[cur]-1; i>=0 ;i--) dp[cur][i+1]=(dp[cur][i+1]+dp[cur][i])%mod;
		dp[cur][0]++;
		for(int i=0; i<=dsz[cur] ;i++) dp2[id][i]=(dp2[id][i]+dp[cur][i])%mod;
		dp2[id][0]=(dp2[id][0]+mod-1)%mod;
		for(int i=min(k,sum+dsz[cur]); i>=0 ;i--){
			dp[id][i]=dp[id][i]*dp[cur][0]%mod;
			for(int j=max(1,i-sum); j<=min(i,dsz[cur]) ;j++){
				dp[id][i]=(dp[id][i]+dp[id][i-j]*dp[cur][j])%mod;
			}
		}
		sum=min(k,sum+dsz[cur]);
	}
	for(int i=0; i<=dsz[id] ;i++){
		dp[id][i]*=2;
		tot[i]=(tot[i]+dp[id][i]-dp2[id][i]+mod)%mod;
	}
	dp[id][0]=(dp[id][0]+mod-1)%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	tmw();
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	solve(1,0);
	ll ans=0;
	for(int i=0; i<=k ;i++){
		ans=ans+tot[i]*f[i]%mod*st[k][i]%mod;
		ans%=mod;
	}
	cout << ans << '\n';
}