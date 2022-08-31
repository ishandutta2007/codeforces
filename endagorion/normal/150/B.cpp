#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

void dfs(int v, vector< vector<int> > &edges, vector<bool> &vis) {
	vis[v] = true;
	for (size_t i = 0; i < edges[v].size(); ++i) {
		if (!vis[edges[v][i]]) {
			dfs(edges[v][i], edges, vis);
		}
	}
}

int main() {
	int n, m, k;
	fin >> n >> m >> k;

	vector< vector<int> > edges(n);

	for (int i = 0; i + k <= n; ++i) {
		int l = i, r = i + k - 1;
		while (l < r) {
			edges[l].push_back(r);
			edges[r].push_back(l);
			++l; --r;
		}
	}

	vector<bool> visited(n, false);

	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			ans = (ans * m) % 1000000007;
			dfs(i, edges, visited);
		}
	}

	fout << ans << '\n';

	return 0;
}