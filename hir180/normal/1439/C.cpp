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

struct seg{
	#define szz (1<<18)
	int mxv[szz * 2];
	int mnv[szz * 2];
	int sum[szz * 2];
	void recalc(int k){
		mxv[k] = max(mxv[k*2+1], mxv[k*2+2]);
		mnv[k] = min(mnv[k*2+1], mnv[k*2+2]);
		sum[k] = sum[k*2+1] + sum[k*2+2];
	}
	void push(int k, int l, int r){
		if(mnv[k] != mxv[k]) return;
		repn(a,2){
			mxv[2*k+a] = mnv[k];
			mnv[2*k+a] = mnv[k];
			sum[2*k+a] = mnv[k] * (r-l+1) / 2;
		}
	}
	void update(int a, int b, int k, int l, int r, ll v){
		if(a > b or b < l or r < a or mnv[k] >= v) return;
		if(a <= l && r <= b && mxv[k] <= v){
			mxv[k] = v;
			mnv[k] = v;
			sum[k] = v * (r - l + 1);
			return;
		}
		push(k, l, r);
		update(a, b, k*2+1, l, (l+r)/2, v);
		update(a, b, k*2+2, (l+r)/2+1, r, v);
		recalc(k);
	}
	void update(int a, int b, ll v){
		update(a, b, 0, 0, szz-1, v);
		return;
	}
	P sum_large(int k, int l, int r, ll v, ll sum_pre){
		if(l == r) return P(l, sum_pre);
		push(k, l, r);
		
		if(sum[k*2+1] > v) return sum_large(k*2+1, l, (l+r)/2, v, sum_pre);
		else return sum_large(k*2+2, (l+r)/2+1, r, v-sum[k*2+1], sum_pre+sum[k*2+1]);
	}
	P notbig(int a, int b, int k, int l, int r, ll v, ll sum_pre){
		if(a > b or r < a or b < l or mnv[k] > v) return P(-1, -1);
		if(l == r) return P(l, sum_pre);
		push(k, l, r);
		
		auto x = notbig(a, b, k*2+1, l, (l+r)/2, v, sum_pre);
		if(x.a != -1) return x;
		return notbig(a, b, k*2+2, (l+r)/2+1, r, v, sum_pre + sum[k*2+1]);
	}
	P notbig(int a, int b, ll v){
		return notbig(a, b, 0, 0, szz-1, v, 0);
	}
	P sum_large(ll v){
		return sum_large(0, 0, szz-1, v, 0);
	}
}fuyuko;

int a[200001], n, q;
void solve(){
	cin>>n>>q;
	rep(i,n)cin>>a[i];
	rep(i,n)fuyuko.update(i, i, a[i]);
	while(q--){
		int t, x, y; cin >> t >> x >> y;
		x --;
		
		if(t == 1){
			fuyuko.update(0, x, y);
		}
		else if(t == 2){
			int ans = 0;
			while(1){
				auto xpre = fuyuko.notbig(x, n, y);
				int x = xpre.a, pre = xpre.b;
				if(x == n) break;
				auto nxtsum = fuyuko.sum_large(pre+y);
				int nxt = nxtsum.a, sum = nxtsum.b;

				if(nxt >= n){
				    ans += n-x;
				    break;
				}
				
				y -= sum - pre;
				ans += nxt - x;
				x = nxt;
			}
			o(ans);
		}
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}