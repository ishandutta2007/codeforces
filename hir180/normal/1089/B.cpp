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
#define INF 1000000000
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


const int MAXN = 305;
struct mf{
	// 1-based Vertex index
	int vis[MAXN], par[MAXN], orig[MAXN], match[MAXN], aux[MAXN], t, N;
	vector<int> conn[MAXN];
	queue<int> Q;
	void add_edge(int u, int v) {
	    u++; v++;
		conn[u].push_back(v); conn[v].push_back(u);
	}
	void init(int n) {
		N = n; t = 0;
		for(int i=0; i<=n; ++i) {
			conn[i].clear();
			match[i] = aux[i] = par[i] = 0;
		}
	}
	void augment(int u, int v) {
		int pv = v, nv;
		do {
			pv = par[v]; nv = match[pv];
			match[v] = pv; match[pv] = v;
			v = nv;
		} while(u != pv);
	}
	int lca(int v, int w) {
		++t;
		while(true) {
			if(v) {
				if(aux[v] == t) return v; aux[v] = t;
				v = orig[par[match[v]]];
			}
			swap(v, w);
		}
	}
	void blossom(int v, int w, int a) {
		while(orig[v] != a) {
			par[v] = w; w = match[v];
			if(vis[w] == 1) Q.push(w), vis[w] = 0;
			orig[v] = orig[w] = a;
			v = par[w];
		}
	}
	bool bfs(int u) {
		fill(vis+1, vis+1+N, -1); iota(orig + 1, orig + N + 1, 1);
		Q = queue<int> (); Q.push(u); vis[u] = 0;
		while(!Q.empty()) {
			int v = Q.front(); Q.pop();
			for(int x: conn[v]) {
				if(vis[x] == -1) {
					par[x] = v; vis[x] = 1;
					if(!match[x]) return augment(u, x), true;
					Q.push(match[x]); vis[match[x]] = 0;
				}
				else if(vis[x] == 0 && orig[v] != orig[x]) {
					int a = lca(orig[v], orig[x]);
					blossom(x, v, a); blossom(v, x, a);
				}
			}
		}
		return false;
	}
	int Match() {
		int ans = 0;
		// find random matching (not necessary, constant improvement)
		vector<int> V(N-1); iota(V.begin(), V.end(), 1);
		shuffle(V.begin(), V.end(), mt19937(61471));
		for(auto x: V) if(!match[x]){
			for(auto y: conn[x]) if(!match[y]) {
				match[x] = y, match[y] = x;
				++ans; break;
			}
		}
		//cout << ans << endl; return ans;
		for(int i=1; i<=N; ++i) if(!match[i] && bfs(i)) ++ans;
		return ans;
	}
}mf;

void solve(){
	int n,m;
	g(n); g(m);
	mf.init(2*n + m + 2);
	rep(i,n){
		mf.add_edge(i*2, i*2+1);
		string s; g(s);
		rep(j,m){
			if(s[j] == '1'){
				mf.add_edge(i*2, j+2*n);
				mf.add_edge(i*2+1, j+2*n);
			}
		}
	}
	int ans = mf.Match() - n;
	o(ans);
}
int main(){
	ios::sync_with_stdio(false);
	int t; g(t);
	while(t--) solve();
}