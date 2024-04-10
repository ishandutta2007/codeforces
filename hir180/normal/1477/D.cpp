//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//#define int long long
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
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
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
int n, m;
vc<int>edge[500005];
set<int>S[500005];
bool vis[500005];
vc<vc<int>>piece;
int dep[500005], r[500005], cnt[500005], up[500005];
void dfs(int v, int u, int d, int b){
	dep[v] = d;
	r[v] = b;
	cnt[b] ++;
	up[v] = u;
	for(auto a:edge[v]){
		if(a == u) continue;
		dfs(a, v, d+1, b);
	}
}
void solve(){
	cin >> n >> m;
	repn(i, n){
		edge[i].clear();
		S[i].clear();
		vis[i] = 0;
		dep[i] = -1;
		cnt[i] = 0;
	}
	piece.clear();
	rep(i, m){
		int a, b; cin >> a >> b;
		S[a].insert(b);
		S[b].insert(a);
	}
	repn(i, n){
		if(edge[i].size()) continue;
		repn(j, n){
			if(j == i) continue;
			if(S[i].find(j) == S[i].end()){
				edge[i].pb(j);
				edge[j].pb(i);
				break;
			}
		}
	}
	repn(i, n){
		if(dep[i] != -1) continue;
		dfs(i, -1, 0, i);
	}
	vc<P>V;
	repn(i, n){
		V.pb(mp(-dep[i], i));
	}
	SORT(V);
	for(auto a:V){
		int v = a.b;
		if(vis[v]) continue;
		if(dep[v] == 0){
			assert(edge[v].empty());
			piece.pb(vc<int>({v}));
			cnt[v] --;
		}
		else{
			int U = up[v];
			vc<int>nw; nw.pb(U);
			for(auto v:edge[U]){
				if(!vis[v] && dep[v] > dep[U]) nw.pb(v);
			}
			if(cnt[r[v]] == si(nw)+1){
				//root
				assert(dep[U] == 1);
				nw.pb(r[v]);
			}
			cnt[r[v]] -= si(nw);
			piece.pb(nw);
		}
		for(auto at:piece.back()) vis[at] = 1;
	}
	vc<int>p(n+1), q(n+1);
	int nxt = 1;
	for(auto at:piece) {
		p[at[0]] = nxt;
		repn(i, si(at)-1) p[at[i]] = nxt+i;
		
		q[at[0]] = nxt+si(at)-1;
		repn(i, si(at)-1) q[at[i]] = nxt+i-1;
		nxt += si(at);
	}
	repn(i, n){
		cout << p[i] << " ";
	}
	cout << '\n';
	repn(i, n){
		cout << q[i] << " ";
	}
	cout << '\n';
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}