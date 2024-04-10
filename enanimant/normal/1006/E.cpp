// July 16, 2018


#include <bits/stdc++.h>

using namespace std;


const int MAXN = (int) 2e5;


struct Node {
	int id;
	int subtree_size;
};

int N, Q;
vector<int> adj[MAXN + 1];
Node nodes[MAXN + 1];
int ind[MAXN + 1]; // ind[x] gives the value such that nodes[ind[x]].id == x.
int next_ind = 1;


void dfs(int s, int e) {
	int i = next_ind++;
	ind[s] = i;
	nodes[i].id = s;
	nodes[i].subtree_size = 1;
	for (int u : adj[s]) {
		if (u == e) continue;
		dfs(u, s);
		nodes[i].subtree_size += nodes[ind[u]].subtree_size;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)



	cin >> N >> Q;
	for (int a = 2; a <= N; a++) {
		int b;
		cin >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	while (Q--) {
		int u, k;
		cin >> u >> k;
		if (nodes[ind[u]].subtree_size < k) {
			cout << "-1\n";
		} else {
			cout << nodes[ind[u] + k - 1].id << '\n';
		}
	}


	return 0;
}