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
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
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
int n, m, dist[405][405];
vc<int>v[405], edge[405];
double sum[405];
bool vis[405], in[405];
void solve(){
	cin >> n >> m;
	rep(a, 405) rep(b, 405) if(a != b) dist[a][b] = INF;
	rep(i, m){
		int a, b; cin >> a >> b;
		edge[a].pb(b); edge[b].pb(a);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	repn(k, n) repn(i, n) repn(j, n) chmin(dist[i][j], dist[i][k] + dist[k][j]);
	
	double ans = 0.0;
	repn(i, n){
		rep(j, 405){
			v[j].clear();
		}
		repn(j, n) v[dist[i][j]].pb(j);
		double tmp = 0.;
		rep(j, 405){
			if(v[j].empty()) break;
			memset(sum, 0, sizeof(sum));
			double F = 1.0;
			vc<int>t;
			for(auto from:v[j]) for(auto to:edge[from]){
				if(!in[to]) t.pb(to);
				in[to] = 1;
				sum[to] += 1.0 / (double)(edge[from].size());
			}
			sort(all(t), [&](int a, int b){
				return sum[a] > sum[b];
			});
			double S = 0.0;
			repn(s, n){
				double V = 0.0;
				for(auto at:t){
					if(vis[dist[s][at]]) continue;
					vis[dist[s][at]] = true;
					V += sum[at];
				}
				chmax(S, V);
				for(auto at:t){
					vis[dist[s][at]] = false;
				}
			}
			tmp += max(F, S) / (double)(n);
			for(auto at:t) in[at] = false;
		}
		chmax(ans, tmp);
	}
	cout << ans << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}