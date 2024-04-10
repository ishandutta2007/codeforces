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
ll arr[61][2][2];
void prepare2(){
	arr[0][0][1] = arr[0][1][0] = arr[0][1][1] = 1;
	rep(k,60){
		rep(a,2)rep(b,2)rep(c,2) add(arr[k+1][a][c], arr[k][a][b]*arr[k][b][c]%mod);
	}
}
ll fib(ll n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(n == 2) return 2;
	ll cur[2]; cur[0] = 1; cur[1] = 2;
	n -= 2;
	rep(i,61){
		if(((n>>i)&1LL)){
			ll nxt[2] = {};
			rep(a,2)rep(b,2){
				nxt[a] += arr[i][a][b] * cur[b] % mod;
			}
			rep(a,2) cur[a] = (nxt[a]%mod+mod)%mod;
		}
	}
	return cur[1];
}
pair<ll,ll> ans[61][61];

ll modpow(ll x,ll n){
    x %= mod;
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[105],R[105];
void make(){
	F[0] = 1;
	for(int i=1;i<105;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<105;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
void prepare(){
	rep(i,41){
		ans[0][i] = mp(1, 0);
		ans[1][i] = mp(1, modpow(2, i));
	}
	for(int i=2;i<=60;i++){
		ll len = (1LL<<i) / 2;
		for(int k=0;k<=40;k++){
			ll c[2] = {fib(len-2), fib(len-1)};
			ll d[2] = {fib(len-1), fib(len)};
			ans[i][k] = ans[i-1][k];
			for(int up=0;up<=k;up++){
				ll coef = C(k, up) * modpow(len % mod, up) % mod;
				add(ans[i][k].fi, c[0] * ans[i-1][k-up].fi % mod * coef % mod);
				add(ans[i][k].sc, c[1] * ans[i-1][k-up].fi % mod * coef % mod);
				add(ans[i][k].fi, d[0] * ans[i-1][k-up].sc % mod * coef % mod);
				add(ans[i][k].sc, d[1] * ans[i-1][k-up].sc % mod * coef % mod);
			}
		}
	}
}
ll n, k;
int main(){
    make();
    prepare2();
	prepare();
	cin >> n >> k;
	ll res = 0;
	ll cur = 0;
	for(int i=60;i>=0;i--){
		if(!((n>>i)&1LL)) continue;
		ll a = fib(cur + 1);
		ll b = fib(cur + 2);
		if(i == 0){
			res += a * modpow(n % mod, k) % mod;
			break;
		}
		for(int up=0;up<=k;up++){
			ll coef = C(k, up) * modpow(cur % mod, up) % mod;
			res += ans[i][k-up].fi * coef % mod * a % mod;
			res += ans[i][k-up].sc * coef % mod * b % mod;
		}
		cur += (1LL<<i);
	}
	cout << (res%mod+mod)%mod << endl;
}