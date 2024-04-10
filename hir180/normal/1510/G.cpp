#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define repn(i, b) for(int i=1;i<=b;i++)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u>bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u>bool chmin(t&a,u b){if(a>b){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>&p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t>
ostream&operator<<(ostream&os,const vector<t>&v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
template<class t>
using vc = vector<t>;
using P=pair<int,int>;

vc<int>edge[105];
int n, k, up[105], dep[105];
vc<int>d[105];
void dfs(int v, int u, int d){
	dep[v] = d;
	up[v] = u;
	
	for(auto a:edge[v]){
		if(a == u) continue;
		dfs(a, v, d+1);
	}
}
int las[105];
bool used[105] = {};
vc<int>pat;
void dfs2(int v, int u){
	pat.pb(v);
	for(auto a:edge[v]){
	    if(a == u) continue;
		if(!used[a]) continue;
		if(las[a]) continue;
		dfs2(a, v);
		pat.pb(v);
	}
	for(auto a:edge[v]){
	    if(a == u) continue;
		if(!used[a]) continue;
		if(!las[a]) continue;
		dfs2(a, v);
		pat.pb(v);
	}
}
void solve(){
	cin >> n >> k;
	rep(i, 105) edge[i].clear();
	rep(i, 105) d[i].clear();
	repn(i, n-1){
		int a; cin >> a;
		edge[a].pb(i+1);
		edge[i+1].pb(a);
	}
	if(k == 1){
		cout << 0 << '\n' << 1 << '\n';
		return;
	}
	dfs(1, -1, 0);
	memset(las, 0, sizeof(las));
	memset(used, 0, sizeof(used));
	repn(i, n) d[dep[i]].pb(i);
	int rem = k;
	for(int i=k-1;i>=0;i--){
		if(d[i].empty()) continue;
		int x = d[i][0];
		while(1){
			las[x] = 1;
			used[x] = 1;
			rem --;
			if(x == 1) break;
			x = up[x];
		}
		rep(i, 105){
			for(auto a:d[i]){
				if(rem && !used[a]){
					used[a] = 1;
					rem --;
				}
			}
		}
		cout << 2*(k-1) - i << '\n';
		pat.clear();
		dfs2(1, -1);
		assert(pat.size() == 2*(k-1) + 1);
		pat.resize(2*(k-1) - i + 1);
		rep(i, pat.size()) cout << pat[i] << (i+1==pat.size()?'\n':' ');
		return;
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}