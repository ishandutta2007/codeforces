#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back

using Weight = ll;
using Flow = ll;
struct Edge {
	int src, dst;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(ll s, ll d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, ll a, ll b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, ll a, ll b, Weight w = 1) { g[a].emplace_back(a, b, w); }

pair<vector<ll>, Edges> bridge(const Graph& g) {
	const ll n = g.size();
	ll idx = 0, s = 0, t = 0, k = 0;
	std::vector<ll> ord(n, -1), onS(n), stk(n), roots(n), cmp(n);
	Edges brdg;
	std::function<void(ll, ll)> dfs = [&](ll v, ll u) {
		ord[v] = idx++;
		stk[s++] = v;
		onS[v] = true;
		roots[t++] = v;
		for (auto& e : g[v]) {
			ll w = e.dst;
			if (ord[w] == -1)
				dfs(w, v);
			else if (u != w && onS[w])
				while (ord[roots[t - 1]] > ord[w]) --t;
		}
		if (v == roots[t - 1]) {
			brdg.emplace_back(u, v, 0);
			while (1) {
				ll w = stk[--s];
				onS[w] = false;
				cmp[w] = k;
				if (v == w) break;
			}
			--t;
			++k;
		}
	};
	for (ll u = 0; u < n; u++) {
		if (ord[u] == -1) {
			dfs(u, n);
			brdg.pop_back();
		}
	}
	return std::make_pair(cmp, brdg);
}

ll cnt=0;
vector<vector<ll>> tr_adj(1);
vector<bool> used;

void dfs(ll p, ll par, ll gp, vector<vector<ll>>& adj,vector<set<ll>>& brdg) {
	used[p]=true;
	REP(i,(ll)adj[p].size()) {
		if(adj[p][i]==par) continue;
		if(used[adj[p][i]]) continue;
		if(brdg[p].count(adj[p][i])) {
			tr_adj.pb(vector<ll>(0));
			tr_adj[gp].pb(cnt+1);
			tr_adj[cnt+1].pb(gp);
			cnt++;
			dfs(adj[p][i],p,cnt,adj,brdg);
		} else dfs(adj[p][i],p,gp,adj,brdg);;
	}
}

P dfs2(ll p, ll par, ll dpt, vector<vector<ll>>& adj) {
	bool upd=false;
	P ret=P(-1,-1);
	REP(i,(ll)adj[p].size()) {
		if(adj[p][i]==par) continue;
		upd=true;
		ret=max(ret,dfs2(adj[p][i],p,dpt+1,adj));
	}
	if(!upd) return P(dpt,p);
	else return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> adj(n);
	used.assign(n,false);
	Graph g(n);
	REP(i,m) {
		ll x,y;
		cin>>x>>y;
		x--;
		y--;
		add_edge(g,x,y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	pair<vector<ll>,Edges> tmp=bridge(g);
	vector<set<ll>> brdg(n);
	for(auto x: tmp.second) {
		brdg[x.src].insert(x.dst);
		brdg[x.dst].insert(x.src);
	}
	dfs(0,-1,0,adj,brdg);
	P tmp2=dfs2(0,-1,0,tr_adj);
	P ans=dfs2(tmp2.second,-1,0,tr_adj);
	cout<<ans.first<<endl;
}