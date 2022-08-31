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
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int n;
ll a[500005];
ll rui[60][500005], cur[60];
void solve(){
	scanf("%d", &n);
	repn(i, n) scanf("%lld", &a[i]);
	repn(i, n){
		rep(j, 60){
			rui[j][i] = rui[j][i-1];
			if( (a[i] & (1LL<<j)) ) rui[j][i] ++;
		}
	}
	rep(j, 60) cur[j] = 0;
	ll ans = 0;
	repn(i, n){
		ll le = 0, ri = 0;
		rep(j, 60){
			if( (a[i] & (1LL<<j)) == 0) continue;
			
			le += (1LL<<j)%mod * rui[j][n] % mod;
		}
		rep(j, 60){
			if( (a[i] & (1LL<<j)) == 0){
				ri += (1LL<<j)%mod * (rui[j][n]) % mod;
			}
			else{
				ri += (1LL<<j)%mod * (n) % mod;
			}
		}
		le %= mod;
		ri %= mod;
		ans += le * ri % mod;
	}
	cout << (ans%mod) << '\n';
}
int main(){
//	ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);
	while(t--) solve();
}