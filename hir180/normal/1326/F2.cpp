//Let's join Kaede Takagaki Fun Club !!
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
string f[20];
vector<int>part[(1<<17)];
map<vector<int>, ll> ans;
ll tmp[18][(1<<18)], val[19][(1<<18)];
ll dp[(1<<18)];
ll way[(1<<17)];
vector<int>M[18];
void prepare(){
	rep(mask,(1<<(n-1))){
		int a[20];
		rep(i,n-1) a[i] = ((mask>>i)&1);
		int cur = 1;
		rep(i,n-1){
			if(a[i] == 1) cur++;
			else{
				part[mask].pb(cur);
				cur = 1;
			}
		}
		part[mask].pb(cur);
		SORT(part[mask]);
	}
	
	rep(i,n) tmp[i][(1<<i)] = 1;
	rep(mask,(1<<n)){
		rep(i,n){
			if( !((mask>>i)&1) ) continue;
			if(tmp[i][mask] == 0) continue;
			rep(j,n){
				if( ((mask>>j)&1) ) continue;
				if(f[i][j] == '0') continue;
				tmp[j][mask^(1<<j)] += tmp[i][mask];
			}
		}
	}
	rep(i,n+1){
	    rep(j,(1<<n)) if(__builtin_popcount(j) == i) rep(k,n) val[i][j] += tmp[k][j];
		rep(k,n)rep(j,(1<<n)){
			if(((j>>k)&1)) val[i][j] += val[i][j^(1<<k)];
		}
	}
}
void rec(vector<int>vec, int sum){
	if(sum == n){
		ll res = 0;
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)%2 == n%2) res += dp[i];
			else res -= dp[i];
		}
		ans[vec] = res;
		return;
	}
	int v = (vec.empty()?1:vec.back());
	if(sum+v > n) return;
	vector<ll>zip(1<<n);
	rep(i,(1<<n)) zip[i] = dp[i];
	for(int a=v;a+sum<=n;a++){
		if(sum == 0){
			rep(i,(1<<n)) dp[i] = val[a][i];
		}
		else{
			rep(i,(1<<n)) dp[i] *= val[a][i];
		}
		vec.pb(a);
		rec(vec, sum+a);
		vec.pop_back();
	    rep(i,(1<<n)) dp[i] = zip[i];
	}
}
int main(){
	//ios::sync_with_stdio(false);
	g(n); rep(i,n) g(f[i]);
	prepare();
	rec(vector<int>(), 0);
	rep(i,(1<<(n-1))) way[i] = ans[part[i]];
	rep(j,n-1){
		rep(i,(1<<(n-1))) {
			if(((i>>j)&1)) continue;
			way[i] -= way[i^(1<<j)];
		}
	}
	rep(i,(1<<(n-1))) printf("%lld ",way[i]);
}