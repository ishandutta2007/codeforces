#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
vector<int> adj[MAXN];

const int MAXK = 3.1e5;
int K;

int cost[MAXK][2];
pair<int, bool> par[MAXK];
void reset() {
	for (int k = 0; k <= K; k++) {
		cost[k][0] = 0;
		cost[k][1] = k ? 1 : 2*(K+1);
		par[k] = {-1, false};
	}
}

pair<int, bool> getPar(int a) {
	assert(0 <= a && a <= K);
	if (par[a].first < 0) return {a, false};

	bool v = par[a].second;
	par[a] = getPar(par[a].first);
	par[a].second ^= v;
	return par[a];
}

int ans = 0;
void merge(int a, int b, bool v) {
	auto pa = getPar(a);
	a = pa.first; v ^= pa.second;
	auto pb = getPar(b);
	b = pb.first; v ^= pb.second;
	
	if (a == b) {
		assert(v == false);
		return;
	}

	if (-par[a].first < -par[b].first) {
		swap(a, b);
	}
	par[a].first += par[b].first;
	par[b] = {a, v};

	ans -= min(cost[a][0], cost[a][1]);
	ans -= min(cost[b][0], cost[b][1]);
	cost[a][0] += cost[b][0^v];
	cost[a][1] += cost[b][1^v];
	ans += min(cost[a][0], cost[a][1]);
}

bool S[MAXN];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		// S[i] is 1 if it's off right now
		S[i] = (c == '0');
	}
	for (int k = 1; k <= K; k++) {
		int c; cin >> c;
		for (int i = 0; i < c; i++) {
			int x; cin >> x; x--;
			adj[x].push_back(k);
		}
	}

	reset();

	for (int i = 0; i < N; i++) {
		assert(adj[i].size() <= 2);
		while (adj[i].size() < 2) adj[i].push_back(0);

		merge(adj[i][0], adj[i][1], S[i]);
		cout << ans << '\n';
	}

	return 0;
}