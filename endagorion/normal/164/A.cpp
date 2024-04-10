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

int main() {
	fout.precision(10);
	fout << fixed;

	int N, M;
	fin >> N >> M;
	vector<int> state(N);
	for (int i = 0; i < N; ++i) {
		fin >> state[i];
	}

	vector< vector<int> > edges(N), invEdges(N);
	for (int i = 0; i < M; ++i) {
		int x, y;
		fin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		invEdges[y].push_back(x);
	}

	vector<int> q, invq;
	vector<bool> vis(N, false), invVis(N, false);
	for (int i = 0; i < N; ++i) {
		if (state[i] == 1) {
			q.push_back(i);
			vis[i] = true;
		}
		if (state[i] == 2) {
			invq.push_back(i);
			invVis[i] = true;
		}
	}
	int cur = 0;
	while (cur < q.size()) {
		int v = q[cur++];
		for (size_t i = 0; i < edges[v].size(); ++i) {
			int u = edges[v][i];
			if (!vis[u]) {
				q.push_back(u);
				vis[u] = true;
			}
		}
	}

	cur = 0;
	while (cur < invq.size()) {
		int v = invq[cur++];
		if (state[v] == 1) {
			continue;
		}
		for (size_t i = 0; i < invEdges[v].size(); ++i) {
			int u = invEdges[v][i];
			if (!invVis[u]) {
				invq.push_back(u);
				invVis[u] = true;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		if (vis[i] && invVis[i]) {
			fout << "1\n";
		} else {
			fout << "0\n";
		}
	}

	return 0;
}