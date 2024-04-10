#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define repn(i, n) for(int i=1;i<=n;i++)
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
typedef pair<ll, ll> P;
#define mp make_pair

P get(ll x){
	if(x == 0) return mp(0, 0);
	for(ll i=1;;i<<=2){
		if(i <= x && x < i*4);
		else continue;
		P p;
		int d;
		if(i <= x && x < i*2) p = get(x - i), d = 0;
		else if(i*2 <= x && x < i*3) p = get(x - i - i), d = 1;
		else if(i*3 <= x && x < i*4) p = get(x - i - i - i), d = 2;
		
		ll ar[3] = {p.a, p.b, p.a ^ p.b};
		rep(j, 3){
			if(ar[j] == x%i){
				//j = d
				return mp(ar[(j+3-d)%3]+i, ar[(j+4-d)%3]+i+i);
			}
		}
		assert(false);
	}
}
void solve(){
	ll n; cin >> n;
	for(ll i=1;;i<<=2){
		if(n > i*3){
			n -= i*3;
			continue;
		}
		ll p = (n+2)/3 - 1;
		ll q = (n+2)%3;
		auto ans = get(i + p);
		if(q == 0) cout << ans.a << '\n';
		if(q == 1) cout << ans.b << '\n';
		if(q == 2) cout << (ans.a ^ ans.b) << '\n';
		return;
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}