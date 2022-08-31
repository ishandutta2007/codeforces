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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
ll c;
ll p[10005],s[10005];
ll dp[2][10005];


int main(){
	cin >> n >> c;
	rep(i,n) cin >> p[i];
	rep(i,n) cin >> s[i];
	rep(a,2)rep(b,10005)dp[a][b] = 1e18;
	
	dp[0][0] = 0;
	int cur = 0, nxt = 1;
	
	rep(i,n){
		rep(x,10005) dp[nxt][x] = 1e18;
		rep(x,10005){
			if(dp[cur][x] > 5e17) continue;
			//ox
			dp[nxt][x+1] = min(dp[nxt][x+1],dp[cur][x]+s[i]);
			//xx
			//dp[nxt][x] = min(dp[nxt][x],dp[cur][x]+s[i]+p[i]);
			//xo
			dp[nxt][x] = min(dp[nxt][x],dp[cur][x]+p[i]+c*x);
		}
		swap(cur,nxt);
	}
	
	
	ll ans = 1e18;
	rep(x,10005)ans = min(ans,dp[cur][x]);
	cout << ans << endl;
}