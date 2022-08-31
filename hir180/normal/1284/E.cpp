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

int n;
ll x[2505],y[2505];
ll ans;
ll choose(ll a,ll b){
	ll ret = 1;
	for(ll i = a ; i >= a-b+1;i--) ret = ret*i;
	repn(i,b) ret /= i;
	return ret;
}
bool ccw(P a,P b,P c)
{
	return 1LL*(b.fi-a.fi)*(c.sc-a.sc)-1LL*(b.sc-a.sc)*(c.fi-a.fi) > 0;
}
bool ccw(int a,int b,int c){
	return ccw(mp(x[a],y[a]),mp(x[b],y[b]),mp(x[c],y[c]));
}
int main(){
	cin >> n;
	rep(i,n) cin >> x[i] >> y[i];
	
	rep(p,n){
		vector<pair<long double,int>>vec;
		rep(i,n){
			if(i == p) continue;
			long double th = atan2((long double)(y[i]-y[p]),(long double)(x[i]-x[p]));
			vec.pb(mp(th,i));
			vec.pb(mp(th+2.0*acos((long double)(-1.0)),i));
		}
		SORT(vec);
		
		rep(i,n-1){
			long double lim = vec[i].fi + acos((long double)(-1.0));
			int a = POSL(vec,mp(lim,-1));
			ll num = 0;
			for(int j=max(i+1,a-3);j<=min(a+3,2*n-3);j++){
				if(ccw(p,vec[i].sc,vec[j].sc) == false){
					num = j-i-1; break;
				}
			}
			
			ans -= choose(num,3);
		}
		ans += choose(n-1,4);
	}
	
	cout << ans << endl;
}