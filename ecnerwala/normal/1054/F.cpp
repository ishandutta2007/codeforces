#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int N;
map<int, vector<int>> xs, ys;

const int MAXL = MAXN;
const int MAXR = MAXN;
int L, R;
int prv[MAXR];
int match[MAXL];
vector<int> adj[MAXL];

bool vis[MAXN];

bool dfs(int cur) {
	if (cur == -1) return true;
	if (vis[cur]) return false;
	vis[cur] = true;
	for (int nxt : adj[cur]) {
		int p = prv[nxt];
		int m = match[cur];
		prv[nxt] = cur;
		match[cur] = nxt;
		if (dfs(p)) {
			return true;
		}
		prv[nxt] = p;
		match[cur] = m;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		xs[x].push_back(y);
		ys[y].push_back(x);
	}

	for (auto& it : xs) {
		sort(it.second.begin(), it.second.end());
	}

	for (auto& it : ys) {
		sort(it.second.begin(), it.second.end());
	}

	L = 0;
	R = N - int(ys.size());
	for (auto& xit : xs) {
		int rind = 0;
		bool seen = false;
		for (auto& yit : ys) {
			auto it = lower_bound(yit.second.begin(), yit.second.end(), xit.first);
			if (it != yit.second.end() && *it == xit.first) {
				// we're overlapping
				if (seen) {
					L++;
				}
				seen = true;
			} else {
				// add it to the edges
				if (seen && it != yit.second.begin() && it != yit.second.end()) {
					adj[L].push_back(rind + int(it - yit.second.begin()) - 1);
				}
			}
			rind += int(yit.second.size()) - 1;
		}
		adj[L].clear();
		assert(adj[L].empty());
		assert(rind == R);
	}

	assert(L == N - int(xs.size()));
	assert(R == N - int(ys.size()));

	int flow = 0;
	memset(prv, -1, sizeof(prv));
	memset(match, -1, sizeof(match));
	for (int i = 0; i < L; i++) {
		if (dfs(i)) {
			flow++;
			memset(vis, 0, sizeof(vis));
		}
	}

	int cost = int(xs.size()) + int(ys.size());
	cost += flow;

	// we now need to actually find a min-cut
	memset(vis, 0, sizeof(vis));
	// we dfs from bad vertices to get our reachable set
	for (int i = 0; i < L; i++) {
		if (match[i] == -1) {
			dfs(i);
		}
	}

	int nh = 0;
	map<int, vector<int>> hs;
	// our cut is unreachable things on the left + reachable things on the right
	int lind = 0;
	for (auto& xit : xs) {
		nh++;
		hs[xit.first].push_back(xit.second.front());
		for (int i = lind; i < lind + int(xit.second.size()) - 1; i++) {
			if (!vis[i]) {
				// we're part of the cut
				hs[xit.first].push_back(xit.second[i - lind]);
				hs[xit.first].push_back(xit.second[i - lind+1]);
				nh++;
			}
		}
		lind += int(xit.second.size()) - 1;
		hs[xit.first].push_back(xit.second.back());
	}
	int nv = 0;
	map<int, vector<int>> vs;
	int rind = 0;
	for (auto& yit : ys) {
		nv++;
		vs[yit.first].push_back(yit.second.front());
		for (int j = rind; j < rind + int(yit.second.size()) - 1; j++) {
			if (prv[j] != -1 && vis[prv[j]]) {
				vs[yit.first].push_back(yit.second[j - rind]);
				vs[yit.first].push_back(yit.second[j - rind + 1]);
				nv++;
			}
		}
		rind += int(yit.second.size()) - 1;
		vs[yit.first].push_back(yit.second.back());
	}

	assert(nh + nv == cost);

	cout << nv << '\n';
	for (auto& it : vs) {
		for (int i = 0; i < int(it.second.size()); i += 2) {
			cout << it.second[i] << ' ' << it.first << ' ' << it.second[i+1] << ' ' << it.first << '\n';
		}
	}
	cout << nh << '\n';
	for (auto& it : hs) {
		for (int i = 0; i < int(it.second.size()); i += 2) {
			cout << it.first << ' ' << it.second[i] << ' ' << it.first << ' ' << it.second[i+1] << '\n';
		}
	}

	return 0;
}