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


//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int n, m;
vector<int>za;
int dp[10005][2005];
int rui[10005][2005];
int g, r;
int dist[10005];
bool vis[10005];

void solve(){
	cin >> n >> m;
	rep(i, m){
		int a; cin >> a; za.pb(a);
	}
	sort(all(za));
	ERASE(za);
	cin >> g >> r;
	int sz = za.size();
	rep(i, 10005) rep(j, 2005) rui[i][j] = dp[i][j] = -INF;
	for(int i=sz-1;i>=0;i--){
		dp[i][0] = i;
		if(i+1 < sz){
			int d = za[i+1] - za[i];
			d <<= 1;
			for(int j=0;j<2005;j++){
				if(j >= d) chmax(rui[i+1][j], rui[i+1][j-d]);
				chmax(rui[i+1][j], dp[i+1][j]);
			}
			for(int j=d;j<2005;j++){
				dp[i][j] = rui[i+1][j-d];
			}
		}
	}
	for(int i=1;i<sz;i++){
		rep(j, 2005) chmax(dp[i][j], dp[i-1][j]);
	}
	rep(i, sz) dist[i] = INF;
	dist[0] = 0;
	queue<int>que; que.push(0);
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(vis[q]) continue; vis[q] = 1;
		for(int i=max(0, q-g);i<=min(sz-1, q+g);i++){
			int u = min(i, q);
			int v = max(i, q);
			if(za[v] - za[u] > g) continue;
			if(dp[u][g + za[v] - za[u]] >= v){
				chmin(dist[i], dist[q] + 1);
				if(!vis[i]) que.push(i);
			}
		}
	}
	ll ans = 1e18;
	rep(i, sz){
		if(dist[i] == INF) continue;
		if(za[i]+g < n) continue;
		chmin(ans, 1LL*dist[i]*(g+r) + n - za[i]);
	}
	if(ans > 5e17) ans = -1;
	cout << ans << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1;//cin >> t;
	while(t--) solve();
}