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

const ll mod = 998244353;
vector<int>edge[2][4005];
int n[2],k;
map<P,ll>subtree_dp[2][80];
map<int,pair<int,ll>>subtree_zip[2][80];
ll sum[2][80];
ll C[80][80];

void make(int id,int u,int v){
	if(subtree_dp[id][2].find(P(u,v)) != subtree_dp[id][2].end()) return ;
	ll pr[80]={};
	subtree_dp[id][0][P(u,v)] = 1;
	if(subtree_zip[id][2].find(v) != subtree_zip[id][2].end()){
		int pre = subtree_zip[id][2][v].fi;
		make(id,v,u);
		make(id,v,pre);
		for(int len=2;len<=k;len++){
			subtree_dp[id][len][P(u,v)] = subtree_zip[id][len][v].sc;
			subtree_dp[id][len][P(u,v)] -= subtree_dp[id][len-2][P(v,u)];
			subtree_dp[id][len][P(u,v)] += subtree_dp[id][len-2][P(v,pre)];
			subtree_dp[id][len][P(u,v)] %= mod;
			pr[len] = subtree_dp[id][len][P(u,v)];
		}
	}
	else{
		for(int len=2;len<=k;len+=2){
			rep(i,edge[id][v].size()){
				int x = edge[id][v][i];
				if(x == u) continue;
				make(id,v,x);
				subtree_dp[id][len][P(u,v)] += subtree_dp[id][len-2][P(v,x)];
			}
			subtree_dp[id][len][P(u,v)] %= mod;
			subtree_zip[id][len][v] = mp(u,subtree_dp[id][len][P(u,v)]);
			pr[len] = subtree_dp[id][len][P(u,v)];
		}
	}
	ll DP[80]={};
	for(int i=2;i<=k;i+=2){
		for(int j=2;j<i;j+=2){
			DP[i] += DP[i-j] * pr[j] % mod;
		}
		subtree_dp[id][i][P(u,v)] += DP[i]%mod;
		subtree_dp[id][i][P(u,v)] %= mod;
		DP[i] = (DP[i]+pr[i])%mod;
	}
	return ;
}

int main(){
	rep(i,80) rep(j,i+1){
		if(j == 0 || j == i) C[i][j] = 1;
		else C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
	}
	cin >> n[0] >> n[1] >> k;
	rep(i,n[0]-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[0][a].pb(b);
		edge[0][b].pb(a);
	}
	rep(i,n[1]-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[1][a].pb(b);
		edge[1][b].pb(a);
	}
	rep(q,2){
		repn(i,n[q]){
			rep(j,edge[q][i].size()){
				make(q,i,edge[q][i][j]);
			}
		}
		repn(v,n[q]){
			ll DP[80]={}, pr[80]={};
			for(int len=2;len<=k;len+=2){
				rep(i,edge[q][v].size()){
					int x = edge[q][v][i];
					pr[len] += subtree_dp[q][len-2][mp(v,x)];
				}
				pr[len] %= mod;
			}
			sum[q][0] ++;
			for(int i=2;i<=k;i+=2){
				for(int j=2;j<i;j+=2){
					DP[i] += DP[i-j] * pr[j] % mod;
				}
				DP[i] = (DP[i]+pr[i])%mod;
				sum[q][i] += DP[i];
				sum[q][i] %= mod;
			}
		}
	}
	ll ans = 0;
	rep(i,k+1) ans += sum[0][i] * sum[1][k-i] % mod * C[k][i] % mod;
	cout << (ans%mod+mod)%mod << endl;
}