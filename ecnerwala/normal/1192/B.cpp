#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct seg_tree {
	int N;
	int S;
	struct seg_node {
		ll lazyVal = 0;
		ll maxVal = 0;
	};
	vector<seg_node> nodes;
	seg_tree() : N(0), S(0), nodes() {}
	seg_tree(int N_) : N(N_), S(N == 1 ? 1 : 1<<(32 - __builtin_clz(N-1))), nodes(2*S) {}

	ll query() {
		return nodes[1].maxVal;
	}

	void updateNode(int i) {
		assert(1 <= i && i < 2 * S);
		nodes[i].maxVal = ((i >= S) ? 0 : max(nodes[2*i].maxVal, nodes[2*i+1].maxVal)) + nodes[i].lazyVal;
	}

	void modify(int l, int r, ll v) {
		for (int a = l+S, b = r+S; a < b; a /= 2, b /= 2) {
			if (a & 1) {
				nodes[a].lazyVal += v;
				updateNode(a);
				a++;
			}
			if (b & 1) {
				--b;
				nodes[b].lazyVal += v;
				updateNode(b);
			}
		}
		for (int a = l+S; a; a /= 2) {
			updateNode(a);
		}
		for (int b = r+S-1; b; b /= 2) {
			updateNode(b);
		}
	}

	void modify(pair<int, int> r, ll v) {
		return modify(r.first, r.second, v);
	}
};

const int MAXN = 1.1e5;
const int MAXQ = 1.1e5;
int N, Q; ll W;

struct edge_t {
	int c[2];
	ll w;
	int other(int a) {
		assert(a == c[0] || a == c[1]);
		return c[0] ^ c[1] ^ a;
	}
} E[MAXN];
vector<int> adj[MAXN];

bool isDead[MAXN];

int dfsSz(int cur, int prv) {
	if (isDead[cur]) return 0;
	int ans = 1;
	for (int e : adj[cur]) {
		int nxt = E[e].other(cur);
		if (nxt == prv) continue;
		ans += dfsSz(nxt, cur);
	}
	return ans;
}

int getCentroid(int cur, int prv, int sz) {
	if (isDead[cur]) return -1;
	int curSz = 1;
	for (int e : adj[cur]) {
		int nxt = E[e].other(cur);
		if (nxt == prv) continue;
		int ch = getCentroid(nxt, cur, sz);
		if (ch >= 0) {
			return ch;
		} else {
			ch = -1-ch;
			curSz += ch;
		}
	}

	if (curSz * 2 >= sz) {
		return cur;
	} else {
		return -1-curSz;
	}
}

vector<pair<pair<int, int>, pair<int, int>>> ranges[MAXN];
set<pair<ll, int>> bestVals[MAXN];
vector<seg_tree> segs[MAXN];

void buildRanges(int cur, int e, int centroid, int seg_ind, int& ind) {
	assert(!isDead[cur]);
	int st = ind++;
	for (int f : adj[cur]) {
		if (f == e) continue;
		int nxt = E[f].other(cur);
		if (isDead[nxt]) continue;
		buildRanges(nxt, f, centroid, seg_ind, ind);
	}
	int en = ind;
	//cerr << "range " << e << ' ' << centroid << ' ' << seg_ind << ' ' << st << ' ' << en << '\n';
	ranges[e].emplace_back(pair<int, int>(centroid, seg_ind), pair<int, int>(st, en));
	segs[centroid][seg_ind].modify(st, en, E[e].w);
}

set<pair<ll, int>> bestCentroids;

ll centroidVal(int cur) {
	ll ans = 0;
	auto it = bestVals[cur].rbegin();
	if (it == bestVals[cur].rend()) return ans;
	ans += it->first;
	++it;
	if (it == bestVals[cur].rend()) return ans;
	ans += it->first;
	return ans;
}

void buildCentroid(int cur) {
	int sz = dfsSz(cur, -1);
	cur = getCentroid(cur, -1, sz);

	for (int e : adj[cur]) {
		int nxt = E[e].other(cur);
		if (isDead[nxt]) continue;
		int seg_ind = int(segs[cur].size());
		segs[cur].emplace_back(dfsSz(nxt, cur));
		int ind = 0;
		buildRanges(nxt, e, cur, seg_ind, ind);
		bestVals[cur].emplace(segs[cur][seg_ind].query(), seg_ind);
	}

	bestCentroids.emplace(centroidVal(cur), cur);

	isDead[cur] = true;
	for (int e : adj[cur]) {
		int nxt = E[e].other(cur);
		if (isDead[nxt]) continue;
		buildCentroid(nxt);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q >> W;
	for (int e = 0; e < N-1; e++) {
		cin >> E[e].c[0] >> E[e].c[1] >> E[e].w;
		E[e].c[0] --, E[e].c[1] --;
		adj[E[e].c[0]].push_back(e);
		adj[E[e].c[1]].push_back(e);
	}

	buildCentroid(0);

	//cerr << bestCentroids.rbegin()->first << '\n';

	ll last = 0;
	for (int q = 0; q < Q; q++) {
		int e; ll w;
		cin >> e >> w;
		e = (e + last) % (N-1);
		w = (w + last) % W;

		ll deltaW = w - E[e].w;

		for (auto it : ranges[e]) {
			int cur = it.first.first;
			int seg_ind = it.first.second;
			auto range = it.second;

			bestCentroids.erase(pair<ll, int>(centroidVal(cur), cur));
			bestVals[cur].erase(pair<ll, int>(segs[cur][seg_ind].query(), seg_ind));

			segs[cur][seg_ind].modify(range, deltaW);

			bestVals[cur].insert(pair<ll, int>(segs[cur][seg_ind].query(), seg_ind));
			bestCentroids.insert(pair<ll, int>(centroidVal(cur), cur));
		}

		E[e].w = w;

		ll ans = bestCentroids.rbegin()->first;
		cout << ans << '\n';
		last = ans;
	}

	return 0;
}