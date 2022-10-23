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

using P=pair<int,int>;

void solve(){
	int n, k; cin >> n >> k;
	if(n == 4 and k == 3){
		cout << -1 << '\n';
	}
	else if(k == n-1){
		cout<<n/2-1<<" "<<n-1<<'\n';
		cout<<n/2<<" "<<n-2<<'\n';
		cout<<0<<" "<<1<<'\n';
		for(int i=2;i<n/2-1;i++){
			cout<<i<<" "<<n-1-i<<'\n';
		}
	}
	else{
		cout<<k<<" "<<n-1<<'\n';
		if(k) cout<<0<<" "<<n-1-k<<'\n';
		for(int i=1;i<n/2;i++){
			if(i == min(k, n-1-k)) continue;
			cout<<i<<" "<<n-1-i<<'\n';
		}
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	
	int t; cin >> t;
	while(t -- ) solve();
}