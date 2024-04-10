#include<bits/stdc++.h>
using namespace std;

void wssert(bool b) {
	if (!b) {
		cout << "GARBAGE\n";
		exit(0);
	}
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1.1e6;
const int MAXM = 2.1e6;
int N, M;
pair<int, int> E[MAXM];

int oldN, oldM;

vector<pair<int, int>> adj[MAXN];
bool used[MAXM];
bool take[MAXM];

void dfs(int start) {
	int stackPos = 0;

	stack<int> st;
	st.push(start);
	while (!st.empty()) {
		int cur = st.top();
		if (adj[cur].empty()) {
			st.pop();
			if (st.empty()) return;
			int e = st.top(); st.pop();
			stackPos ^= 1;
			take[e] = stackPos;
			continue;
		} else {
			int nxt = adj[cur].back().first;
			int e = adj[cur].back().second;
			adj[cur].pop_back();
			if (used[e]) {
				continue;
			}
			used[e] = true;
			st.push(e);
			st.push(nxt);
		}
	}
}

int extraTake[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	oldN = N, oldM = M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; u--, v--;
		E[i] = {u, v};
	}

	for (int e = 0; e < M; e++) {
		int u = E[e].first, v = E[e].second;
		adj[u].emplace_back(v, e);
		adj[v].emplace_back(u, e);
	}

	for (int i = 0; i < N; i++) {
		if (adj[i].size() % 2 == 1) {
			int e = M++;
			E[e] = {i, N};
			adj[i].emplace_back(N, e);
			adj[N].emplace_back(i, e);
		}
	}
	N++;

	for (int i = 0; i < N; i++) {
		dfs(i);
		assert(adj[i].empty());
	}

	N = oldN;

	for (int e = oldM; e < M; e++) {
		if (take[e]) {
			assert(E[e].second == N);
			extraTake[E[e].first]++;
		}
	}

	M = oldM;

	for (int e = 0; e < M; e++) {
		int u = E[e].first, v = E[e].second;
		adj[u].emplace_back(v, e);
		adj[v].emplace_back(u, e);
	}

	for (int i = 0; i < N; i++) {
		//cerr << i << ' ' << extraTake[i] << '\n';
		for (auto it : adj[i]) {
			int e = it.second;
			//cerr << "cnd " << e << '\n';
			if (e >= M) continue;
			if (take[e]) continue;
			if (extraTake[i] > 0) {
				//cerr << "extra " << e << '\n';
				take[e] = true, extraTake[i] --;
			}
		}
	}

	int K = 0;
	for (int e = 0; e < M; e++) {
		K += take[e];
	}
	cout << K << '\n';
	for (int e = 0; e < M; e++) {
		if (take[e]) {
			cout << E[e].first+1 << ' ' << E[e].second+1 << '\n';
		}
	}

	wssert(K <= (N+M+1) / 2);
	vector<int> takeDeg(N);
	for (int e = 0; e < M; e++) {
		if (take[e]) takeDeg[E[e].first]++, takeDeg[E[e].second]++;
	}
	for (int i = 0; i < N; i++) {
		wssert(takeDeg[i] >= (int(adj[i].size()) + 1) / 2);
	}

	return 0;
}