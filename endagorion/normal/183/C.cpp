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

struct TEdge {
	int to, d;

	TEdge(int _to, int _d)
		: to(_to)
		, d(_d)
	{
	}
};

int GCD(int a, int b) {
	return b == 0 ? a : GCD(b, a % b);
}

int paintDfs(int x, vector<int> &paint, const vector< vector<TEdge> > &edges, int minK, int cur) {
	paint[x] = cur;
	for (size_t i = 0; i < edges[x].size(); ++i) {
		int pres = cur + edges[x][i].d;
		int y = edges[x][i].to;
		if (paint[y] != -1000000) {
			minK = GCD(minK, abs(pres - paint[y]));
		} else {
			minK = paintDfs(y, paint, edges, minK, pres);
		}
	}
	return minK;
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N, M;
	fin >> N >> M;
	vector< vector<TEdge> > edges(N);
	for (int i = 0; i < M; ++i) {
		int x, y;
		fin >> x >> y;
		--x; --y;
		edges[x].push_back(TEdge(y, 1));
		edges[y].push_back(TEdge(x, -1));
	}
	vector<int> painted(N, -1000000);
	int minK = 0;
	for (size_t i = 0; i < N; ++i) {
		if (painted[i] == -1000000) {
			minK = paintDfs(i, painted, edges, minK, 0);
		}
	}
	if (minK == 0) {
		fout << N << '\n';
	} else {
		fout << minK << '\n';
	}

	return 0;
}