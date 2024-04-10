//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
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
const ll mod = 1000000007;//998244353
//mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
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
struct state{
	int x[2];
	state(){}
	state(int a, int b){
		x[0] = a, x[1] = b;
	}
}dp[200005];

state compress(int v0, int v1, int id){
	if(id == 0) return state(max(v0, v1+1), v1);
	if(id == 1) return state(v0, max(v1, v0+1));
	if(id == 2) return state(v0, v1);
}

int n, a[200005], ans;
vc<int>edge[200005];
void dfs0(int v, int u){
	int mx[2] = {};
	rep(i, edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs0(edge[v][i], v);
		rep(j, 2) chmax(mx[j], dp[edge[v][i]].x[j]);
	}
	dp[v] = compress(mx[0], mx[1], a[v]);
}
void dfs1(int v, int u, state up){
	vector<P>Q[2];
	int M[2] = {};
	rep(i, 2) Q[i].eb(up.x[i], -1);
	rep(i, edge[v].size()){
		if(edge[v][i] == u) continue;
		rep(j, 2) Q[j].eb(dp[edge[v][i]].x[j], edge[v][i]);
		rep(j, 2) chmax(M[j], dp[edge[v][i]].x[j]);
	}
	if(a[v] == 0 || a[v] == 2){
		auto A = compress(up.x[0], up.x[1], 0);
		chmin(ans, max( max(M[0], M[1] + 1), max(A.x[0], A.x[1]) ));
	}
	if(a[v] == 1 || a[v] == 2){
		auto A = compress(up.x[0], up.x[1], 1);
		chmin(ans, max( max(M[1], M[0] + 1), max(A.x[0], A.x[1]) ));
	}
	rep(j, 2){
		sort(all(Q[j]));
		reverse(all(Q[j]));
	}
	rep(i, edge[v].size()){
		if(edge[v][i] == u) continue;
		int mx[2] = {};
		rep(j, 2){
			rep(k, 2){
				if(k < Q[j].size() && Q[j][k].b != edge[v][i]){
					chmax(mx[j], Q[j][k].a);
				}
			}
		}
		dfs1(edge[v][i], v, compress(mx[0], mx[1], a[v]));
	}
}
void solve(){
	 cin >> n;
	 repn(i, n){
	 	cin >> a[i];
	 	a[i] = 2 - a[i];
		edge[i].clear();
		rep(k, 2) dp[i].x[k] = INF;
	}
	rep(i, n-1){
		int x, y; cin >> x >> y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	dfs0(1, -1);
	ans = INF;
	dfs1(1, -1, state(0, 0));
	cout << ans << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}