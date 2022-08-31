//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <iomanip>
#include <chrono>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
//#define L __int128
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define fi first
#define sc second
#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
 
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
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
//const ll mod = 998244353;
//const ll mod = 1000000007;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
/*template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
#define _sz 1
ll F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1]*i%mod;
	R[_sz-1] = modpow(F[_sz-1], mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	if(b < 0 || a < b) return 0;
	return F[a]*R[b]%mod*R[a-b]%mod;
}*/

int n, m, mod;
int way[505], sum[505];
int dp_way[2][505][505];
int dp_sum[2][505][505];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[505], R[505], C[505][505];
void solve(){
	cin >> n >> m >> mod;
	auto add = [&](int &a, int b){
		a += b;
		while(a >= mod) a-=mod;
		while(a < 0) a += mod;
	};
  F[0] = 1; for(int i=1;i<505;i++)F[i]=F[i-1]*i%mod;
  rep(i,505)R[i]=modpow(F[i],mod-2);
  auto CC=[&](int a,int b){
    if(a<b or b < 0)return 0LL;
    return F[a] * R[b] % mod * R[a-b] % mod;
  };
  rep(i,505)rep(j,505)C[i][j]=CC(i,j);
	way[0] = 1;
	sum[0] = 0;
	for(int i=1;i<=m;i++){
		repn(las, i){
			way[i] += way[las-1] * way[i-las] % mod * (i+1) % mod * C[i-1][las-1]%mod;
			sum[i] += sum[las-1] * way[i-las] % mod * (i+1) % mod * C[i-1][las-1]%mod;
			sum[i] += sum[i-las] * way[las-1] % mod * (i+1) % mod * C[i-1][las-1]%mod;
          int coef  = way[las-1] % mod * way[i-las] % mod * C[i-1][las-1]%mod;
			repn(des, i){
				sum[i] += abs(las - des) * coef % mod;
			}
		}
		way[i] %= mod;
		sum[i] %= mod;
	}

	repn(i, m){
		dp_way[1][i][i] = way[i];
		dp_sum[1][i][i] = sum[i];
	}
	repn(place, n){
		repn(human, m){
			rep(id, 2){
				//put vacant
				add(dp_way[0][human][place + 1],dp_way[id][human][place]);
				add(dp_sum[0][human][place + 1],dp_sum[id][human][place]);
				//put colony
				if(id == 1) continue;
				if(dp_way[id][human][place] == 0 and dp_sum[id][human][place] == 0) continue;
				repn(rem, min(m-human, n-place)){
					add(dp_way[1][human+rem][place+rem], dp_way[id][human][place] * C[human+rem][human] % mod * way[rem] % mod);
					add(dp_sum[1][human+rem][place+rem], dp_sum[id][human][place] * C[human+rem][human] % mod * way[rem] % mod);
					add(dp_sum[1][human+rem][place+rem], dp_way[id][human][place] * C[human+rem][human] % mod * sum[rem] % mod);
				}
			}
		}
	}
	int ans = 0;
	for(int i=m;i<=n;i++){
		add(ans, dp_sum[1][m][i] * (n+1-i) % mod);
	}
	o(ans);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}