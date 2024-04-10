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
#define INF 100000000
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
bool Q;

struct Line {
	mutable ll k, m, p; // slope, y-intercept, last optimal x
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

//max

struct LineContainer : multiset<Line> {
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		if (b < 0) a *= -1, b *= -1;
		if (a >= 0) return a / b;
		return -((-a + b - 1) / b);
	}

	// updates x->p, determines if y is unneeded
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return 0; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}

	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}

	ll query(ll x) { // gives max value
		if(empty()) return -1e18;
		assert(!empty());
		Q = 1; auto l = *lower_bound({0, 0, x}); Q = 0;
		return l.k * x + l.m;
	}
};
LineContainer t[500005];

int n;
vector<int>edge[500005];
ll ans = 1e18, mx[500005], sub[500005];

void dfs(int v,int u){
	bool ch = 0;
	sub[v] = 1;
	rep(i,edge[v].size()){
		int to = edge[v][i];
		if(to == u) continue;
		dfs(to, v);
		ch = 1; sub[v] += sub[to];
	}
	if(!ch){
		mx[v] = 1;
		return ;
	}
	mx[v] = 1e18;
	rep(i,edge[v].size()){
		int to = edge[v][i];
		if(to == u) continue;
		//v to (sub[to])
		chmin(ans, mx[to] + 1LL * (n-sub[to]) *  (n-sub[to]));
		//use previous
		ll res = -t[v].query(sub[to]) + mx[to];
		chmin(ans, res + 1LL * (n-sub[to]) *  (n-sub[to]));
		t[v].add(-2LL*sub[to], -1LL*sub[to]*sub[to] - mx[to] + 2LL * n * sub[to]);
		chmin(mx[v], mx[to]+1LL*(sub[v]-sub[to])*(sub[v]-sub[to]));
	}
	//cout << v << " " << mx[v] << endl;
}
int main(){
	ios::sync_with_stdio(false);
	g(n);
	rep(i,n-1){
		int a,b; g(a); g(b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1, -1);
	
	ll ret = 2LL*n*n - n - ans;
	o(ret/2);
}