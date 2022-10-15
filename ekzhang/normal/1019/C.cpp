#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1000013
int N, M;
vector<int> adj[MAXN];
bool vis[MAXN];
bool incoming[MAXN];
bool ans[MAXN];

void rm(int n) {
	if (!vis[n]) {
		vis[n] = true;
		for (int v : adj[n])
			vis[v] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
	}

	vector<int> v;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			rm(i);
			v.push_back(i);
		}
	}

	reverse(v.begin(), v.end());
	for (int n : v) {
		if (!incoming[n]) {
			ans[n] = true;
			for (int u : adj[n]) {
				incoming[u] = true;
			}
		}
	}

	cout << accumulate(ans, ans + N, 0) << endl;
	for (int i = 0; i < N; i++) {
		if (ans[i])
			cout << i + 1 << ' ';
	}

	cout << endl;
	return 0;
}