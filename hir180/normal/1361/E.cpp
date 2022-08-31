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
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353

int t, n, m, dep[100005], ord[100005], low[100005], go[100005], out[100005], rui[100005];
bool ok[100005], vis[100005];
vector<int>G[100005], edge[100005], add[100005];

void dfs(int v, int u, int &k){
	vis[v] = true;
	
	ord[v] = k++;
	low[v] = ord[v];
	
	if(u == -1) dep[v] = 0;
	else dep[v] = dep[u] + 1;
	
	bool is_art = false;
	int ct = 0;
	for(const auto to:G[v]){
		if(!vis[to]){
			ct++;
			dfs(to, v, k);
			low[v] = min(low[v], low[to]);
			if(u != -1 && ord[v] <= low[to]) is_art = true;
			if(ord[v] < low[to]) {
				//bridge
			}
		}
		else if(to != u){
			chmin(low[v], ord[to]);
		}
	}
	out[v] = k-1;
	if(u == -1 && ct > 1) is_art = 1;
}
int change(int a, int b){
	if(a == -1) return b;
	if(b == -1) return a;
	if(dep[a] < dep[b]) return a;
	return b;
}
void calc(int v){
	for(const auto at:edge[v]){
		calc(at);
		rui[v] += rui[at];
		go[v] = change(go[v], go[at]);
	}
}
void make(int v){
	if(go[v] != -1){
		ok[v] |= ok[go[v]];
	}
	for(const auto at:edge[v]){
		make(at);
	}
}
void solve(){
	scanf("%d%d", &n, &m);
	repn(i, n){
		G[i].clear();
		edge[i].clear();
		add[i].clear();
		go[i] = -1;
		ok[i] = 0;
		rui[i] = 0;
	}
	rep(i, m){
		int a, b; scanf("%d%d", &a, &b);
		G[a].pb(b);
	}
	vector<int>vt(n);
	rep(i, n) vt[i] = i+1;
	mt19937 mt(61471);
	shuffle(vt.begin(), vt.end(), mt);
	int good = -1;
	rep(j, min(50, n)){
	    repn(i, n) vis[i] = 0;
		int root = vt[j], x = 1, bad = 0;
		dfs(root, -1, x);
		repn(i, n){
			for(const auto j:G[i]){
				if((dep[i]+1 == dep[j] && ord[i]<=ord[j] && out[j]<=out[i]) || (ord[j] <= ord[i] && out[i] <= out[j]));
				else bad = 1;
			}
		}
		if(bad) continue;
		good = root; break;
	}
	if(good == -1){
	    puts("-1");
	    return;
	}
	repn(i, n){
		for(const auto j:G[i]){
			if(dep[i]+1 == dep[j] && ord[i]<=ord[j] && out[j]<=out[i]){
				//tree
				edge[i].pb(j);
			}
			else{
				//add
				add[i].pb(j);
				rui[i]++;
				rui[j]--;
				go[i] = change(go[i], j);
			}
		}
	}
	calc(good);
	ok[good] = true;
	repn(i, n) if(rui[i] != 1) go[i] = -1;
	make(good);
	vector<int>ans;
	repn(i, n) if(ok[i]) ans.pb(i);
	int lim = (n-1)/5;
	if(ans.size() <= lim) puts("-1");
	else{
		dmp(ans);
	}
}
int main(){
	scanf("%d", &t);
	while(t--){
		solve();
	}
}