#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
#define MAXM 300013
int N, M;
vector<int> adj[MAXN];
int D[MAXN];
map<pair<int, int>, int> e_to_idx;
vector<int> ch[MAXN];
bool visited[MAXN];
vector<int> ans;

int dfs(int n, int p) {
	visited[n] = true;
	int deg = 0;
	for (int v : adj[n]) if (!visited[v]) {
		int use = dfs(v, n);
		deg += use;
	}
	deg %= 2;
	if (deg != D[n]) {
		assert(n);
		ans.push_back(e_to_idx[{n, p}]);
		return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	int degreeSum = 0;
	bool hasNeg = false;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
		if (D[i] == -1) {
			hasNeg = true;
		}
		else {
			degreeSum += D[i];
		}
	}

	degreeSum %= 2;

	if (degreeSum % 2 == 1 && !hasNeg) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		if (D[i] == -1) {
			if (degreeSum) {
				degreeSum = 0;
				D[i] = 1;
			}
			else {
				D[i] = 0;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		e_to_idx[{a, b}] = e_to_idx[{b, a}] = i + 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1);

	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int x : ans) {
		cout << x << '\n';
	}
	cout << flush;
	return 0;
}