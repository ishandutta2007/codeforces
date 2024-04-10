#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
int N, Q;
int parent[MAXN];
vector<int> ch[MAXN];
int sz[MAXN];
int cent[MAXN];

void dfs(int n) {
	sz[n] = 1;
	for (int v : ch[n]) {
		dfs(v);
		sz[n] += sz[v];
	}
	for (int v : ch[n]) {
		if (sz[v] * 2 > sz[n]) {
			// heavy vertex!
			int c = cent[v];
			while (true) {
				int rest = sz[n] - sz[c];
				if (rest * 2 > sz[n]) {
					c = parent[c];
				}
				else {
					break;
				}
			}
			cent[n] = c;
			return;
		}
	}
	cent[n] = n;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		cin >> parent[i];
		parent[i]--;
		ch[parent[i]].push_back(i);
	}

	dfs(0);

	while (Q--) {
		int v; cin >> v; --v;
		cout << cent[v] + 1 << '\n';
	}

	cout.flush();
	return 0;
}