#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const ll mod = 1000000007;
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int n,k;
int dp[205][100005];
ll bin[100005],rev[100005];
int sub[100005];
vector<int>edge[100005];
ll ans[205];
int t[2][3][205];
void dfs(int v,int u){
	sub[v] = 1;
	int cur = 0, nxt = 1;
	rep(i,edge[v].size()){
		int to = edge[v][i];
		if(to == u) continue;
		dfs(to,v);
	}
	memset(t,0,sizeof(t));
	t[0][0][0] = 1;
	rep(i,edge[v].size()){
	    int to = edge[v][i];
		if(to == u) continue;
		rep(j,3)rep(a,k+1) t[nxt][j][a] = 0;
		rep(j,3) rep(a,min(k+1,sub[v])){
			if(t[cur][j][a] == 0) continue;
			t[nxt][j][a] += 1LL * t[cur][j][a] * bin[sub[to]] % mod;
			if(t[nxt][j][a] >= mod) t[nxt][j][a] -= mod;
		}
		rep(j,3) rep(a,min(k+1,sub[v])){
			if(t[cur][j][a] == 0 || a == k) continue;
			t[nxt][min(2,j+1)][a+1] += 1LL * t[cur][j][a] * (bin[sub[to]]-1) % mod;
			if(t[nxt][min(2,j+1)][a+1] >= mod) t[nxt][min(2,j+1)][a+1] -= mod;
			if(j+1 == 1){
				ans[a+1] += (bin[sub[to]]-1) % mod * (bin[n-sub[to]]-1) % mod;
			}
		}
		rep(j,3) rep(a,min(k+1,sub[v])){
			if(t[cur][j][a] == 0) continue;
			rep(b,min(k+1,sub[to])){
				if(a+b > k) continue;
				ll v = dp[b][to];
				if(b == 0) continue;
				
				t[nxt][min(2,j+1)][a+b] += 1LL * t[cur][j][a] * v % mod;
				if(t[nxt][min(2,j+1)][a+b] >= mod) t[nxt][min(2,j+1)][a+b] -= mod;
				if(a+b+1 > k) continue;
				if(a == 0 && b){
				    ans[b+1] += v * (bin[n-sub[to]]-1) % mod;
				}
				t[nxt][min(2,j+1)][a+b+1] += 1LL * t[cur][j][a] * v % mod;
				if(t[nxt][min(2,j+1)][a+b+1] >= mod) t[nxt][min(2,j+1)][a+b+1] -= mod;
			}
		}
		sub[v] += sub[to];
		swap(cur,nxt);
	}
	repn(i,k) repn(j,2){
		dp[i][v] += 1LL * t[cur][j][i] * 2LL % mod;
		if(dp[i][v] >= mod) dp[i][v] -= mod;
		if(j == 2) ans[i] += t[cur][j][i] * bin[n+1-sub[v]] % mod;
	}
}
ll coef[205][205];
ll F[205],R[205];
void make(){
	F[0] = 1;
	for(int i=1;i<205;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<205;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	bin[0] = 1;
	for(int i=1;i<100005;i++) bin[i] = bin[i-1]*2LL%mod;
	ll rv = (mod+1)/2;
	rev[0] = 1;
	for(int i=1;i<100005;i++) rev[i] = rev[i-1]*rv%mod;
	dfs(1,-1);
	make();
	coef[0][0] = 1;
	for(int i=1;i<205;i++){
		for(int j=1;j<=i;j++){
			//coef[i][j]?
			for(int k=1;k<=i;k++){
				coef[i][j] += coef[i-k][j-1] * C(i,k) % mod;
				coef[i][j] %= mod;
			}
		}
	}
	ll ret = 0;
	for(int i=1;i<=k;i++){
		ret += ans[i]%mod * coef[k][i] % mod;
	}
	cout << (ret%mod+mod)%mod << endl;
}