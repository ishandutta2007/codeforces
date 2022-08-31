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
typedef vector<ll> vl;
typedef pair<vl,vl> t;

bitset<2005>dp[1<<16];
int n,k,a[16];
int dv[16];
vector<int>val[1005];
int main(){
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	
	dp[0][0] = 1;
	
	rep(mask,(1<<n)){
		for(int i=2000/k;i>=1;i--){
			if(dp[mask][i*k]) dp[mask][i] = 1;
		}
		rep(i,n){
			if(((mask>>i)&1)) continue;
			dp[mask ^ (1<<i)] |= dp[mask] << a[i];
		}
	}
	int cur_mask = (1<<n)-1;
	int cur_val = 1;
	if(dp[cur_mask][cur_val] == 0){
		puts("NO");
		return 0;
	}
	puts("YES");
	while(cur_mask){
		while(cur_val*k < 2005 && dp[cur_mask][cur_val*k]){
			rep(i,n) if(((cur_mask>>i)&1)) dv[i] ++;
			cur_val *= k;
		}
		rep(i,n){
			if(((cur_mask >> i)&1) && cur_val >= a[i] && dp[cur_mask^(1<<i)][cur_val-a[i]]){
				cur_mask ^= (1<<i);
				cur_val -= a[i];
				break;
			}
		}
	}
	//rep(i,n) cout << a[i] << " " << dv[i] << endl;
	int mx = -1;
	rep(i,n) {
		val[dv[i]].pb(a[i]);
		mx = max(mx,dv[i]);
	}
	
	for(int i=mx;i>=1;i--){
		while(val[i].size() >= 2){
			int x = val[i][val[i].size()-2];
			int y = val[i][val[i].size()-1];
			cout << x << " " << y << endl;
			rep(x,2) val[i].pop_back();
			int num = i;
			int v = x+y;
			while(v%k == 0){
				v /= k;
				num--;
			}
			val[num].pb(v);
		}
		assert(val[i].empty());
	}
	
}