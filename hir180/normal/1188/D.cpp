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
ll a[100005];
vector<pair<ll,int> >vec[60];
vector<int>rui[60];
ll dp[60][100005];
int main(){
	scanf("%d",&n);
	int mx = 0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ll V = 0;
		for(int j=0;j<59;j++){
			if( ((a[i]>>j)&1LL) ) {mx = max(mx,j); V += 1LL<<j;}
			vec[j].pb(mp(V,i)); //if(j==0)cout<<V<<endl;
		}
	}
	rep(i,60) rep(j,100005) dp[i][j] = 1e18;
	dp[0][n] = 0;
	for(int j=0;j<=mx;j++) sort(vec[j].begin(),vec[j].end());
	for(int j=0;j<=mx;j++){
		int R = 0;
		for(int k=0;k<vec[j].size();k++){
			int id = vec[j][k].sc;
			if( ((a[id]>>(j+1))&1LL) ) R++;
			rui[j+1].pb(R);
		}
	}int R = 0;
	for(int k=0;k<vec[0].size();k++){
			int id = vec[0][k].sc;
			if( ((a[id]>>0)&1LL) ) R++;
			rui[0].pb(R);
		}
	for(int j=0;j<=mx;j++){
		for(int i=0;i<=n;i++){
			//dp[j][i] -> ?
			//0
			int val = (i?rui[j][i-1]:0);
			int all = rui[j][n-1]; all -= val;
			dp[j+1][i-val] = min(dp[j+1][i-val],dp[j][i]+val+(n-i)-all);
			//1
			dp[j+1][n-all] = min(dp[j+1][n-all],dp[j][i]+(i-val)+all);
		}
		//for(int i=0;i<=n;i++) cout << dp[j+1][i] << " " << j << " " << i << endl;
	}
	ll ans = dp[mx+1][n]; //cout << ans << endl;
	for(int i=0;i<n;i++) ans = min(ans,dp[mx+1][i]+i);
	cout << ans << endl;
}