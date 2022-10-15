#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
#define MAXN 100000
#define MAXM 100000

int N, M;
vector<int> adj[MAXN];
int color[MAXN]; // for bipartite DFS
// color of 0 is not visited
// color of 1, 2 is red, blue
int cpnt = 0;
int red[MAXN];
int blue[MAXN];

bool dfs_bipartite(int node, int c) {
	if (color[node] == c) {
		return true;
	}
	if (color[node] != 0 && color[node] != c) {
		// visited, but opposite color!
		return false;
	}

	// if we're here, the node is unvisited. tiem to do work!
	color[node] = c;
	if (c == 1) {
		red[cpnt]++;
	}
	else {
		blue[cpnt]++;
	}
	int new_color = 3 - c; // 1 -> 2, 2 -> 1
	for (int next : adj[node]) {
		bool result = dfs_bipartite(next, new_color);
		if (!result) {
			// oh shoot, not bipartite, stop everything and propogate result
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		A--; B--;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	if (M == 0) { // such wow, zero edges!
		LL ans = ((LL) N) * (N - 1) * (N - 2) / 6; // C(N, 3)
		cout << 3 << ' ' << ans << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		if (color[i] == 0) {
			bool result = dfs_bipartite(i, 1);
			if (!result) {
				// not bipartite; there exists an odd length cycle
				cout << 0 << ' ' << 1 << endl;
				return 0;
			}
			cpnt++;
		}
	}

	bool bad = true;
	LL ans = 0;
	for (int cp = 0; cp < cpnt; cp++) {
		if (red[cp] + blue[cp] > 2) {
			bad = false;
		}
		ans += (((LL) red[cp]) * (red[cp] - 1)) / 2;
		ans += (((LL) blue[cp]) * (blue[cp] - 1)) / 2;
	}

	if (!bad) {
		cout << 1 << ' ' << ans << endl;
	}
	else {
		// 2 edges needed; every edge has N-2 possibilities
		cout << 2 << ' ' << ((LL) M) * (N - 2) << endl;
	}

	return 0;
}