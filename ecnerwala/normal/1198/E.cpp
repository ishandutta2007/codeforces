#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll N;
const int MAXM = 200;
int M;
int xlo[MAXM], ylo[MAXM], xhi[MAXM], yhi[MAXM];

// https://github.com/ecnerwala/icpc-book/blob/master/content/graph/PushRelabel.h
typedef vector<int> vi;
#define sz(a) (int)((a).size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto& a : x)
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

bool adj[200][200];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> xlo[i] >> ylo[i] >> xhi[i] >> yhi[i];
		xlo[i] --;
		ylo[i] --;
	}

	vector<ll> xs({0, N});
	vector<ll> ys({0, N});
	for (int i = 0; i < M; i++) {
		xs.push_back(xlo[i]);
		xs.push_back(xhi[i]);
		ys.push_back(ylo[i]);
		ys.push_back(yhi[i]);
	}
	sort(xs.begin(), xs.end()); xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
	sort(ys.begin(), ys.end()); ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
	for (int i = 0; i < M; i++) {
		xlo[i] = int(lower_bound(xs.begin(), xs.end(), xlo[i]) - xs.begin());
		xhi[i] = int(lower_bound(xs.begin(), xs.end(), xhi[i]) - xs.begin());
		ylo[i] = int(lower_bound(ys.begin(), ys.end(), ylo[i]) - ys.begin());
		yhi[i] = int(lower_bound(ys.begin(), ys.end(), yhi[i]) - ys.begin());
	}
	for (int i = 0; i < M; i++) {
		for (int x = xlo[i]; x < xhi[i]; x++) {
			for (int y = ylo[i]; y < yhi[i]; y++) {
				adj[x][y] = true;
			}
		}
	}

	PushRelabel pr(int(xs.size()) - 1 + int(ys.size()) - 1 + 2);
	int S = 0, T = 1;
	int xoff = 2;
	int yoff = xoff + int(xs.size()) - 1;

	for (int i = 0; i+1 < int(xs.size()); i++) {
		pr.add_edge(S, xoff + i, xs[i+1] - xs[i]);
	}
	for (int i = 0; i+1 < int(ys.size()); i++) {
		pr.add_edge(yoff + i, T, ys[i+1] - ys[i]);
	}

	for (int x = 0; x+1 < int(xs.size()); x++) {
		for (int y = 0; y+1 < int(ys.size()); y++) {
			if (adj[x][y]) pr.add_edge(xoff + x, yoff + y, N);
		}
	}
	cout << pr.maxflow(S, T) << '\n';

	return 0;
}