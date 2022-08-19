#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N, M;
set<int> adj[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int e = 0; e < M; e++) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	vector<int> unadded;
	for (int i = 0; i < N; i++) {
		unadded.push_back(i);
	}
	vector<int> added;
	int ans = -1;
	for (int z = 0; z < N; z++) {
		if (z >= int(added.size())) {
			ans++;
			added.push_back(unadded.back());
			unadded.pop_back();
		}
		int cur = added[z];
		vector<int> nunadded;
		for (int v : unadded) {
			if (adj[cur].count(v)) nunadded.push_back(v);
			else added.push_back(v);
		}
		unadded = std::move(nunadded);
	}
	cout << ans << '\n';

	return 0;
}