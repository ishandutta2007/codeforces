#include <bits/stdc++.h>
using namespace std;

void findcolours(vector<int> adj[], int vis[], int curr, int cc, int neq, int mod) {
	vis[curr] = cc;
	for (int i = 0; i < adj[curr].size(); i++) {
		if (!vis[adj[curr][i]]) {
			cc = cc % mod + 1;
			while (cc == neq)
				cc = cc % mod + 1;
			findcolours(adj, vis, adj[curr][i], cc, vis[curr], mod);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int squares, a, b;
	cin >> squares;
	vector<int> adjlist[squares];
	for (int i = 1; i < squares; i++) {
		cin >> a >> b;
		adjlist[a-1].push_back(b-1);
		adjlist[b-1].push_back(a-1);
	}
	int colours = 0;
	for (int i = 0; i < squares; i++)
		if (colours < adjlist[i].size())
			colours = adjlist[i].size();
	cout << ++colours << endl;

	int visited[squares];
	memset(visited, 0, sizeof(visited));
	findcolours(adjlist, visited, 0, 1, 0, colours);
	for (int i = 0; i < squares; i++)
		cout << visited[i] << " ";
	cout << endl;
	
	return 0;
}