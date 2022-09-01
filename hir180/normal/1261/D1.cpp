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
#define mod 998244353 
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k,a[2005];
ll dp[2005][4005];

int main(){
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	dp[0][2002] = 1;
	rep(i,n){
		for(int j=0;j<4005;j++){
			if(dp[i][j] == 0) continue;
			int x = a[i]; int y = a[(i+1)%n];
			if(x == y){
				dp[i+1][j] += dp[i][j] * k % mod;
				if(dp[i+1][j] >= mod) dp[i+1][j] -= mod;
			}
			else{
				for(int x=-1;x<=1;x+=2){
					dp[i+1][j+x] += dp[i][j] % mod;
					if(dp[i+1][j+x] >= mod) dp[i+1][j+x] -= mod;
				}
				dp[i+1][j] += dp[i][j] * (k-2) % mod;
				if(dp[i+1][j] >= mod) dp[i+1][j] -= mod;
			}
		}
	}
	ll ans = 0;
	for(int i=2003;i<4005;i++) ans += dp[n][i];
	cout << (ans%mod+mod)%mod << endl;
}