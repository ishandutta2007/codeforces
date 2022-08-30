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
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}

int n,a,b;
ll p[2005],u[2005];
pair<ll,int> dp[2005][2005];
int use[2005][2005];

void calc_dp(ll mid){
	rep(i,n+1) rep(j,n+1) dp[i][j] = mp(-1e18,-INF);
	dp[0][0] = mp(0,0);
	rep(i,n){
		rep(j,i+1){
			if(dp[i][j].fi <= -5e17) continue;
			//xx
			chmax(dp[i+1][j],dp[i][j]);
			//xo
			chmax(dp[i+1][j],mp(dp[i][j].fi+u[i+1]*1000-mid, dp[i][j].sc+1));
			//ox
			chmax(dp[i+1][j+1],mp(dp[i][j].fi+p[i+1]*1000, dp[i][j].sc));
			//oo
			chmax(dp[i+1][j+1],mp(dp[i][j].fi+1000000-(1000-u[i+1])*(1000-p[i+1])-mid, dp[i][j].sc+1));
		}
	}
	for(int i=2;i<=n;i++){
		assert(dp[n][i].fi-dp[n][i-1].fi <= dp[n][i-1].fi-dp[n][i-2].fi);
	}
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	repn(i,n){
		double d; scanf("%lf",&d);
		p[i] = (ll)floor(d*1000.+0.5);
	}
	repn(i,n){
		double d; scanf("%lf",&d);
		u[i] = (ll)floor(d*1000.+0.5);
	}
	ll lb = 0, ub = 1000005;
	while(ub-lb > 1){
		ll mid = (lb+ub)/2;
		calc_dp(mid);
		if(dp[n][a].sc < b) ub = mid;
		else{
			lb = mid;
		}
	}
	calc_dp(lb);
	
	long double ret = (long double)(dp[n][a].fi+lb*b) / 1e6;
	printf("%.20Lf\n",ret);
}