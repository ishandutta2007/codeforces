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

bool reach(int s, int t, const vector< vector<int> > &edges, const vector<int> &minD, int lim, vector<bool> &vis) {
	if (s == t) {
		return true;
	}
	vis[s] = true;
	bool ok = false;
	for (size_t i = 0; i < edges[s].size(); ++i) {
		int v = edges[s][i];
		if (minD[v] <= lim && !vis[v]) {
			ok |= reach(v, t, edges, minD, lim, vis);
		}
	}
	return ok;
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N, M, K;
	fin >> N >> M >> K;
	vector<int> start(K);
	for (int i = 0; i < K; ++i) {
		fin >> start[i];
		--start[i];
	}
	vector< vector<int> > edges(N + M);
	for (int i = 0; i < M; ++i) {
		int x, y;
		fin >> x >> y;
		--x; --y;
		edges[x].push_back(N + i);
		edges[N + i].push_back(x);
		edges[N + i].push_back(y);
		edges[y].push_back(N + i);
	}

	vector<int> minD(N + M, 1e9);
	int s, t;
	fin >> s >> t;
	--s; --t;
	start.push_back(t);
	for (size_t i = 0; i < start.size(); ++i) {
		minD[start[i]] = 0;
	}
	size_t cur = 0;
	while (cur < start.size()) {
		int v = start[cur];
		for (size_t i = 0; i < edges[v].size(); ++i) {
			int u = edges[v][i];
			if (minD[u] < 1e9) {
				continue;
			}
			minD[u] = minD[v] + 1;
			start.push_back(u);
		}
		++cur;
	}

	int l = 0, r = N + 1;
	vector<bool> vis(N + M, false);
	while (r - l > 1) {
		int m = (l + r) / 2;
		vis.assign(N + M, false);
		if (reach(s, t, edges, minD, m, vis)) {
			r = m;
		} else {
			l = m;
		}
	}

	vis.assign(N + M, false);
	if (reach(s, t, edges, minD, r, vis)) {
		fout << r << '\n';
	} else {
		fout << -1 << '\n';
	}

	return 0;
}