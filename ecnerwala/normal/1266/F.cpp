#include<bits/stdc++.h>
using namespace std;

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 5.1e5;
int N;
int deg[MAXN];
pair<int, int> edges[MAXN];
vector<int> adj[MAXN];

pair<int, int> maxDist(int cur, int prv) {
	pair<int, int> ans(0, cur);
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		pair<int, int> ch = maxDist(nxt, cur);
		ch.first++;
		ans = max(ans, ch);
	}
	return ans;
}

int diameter() {
	return maxDist(maxDist(0, -1).second, -1).first;
}

int leafUp[MAXN];
int leafDown[MAXN];
int par[MAXN];

void dfsDown(int cur, int prv) {
	par[cur] = prv;
	leafDown[cur] = 0;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfsDown(nxt, cur);
		leafDown[cur] = max(leafDown[cur], leafDown[nxt]+1);
	}
}
void dfsUp(int cur, int prv) {
	int bestUp = leafUp[cur] + 1;
	int bestUp2 = -1;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		int cnd = leafDown[nxt] + 1;
		if (cnd > bestUp) {
			bestUp2 = bestUp;
			bestUp = cnd;
		} else if (cnd > bestUp2) {
			bestUp2 = cnd;
		}
	}
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		int cnd = leafDown[nxt] + 1;
		if (bestUp == cnd) {
			leafUp[nxt] = bestUp2;
		} else {
			leafUp[nxt] = bestUp;
		}
		dfsUp(nxt, cur);
	}
}

vector<int> leafVals[MAXN];
vector<int> bestCnt[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v; u--, v--;
		edges[i] = {u, v};
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfsDown(0, -1);
	leafUp[0] = -1;
	dfsUp(0, -1);

	vector<int> ans(N+1, 1);

	for (int cur = 0; cur < N; cur++) {
		int prv = par[cur];
		for (int nxt : adj[cur]) {
			if (nxt == prv) {
				leafVals[cur].push_back(leafUp[cur]);
			} else {
				leafVals[cur].push_back(leafDown[nxt]);
			}
		}

		assert(leafVals[cur].size() == adj[cur].size());
		sort(leafVals[cur].begin(), leafVals[cur].end());
		setmax(ans[1], int(leafVals[cur].size()) + 1);
		for (int i = 0; i+1 < int(leafVals[cur].size()); i++) {
			int maxK = min(leafVals[cur][i]+1, leafVals[cur][i+1]);

			setmax(ans[maxK * 2 + 1], int(leafVals[cur].size()) - i);
		}

		for (int i = 0; i+1 < int(leafVals[cur].size()); i++) {
			setmax(ans[leafVals[cur][i] * 2 + 2], int(leafVals[cur].size()) - i);
		}

		bestCnt[cur] = vector<int>(leafVals[cur].size(), 0);
	}

	for (int z = 0; z < N-1; z++) {
		int cur = z+1, prv = par[cur];
		if (adj[cur].size() > adj[prv].size()) swap(cur, prv);
		assert(int(adj[cur].size()) <= int(adj[prv].size()));
		for (int i = 0; i < int(leafVals[cur].size()); i++) {
			int up = int(upper_bound(leafVals[prv].begin(), leafVals[prv].end(), leafVals[cur][i]) - leafVals[prv].begin());
			up--;
			if (up >= 0) setmax(bestCnt[prv][up], int(leafVals[cur].size()) - i);

			int lo = int(lower_bound(leafVals[prv].begin(), leafVals[prv].end(), leafVals[cur][i]) - leafVals[prv].begin());
			setmax(bestCnt[cur][i], int(leafVals[prv].size()) - lo);
		}
	}

	for (int cur = 0; cur < N; cur++) {
		for (int i = int(leafVals[cur].size()) - 2; i >= 0; i--) {
			setmax(bestCnt[cur][i], bestCnt[cur][i+1]);
		}
		for (int i = 0; i < int(leafVals[cur].size()); i++) {
			int cnd = int(leafVals[cur].size()) - i + bestCnt[cur][i] - 2;
			if (cnd <= 1) continue;
			setmax(ans[2 * leafVals[cur][i] + 2], cnd);
		}
	}

	int diam = diameter();
	for (int i = N; i > 0; i--) {
		if (i <= diam) {
			ans[i] = max(ans[i], 2);
		} else {
			ans[i] = max(ans[i], 1);
		}
		if (i+2 < N) ans[i] = max(ans[i], ans[i+2]);
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " \n"[i==N];
	}

	return 0;
}