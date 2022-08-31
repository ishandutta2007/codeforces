#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vector<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
void solve(){
	int n;
	ll mx = -1e18;
	cin >> n;
	ll dif = -1e18;
	rep(i, n){
		ll a; cin >> a;
		chmax(dif, mx - a);
		chmax(mx, a);
	}
	rep(i, 100){
		if(dif <= (1LL<<i)-1){
			cout<<i<<'\n';
			return;
		}
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}