#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 1, M = 2e5 + 1;
bool chk[M];
int h[N], par[N], ans[M];
inline void Max(int &a, int b) { if (a < b) a = b; }
inline void Min(int &a, int b) { if (a == 0 || b > 0 && a > b) a = b; }

struct TEdge {
	int u, v, w, id, res;
	TEdge(int u_, int v_) : u(u_), v(v_) {}
	TEdge(int u_, int v_, int w_) : u(u_), v(v_), w(w_), res(0) {}
	TEdge(int u_, int v_, int w_, int id_) : u(u_), v(v_), w(w_), id(id_), res(0) {}
	TEdge(const TEdge &x) : u(x.u), v(x.v), w(x.w), id(x.id), res(x.res) {}
};
vector<TEdge> adj[N], prv[N], free_edge;
inline bool operator < (const TEdge &a, const TEdge &b) {
	return (a.w > b.w);
}

void build_LCA() {
	priority_queue<TEdge> H;
	for (H.emplace(0, 1); !H.empty();) {
		TEdge cur(H.top()); H.pop();
		if (prv[cur.v].empty()) {
			h[cur.v] = h[cur.u] + 1;
			prv[cur.v].push_back(cur);
			while (prv[cur.v].size() <= prv[prv[cur.v].back().u].size()) {
				TEdge e1(prv[cur.v].back());
				TEdge e2(prv[e1.u][prv[cur.v].size() - 1]);
				prv[cur.v].emplace_back(e2.u, e1.v, max(e2.w, e1.w));
			}
			for (TEdge nxt : adj[cur.v])
				if (prv[nxt.v].empty())
					H.push(nxt);
		} else if (!chk[cur.id]) {
			chk[cur.id] = true;
			free_edge.push_back(cur);
		}
	}
}

int update_LCA(int a, int b, int res) {
	if (h[a] < h[b]) 
		swap(a, b);
	int maxw = 0;
	for (int i = prv[a].size(); i--;)
		if (i < prv[a].size()) {
			TEdge *a_ = &prv[a][i];
			if (h[a_->u] >= h[b]) {
				Max(maxw, a_->w);
				Min(a_->res, res);
				a = a_->u;
			}
		}
	if (a == b) 
		return maxw;
	for (int i = prv[a].size(); i--;)
		if (i < prv[a].size()) {
			TEdge *a_ = &prv[a][i], 
			      *b_ = &prv[b][i];
			if (a_->u != b_->u) {
				Max(maxw, max(a_->w, b_->w));
				Min(a_->res, res);
				Min(b_->res, res);
				a = a_->u;
				b = b_->u;
			}
		}
	TEdge *a_ = &prv[a].front(),
	      *b_ = &prv[b].front();
	Min(a_->res, res);
	Min(b_->res, res);
	return max(maxw, max(a_->w, b_->w));
}

void solve(int n) {
	int maxh = 1;
	for (int i = 2; i <= n; ++i)
		Max(maxh, prv[i].size());
	for (int i = maxh; --i;)
		for (int j = 2; j <= n; ++j)
			if (i < prv[j].size()) {
				TEdge *e  = &prv[j][i],
				      *e1 = &prv[j][i - 1],
					  *e2 = &prv[e1->u][i - 1];
				Min(e1->res, e->res);
				Min(e2->res, e->res);
			}
	for (int i = 2; i <= n; ++i) {
		TEdge e(prv[i].front());
		ans[e.id] = e.res;
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		adj[u].emplace_back(u, v, c, i);
		adj[v].emplace_back(v, u, c, i);
	}
	build_LCA();
	for (TEdge e : free_edge)
		ans[e.id] = update_LCA(e.u, e.v, e.w);
	solve(n);
	for (int i = 0; i < m; ++i)
		printf("%d ", ans[i] - 1);
}