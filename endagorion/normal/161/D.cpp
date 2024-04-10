#pragma comment(linker, "/STACK:50000000")

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

void precount(int v, const vector< vector<int> > &edges, vector<int> &p, vector<bool> &vis) {
	vis[v] = true;
	p[v] = -1;
	for (size_t i = 0; i < edges[v].size(); ++i) {
		int u = edges[v][i];
		if (vis[u]) {
			p[v] = u;
		} else {
			precount(u, edges, p, vis);
		}
	}
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N, K;
	fin >> N >> K;
	vector< vector<int> > edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		fin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	vector<int> p(N);
	vector<bool> vis(N);
	precount(0, edges, p, vis);

	vector< vector< int > > w_down(K + 1, vector< int >(N));
	vector< vector< int > > w_up(K + 1, vector< int >(N));

	for (int i = 0; i < N; ++i) {
		w_down[0][i] = w_up[0][i] = 1;
	}

	for (int k = 1; k <= K; ++k) {
		for (int i = 0; i < N; ++i) {
			for (size_t j = 0; j < edges[i].size(); ++j) {
				int u = edges[i][j];
				if (u != p[i]) {
					w_down[k][i] += w_down[k - 1][u];
				}
			}
			if (p[i] == -1) {
				continue;
			}
			if (k == 1) {
				w_up[k][i] = 1;
				continue;
			}
			w_up[k][i] = w_up[k - 1][p[i]] + w_down[k - 1][p[i]] - w_down[k - 2][i];	
		}
	}

	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += w_down[K][i] + w_up[K][i];
	}

	ans /= 2;
	fout << ans << '\n';

	return 0;
}