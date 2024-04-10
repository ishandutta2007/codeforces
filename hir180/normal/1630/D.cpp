#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rng(i, a, b) for(int i=(int)a;i<int(b);i++)
#define rep(i, b) rng(i, 0, b)
#define repn(i, b) rng(i, 1, b+1)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define si(x) int(x.size())

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0);
#endif

template<class t, class u>bool chmax(t&a, u b){if(a<b){a=b;return true;}else return false;}
template<class t, class u>bool chmin(t&a, u b){if(b<a){a=b;return true;}else return false;}

template<class t, class u>
ostream& operator<<(ostream& os, const pair<t,u>& p){
	return os<<"{"<<p.first<<","<<p.second<<"}";
}

template<class t>ostream& operator<<(ostream& os, const vector<t>&v){
	os<<"{";
	for(auto e:v) os<<e<<",";
	return os<<"}";
}
template<class t>using vc=vector<t>;
using P=pair<int,int>;
#define a first
#define b second
#define mp make_pair

void solve(){
	int n, m; cin >> n >> m;
	vc<ll>a(n);
	rep(i, n) cin >> a[i];
	int g = 0;
	rep(i, m){
		int b; cin >> b;
		g = gcd(g, b);
	}
	ll ans = -1e18;
	rep(p, 2){
		ll zan = 0;
		rep(i, g){
			vc<ll>num;
			for(int j=i;j<n;j+=g) num.pb(a[j]);
			sort(all(num));
			ll tmp = 0, now = -1e18;
			for(auto e:num) tmp += e;
			
			if(!p) now = tmp;
			for(int j=0;j<num.size();j++){
				tmp -= num[j] * 2;
				if((p+j)%2 == 1) chmax(now, tmp);
			}
			zan += now;
		}
		chmax(ans, zan);
	}
	cout<<ans<<'\n';
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	
	int t; cin >> t;
	while(t -- ) solve();
}