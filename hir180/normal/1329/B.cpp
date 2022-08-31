//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
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
#define all(x) x.begin(),x.end()
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
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
//const ll mod = 1000000007;//998244353

int d;
ll mod;
void solve(){
	cin >> d >> mod;
	vector<ll>vec;
	for(int i=1;;i++){
		ll beg = (1LL<<i)/2;
		ll en = (1LL<<i)-1;
		if(beg > d) break;
		vec.pb(min(en, 1LL*d) - beg + 1);
	}
	ll dp[35] = {};
	dp[0] = 1;
	for(int i=0;i<33;i++){
		for(int j=0;j<vec.size();j++){
			if(i >= j+1) continue;
			dp[j+1] += dp[i] * vec[j] % mod;
			if(dp[j+1] >= mod) dp[j+1] -= mod;
		}
	}
	ll ans = 0;
	repn(i, 33) ans = (ans + dp[i]) % mod;
	cout << ans << endl;
}
int main(){
	int t; cin >> t;
	while(t--) solve();
}