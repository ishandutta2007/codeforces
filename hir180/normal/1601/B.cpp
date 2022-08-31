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
#define sz (1<<20)+300005
int dist[sz];
vc<P>edge[sz];
int n, a[300005], b[300005];
void dfs(int a, int b, int k, int l, int r, int to){
	if(a > b or r < a or b < l) return;
	if(a <= l and r <= b){
		edge[k].pb(mp(to, 1));
		return;
	}
	dfs(a, b, k*2+1, l, (l+r)/2, to);
	dfs(a, b, k*2+2, (l+r)/2+1, r, to);
}
vc<int>layer[300005];

void solve(){
	cin>>n;
	repn(i,n)cin>>a[i];
	repn(i,n)cin>>b[i];
	for(int i=0;i<(1<<19)-1;i++){
		edge[i*2+1].pb(mp(i, 0));
		edge[i*2+2].pb(mp(i, 0));
	}
	//after -> before
	for(int i=0;i<=n;i++){
		edge[(1<<20)+i+b[i]].pb(mp((1<<19)-1+i, 0));
	}
	//before -> after
	for(int i=0;i<=n;i++){
		dfs(i-a[i], i-1, 0, 0, (1<<19)-1, (1<<20)+i);
	}
	int beg = (1<<20);
	rep(i, sz) dist[i] = 1e18;
	dist[beg] = 0;
	deque<int>deq; deq.pb(beg);
	
	while(!deq.empty()){
		int q = deq.front(); deq.pop_front();
		for(auto jc: edge[q]){
			int j = jc.a, c = jc.b;
			int d = dist[q] + c;
			if(d < dist[j]){
				dist[j] = d;
				if(c) deq.pb(j);
				else deq.push_front(j);
			}
		}
	}
  
	if(dist[beg+n] > 5e17) o(-1);
	else{
		o(dist[beg+n]);
		for(int i=0;i<=n;i++) {
			if(dist[(1<<19)-1+i] <= n+45){
				layer[dist[(1<<19)-1+i]].pb(i);
			}
		}
		int cur = n;
		while(cur != 0){
			int p = POSL(layer[dist[beg+cur]-1], cur);
			p --;
			p = layer[dist[beg+cur]-1][p];
			cur = p + b[p];
			cout << p << " ";
		}
		cout << '\n';
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}