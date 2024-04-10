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
#define all(x) x.begin(),x.end()
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
const ll mod = 998244353;
//const ll mod = 1000000007;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
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
}
int n, m;
bool f[105][105];
void solve(){
	cin >> n >> m;
	rep(i, n){
		string s; cin >> s;
		rep(j, m){
			f[i][j] = s[j] == '1';
		}
	}
	vc<int>ans;
	rep(i, n-2){
		rep(j, m-2){
			if(f[i][j]){
				ans.pb(i+1); ans.pb(j+1);
				ans.pb(i+2); ans.pb(j+1);
				ans.pb(i+1); ans.pb(j+2);
				f[i][j]^=1;
				f[i+1][j]^=1;
				f[i][j+1]^=1;
			}
		}
		int j = m-2;
		if(f[i][j] == 0 and f[i][j+1] == 0);
		else if(f[i][j] == 1 and f[i][j+1]){
				ans.pb(i+1); ans.pb(j+1);
				ans.pb(i+2); ans.pb(j+1);
				ans.pb(i+1); ans.pb(j+2);
				f[i][j]^=1;
				f[i+1][j]^=1;
				f[i][j+1]^=1;
		}
		else if(f[i][j] == 1){
				ans.pb(i+1); ans.pb(j+1);
				ans.pb(i+2); ans.pb(j+1);
				ans.pb(i+2); ans.pb(j+2);
				f[i][j]^=1;
				f[i+1][j]^=1;
				f[i+1][j+1]^=1;
		}
		else{
				ans.pb(i+2); ans.pb(j+2);
				ans.pb(i+2); ans.pb(j+1);
				ans.pb(i+1); ans.pb(j+2);
				f[i+1][j+1]^=1;
				f[i+1][j]^=1;
				f[i][j+1]^=1;
		}
	}
	rep(j, m-2){
		if(f[n-2][j] == 0 and f[n-1][j] == 0);
		else if(f[n-2][j] == 1 and f[n-1][j] == 1){
			ans.pb(n-2+1); ans.pb(j+1);
			ans.pb(n-1+1); ans.pb(j+1);
			ans.pb(n-2+1); ans.pb(j+1+1);
			f[n-2][j]^=1; f[n-1][j]^=1; f[n-2][j+1]^=1;
		}
		else if(f[n-2][j] == 1){
			ans.pb(n-2+1); ans.pb(j+1);
			ans.pb(n-1+1); ans.pb(j+1+1);
			ans.pb(n-2+1); ans.pb(j+1+1);
			f[n-2][j]^=1; f[n-1][j+1]^=1; f[n-2][j+1]^=1;
		}
		else{
			ans.pb(n-1+1); ans.pb(j+1+1);
			ans.pb(n-1+1); ans.pb(j+1);
			ans.pb(n-2+1); ans.pb(j+1+1);
			f[n-1][j+1]^=1; f[n-1][j]^=1; f[n-2][j+1]^=1;
		}
	}
	while(1){
		int cnt = 0;
		rep(i,2)rep(j,2) cnt += f[n-2+i][m-2+j];
		if(cnt == 0) break;
		else if(cnt == 4){
			ans.pb(n-2+1); ans.pb(m-2+1);
			ans.pb(n-1+1); ans.pb(m-2+1);
			ans.pb(n-2+1); ans.pb(m-1+1);
			f[n-2][m-2]^=1; f[n-1][m-2]^=1; f[n-2][m-1]^=1;
		}
		else if(cnt == 1){
			rep(i,2)rep(j,2){
				if(f[n-2+i][m-2+j] == 0){
					rep(a,2)rep(b,2){
						if(mp(i,j)!=mp(a,b)) {
							ans.pb(n-2+a+1);
							ans.pb(m-2+b+1);
							f[n-2+a][m-2+b] ^= 1;
						}
					}
					goto nxt;
				}
			}
			nxt:;
		}
		else if(cnt == 2){
			rep(i,2)rep(j,2){
				if(f[n-2+i][m-2+j] == 1){
					rep(a,2)rep(b,2){
						if(mp(i,j)!=mp(a,b)) {
							ans.pb(n-2+a+1);
							ans.pb(m-2+b+1);
							f[n-2+a][m-2+b] ^= 1;
						}
					}
					goto nxt2;
				}
			}
			nxt2:;
		}
		else{
			rep(i,2)rep(j,2){
				if(f[n-2+i][m-2+j] == 0){
					rep(a,2)rep(b,2){
						if(mp(i,j)!=mp(a,b)) {
							ans.pb(n-2+a+1);
							ans.pb(m-2+b+1);
							f[n-2+a][m-2+b] ^= 1;
						}
					}
					goto nxt3;
				}
			}
			nxt3:;
		}
	}
	assert(ans.size() <= 6 * n * m);
	rep(i, n) rep(j, m) assert(f[i][j] == 0);
	
	o(ans.size() / 6);
	for(auto a:ans) o(a);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}