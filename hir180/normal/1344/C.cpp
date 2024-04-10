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

int n, m, deg[200005];
vc<int>edge[200005], redge[200005];
bool vis[2][200005];

void solve(){
	cin >> n >> m;
	rep(i, m){
		int a, b; cin >> a >> b;
		edge[a].pb(b);
		deg[b] ++;
		redge[b].pb(a);
	}
	queue<int>Q; repn(i, n) if(deg[i]==0)Q.push(i);
	while(!Q.empty()){
		int q = Q.front(); Q.pop();
		for(auto at:edge[q]){
			deg[at]--; if(deg[at] == 0) Q.push(at);
		}
	}
	repn(i, n) if(deg[i]){
		cout<<-1<<endl;return;
	}
	string ans = "";
	int ret = 0;
	repn(i, n){
		if(!vis[0][i] && !vis[1][i]){
			ret ++ ; ans.pb('A');
		}
		else ans.pb('E');
		queue<int>que;
		que.push(i);
		while(!que.empty()){
			int q = que.front(); que.pop();
			if(vis[0][q]) continue; vis[0][q] = 1;
			for(auto at:edge[q]) if(!vis[0][at]) que.push(at);
		}
		que.push(i);
		while(!que.empty()){
			int q = que.front(); que.pop();
			if(vis[1][q]) continue; vis[1][q] = 1;
			for(auto at:redge[q]) if(!vis[1][at]) que.push(at);
		}
		
	}
	cout << ret << endl << ans << endl;
	
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}