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
#include <bitset>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//#define int long long
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
const ll mod = 1000000007;
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

#define sz (1<<17)
#define ull unsigned long long
ull hsh[sz], rui[sz];
ull calc(int a, int b){
    auto r = rui[b];
    if(a) r ^= rui[a-1];
    return r;
}
struct per_seg{
	vector<int>root;
	int L[sz*40],R[sz*40],id;
	int cnt[sz*40];
	ull seg[sz*40];
	void make(){
		for(int i=0;i<sz-1;i++) L[i] = i*2+1,R[i] = i*2+2;
		root.push_back(0); id = 2*sz;
	}
	int find_zero(int a, int b, int k, int l, int r, bool le=false){
		if(r < a or b < l) return -1;
		if(le == false and seg[k] == hsh[l]) return -1;
		if(le == true and seg[k] == 0) return -1;
		if(l == r) return l;
		auto lev = find_zero(a, b, L[k], l, (l+r)/2, le);
		if(lev != -1) return lev;
		return find_zero(a, b, R[k], (l+r)/2+1, r, le ^ (1&cnt[L[k]]));
	}
	//flip
	int update(int a,int k,int l,int r){
	    if(l<=a and a<=r); else return k;
		if(l == r){
			cnt[id] = cnt[k] ^ 1;
			seg[id] = seg[k] ^ hsh[l];
			L[id] = L[k]; R[id] = R[k]; id++;
			return id-1;
		}
		int x = update(a,L[k],l,(l+r)/2);
		int y = update(a,R[k],(l+r)/2+1,r);
		cnt[id] = cnt[x] + cnt[y];
		seg[id] = seg[x] ^ seg[y];
		L[id] = x; R[id] = y; id++;
		return id-1;
	}
	//value of r0 < value of r1?
	//r0 < r1: +1 r0 > r1: -1 r0 == r1: 0
	int query(int r0, int r1, int l=0, int r=sz-1, bool le0=false, bool le1=false){
		auto v0 = seg[r0]; if(le0) v0 ^= hsh[l];
		auto v1 = seg[r1]; if(le1) v1 ^= hsh[l];
		
		if(v0 == v1) return 0;
		if(l == r){
			assert(v0 == 0 or v1 == 0);
			return (v0 < v1 ? 1 : -1);
		}
		auto ret = query(R[r0], R[r1], (l+r)/2+1, r, (le0 ^ (1&cnt[L[r0]])), (le1 ^ (1&cnt[L[r1]])));
		if(ret) return ret;
		return query(L[r0], L[r1], l, (l+r)/2, le0, le1);
	}
}seg;

void solve(){
	rep(i, sz){
		hsh[i] = mt();
		rui[i] = hsh[i];
		if(i) rui[i] ^= rui[i-1];
	} 
	int n, m; cin >> n >> m;
	seg.make();
	vc<vc<P>>edge(n, vc<P>());
	rep(i, m){
		int a, b, c; cin >> a >> b >> c;
		a --; b --;
		edge[a].pb(mp(b, c));
		edge[b].pb(mp(a, c));
	}
	int s, t; cin >> s >> t; s--; t--;
	vc<int>dist(n, -1);
	vc<P>pre(n);
	dist[s] = 0;
	auto cmp = [&](P p, P q){
		auto flag = seg.query(p.a, q.a);
		return flag == -1;
	};
	priority_queue<P, vc<P>, decltype(cmp)>que(cmp);
	que.push(mp(0, s));
	vc<bool>vis(n);
	while(!que.empty()){
		P p = que.top(); que.pop();
		if(dist[p.b] != p.a) continue;
		vis[p.b] = true;
		for(auto a:edge[p.b]){
			int to = a.a;
			if(vis[to]) continue;
			int cs = a.b;
			int bt = seg.find_zero(cs, sz-1, p.a, 0, sz-1);
			int newroot = seg.update(cs, p.a, 0, sz-1);
			newroot = seg.update(bt+1, newroot, 0, sz-1);
			if(dist[to] == -1 or seg.query(newroot, dist[to]) == 1){
				dist[to] = newroot;
				pre[to] = mp(p.b, cs);
				que.push(mp(newroot, to));
			}
		}
	}
	if(dist[t] == -1){
		o(-1);
	}
	else{
		vc<int>pat;
		int cur = t;
		ll ans = 0;
		while(1){
			pat.pb(cur);
			if(cur == s) break;
			ans += modpow(2LL, pre[cur].b);
			cur = pre[cur].a;
		}
		cout<<ans%mod<<endl;
		cout<<pat.size()<<endl;
		reverse(all(pat));
		rep(i,pat.size())cout<<++pat[i]<<(i+1==pat.size()?'\n':' ');
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}