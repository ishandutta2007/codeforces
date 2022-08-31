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
 
ll val[(1<<20)];
short dp[(1<<20)],ok[(1<<20)];
int n;
ll a[20];
vector<pair<ll,int>>vec;
ll aa[20];
int main(){
	cin >> n;
	rep(i,n) cin >> aa[i];
	int m = 0;
	rep(i,n) if(aa[i]) a[m++] = aa[i];
	n = m;
	
	rep(i,(1<<n)){
		rep(j,n) if(((i>>j)&1)) val[i] += a[j];
		vec.pb(mp(val[i],i));
	}
	SORT(vec);
	rep(i,(1<<n)){
		int x = __builtin_popcount(i);
		if(x <= 1) continue;
		if( (val[i]%2+2)%2 == x%2 ) continue;
		
		ll lb = val[i]-(x-1); lb /= 2;
		ll ub = val[i]+(x-1); ub /= 2;
		int a = POSL(vec,mp(lb,-1));
		int b = POSL(vec,mp(ub+1,-1));
		
		if(b-a < (1<<x)){
			for(int ii=a;ii<b;ii++){
				if( (vec[ii].sc&i) == vec[ii].sc && vec[ii].sc && vec[ii].sc < i){
					ok[i] = 1;
					break;
				}
			}
		}
		else{
			int mask = i;
			int cur = i;
			while(cur){
				cur = (cur-1)&mask;
				if(cur == 0) break;
				if(lb <= val[cur] && val[cur] <= ub){
					ok[i] = 1; break;
				}
			}
		}
	}
	
	dp[0] = 0;
	rep(i,(1<<n)){
		if(i == 0) continue;
		int mask = i;
		int cur = i;
		while(cur){
			cur = (cur-1)&mask;
			if(dp[i] < dp[cur]+ok[i^cur]) dp[i] = dp[cur]+ok[i^cur];
		}
	}
	
	cout << n-(int)(dp[(1<<n)-1]) << endl;
}