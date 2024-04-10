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
int n, dp[100005];
vector<int>edge[100005];
int M;
vector<P>ans;
void make(int v, int u, int add){
	ans.pb(mp(v, add));
	int cur = add;
	bool ok = 0;
	if(v != 1 && cur == M){
	    ans.pb(mp(v, M - si(edge[v])));
	    cur = M - si(edge[v]);
	    ok = 1;
	}
	rep(i, edge[v].size()){
		if(edge[v][i] == u) continue;
		make(edge[v][i], v, cur + 1);
		ans.pb(mp(v, cur + 1));
		if(v != 1 && cur + 1 == M){
		    ans.pb(mp(v, M - si(edge[v])));
	        cur = M - si(edge[v]);
	        ok = 1;
	    }
		else cur ++;
	}
	if(add && !ok) ans.pb(mp(v, add-1));
}
void solve(){
	cin >> n;
	rep(i, n-1){
		int a, b; cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	repn(i, n) chmax(M, si(edge[i]));
	make(1, -1, 0);
	cout << ans.size() << '\n';
	for(auto at:ans) cout << at.a << " " << at.b << '\n';
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1;//cin >> t;
	while(t--) solve();
}