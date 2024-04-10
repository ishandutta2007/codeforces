#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

vector<int> which;
int qq = 0;

void do_stuff(vector<int> x){
	for(int a : x){
		which[a] = qq;
	}
	qq += 1;
}

void solve2(int n, vector<ll> cost, vector<pair<int,int> > dep){
	vector<bool> has_edge(n, false);
	ll ans = 0;
	for(auto r : dep){
		has_edge[r.first] = has_edge[r.second] = true;
	}
	vector<int> vlist;
	map<int,int> zmap;
	vector<ll> newcost;
	for(int i = 0; i < n; i++){
		if(!has_edge[i]){
			if(cost[i] >= 0) ans += cost[i];
		} else {
			zmap[i] = (int)vlist.size();
			vlist.push_back(i);
			newcost.push_back(cost[i]);
		}
	}
	for(auto& r : dep){
		r.first = zmap[r.first];
		r.second = zmap[r.second];
	}

	cost = newcost;

	n = vlist.size();

	PushRelabel flow(n+2);
	for(int i = 0; i < n; i++){
		if(cost[i] >= 0){
			flow.add_edge(n, i, cost[i]);
			ans += cost[i];
		} else {
			flow.add_edge(i, n+1, -cost[i]);
		}
	}
	for(auto r : dep){
		flow.add_edge(r.first, r.second, 1e18);
	}
	ans -= flow.maxflow(n, n+1);
	cout << ans << '\n';
}

void solve(int n, vector<ll> cost, vector<pair<int,int> > dep){
	which.resize(n);
	vector<vector<int> > edges(n);
	for(auto r : dep){
		edges[r.first].push_back(r.second);
	}
	scc(edges, do_stuff);
	vector<pair<int,int> > new_dep;

	vector<ll> new_cost(qq, 0);
	for(int i = 0; i < n; i++){
		new_cost[which[i]] += cost[i];
	}
	for(auto r : dep){
		if(which[r.first] == which[r.second]) continue;
		new_dep.emplace_back(which[r.first], which[r.second]);
	}
	solve2(qq, new_cost, new_dep);
}

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges(n);
	vector<vector<int> > dist(n, vector<int>(n, 1e9));
	for(int i = 0; i < n; i++) dist[i][i] = 0;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		dist[u][v] = min(dist[u][v], 1);
		dist[v][u] = min(dist[v][u], 1);
	}
	for(int _ = 0; _ < 3; _++)
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int s, b, k;
	cin >> s >> b >> k;
	vector<int> x1(s), a(s), f(s), p(s);
	vector<int> x2(b), d(b), g(b);
	for(int i = 0; i < s; i++){
		cin >> x1[i] >> a[i] >> f[i] >> p[i];
		x1[i]--;
	}
	for(int i = 0; i < b; i++){
		cin >> x2[i] >> d[i] >> g[i];
		x2[i]--;
	}
	vector<ll> cost(s, 0);

	vector<vector<pair<int,ll> > > contents(n);

	for(int i = 0; i < b; i++){
		contents[x2[i]].emplace_back(d[i], g[i]);
	}
	for(int i = 0; i < n; i++){
		sort(contents[i].begin(), contents[i].end());
		int best = 0;
		vector<pair<int,ll> > rc;
		rc.emplace_back(0, -1e15);
		for(pair<int,ll> xx : contents[i]){
			if(xx.second <= best) continue;
			best = xx.second;
			rc.push_back(xx);
		}
		contents[i] = rc;
	}

	for(int i = 0; i < s; i++){
		ll best_base = -1e15;
		for(int v = 0; v < n; v++){
			if(f[i] >= dist[x1[i]][v]){
				// find best j with d[j] <= a[i]
				int ss = 0;
				int ee = contents[v].size();
				while(ss + 1 < ee){
					int mm = (ss + ee) / 2;
					if(contents[v][mm].first <= a[i]){
						ss = mm;
					} else {
						ee = mm;
					}
				}
				best_base = max(best_base, contents[v][ss].second);
			}
		}
		cost[i] = best_base - p[i];
	}

	vector<pair<int,int> > dep;
	for(int i = 0; i < k; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		dep.emplace_back(u, v);
	}
	solve(s, cost, dep);
}