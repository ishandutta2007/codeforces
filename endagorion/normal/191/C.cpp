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

void build_up(int x, int p, const vector< vector<int> > &edges, vector<int> &up, vector<int> &d) {
	up[x] = p;
	if (p != -1) {
		d[x] = d[p] + 1;
	}
	for (size_t i = 0; i < edges[x].size(); ++i) {
		int y = edges[x][i];
		if (y == p) {
			continue;
		}
		build_up(y, x, edges, up, d);
	}
}

int get_up(int x, int h, const vector< vector<int> > &up) {
	for (int i = 17; i >= 0; --i) {
		if (h >= (1 << i)) {
			h -= (1 << i);
			x = up[i][x];
		}
	}
	return x;
}

int lcad(int x, int y, const vector< vector<int> > &up, const vector<int> &d) {
	if (d[y] > d[x]) {
		swap(x, y);
	}
	x = get_up(x, d[x] - d[y], up);
	if (x == y) {
		return d[x];
	}
	for (int i = 17; i >= 0; --i) {
		if (up[i][x] != up[i][y]) {
			x = up[i][x];
			y = up[i][y];
		}
	}
	return d[x] - 1;
}

void add_up(int x, int h, const vector< vector<int> > &up, vector< vector<int> > &ups) {
	for (int i = 17; i >= 0; --i) {
		if (h >= (1 << i)) {
			h -= (1 << i);
			++ups[i][x];
			x = up[i][x];
			if (x == -1) {
				break;
			}
		}
	}
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N;
	fin >> N;
	vector< vector<int> > edges(N);
	vector< pair<int, int> > eedges(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		fin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
		eedges[i] = make_pair(x, y);
	}
	vector< vector<int> > up(18, vector<int>(N, -1));
	vector<int> d(N);
	d[0] = 0;
	build_up(0, -1, edges, up[0], d);
	for (int i = 1; i < 18; ++i) {
		for (int x = 0; x < N; ++x) {
			if (up[i - 1][x] == -1) {
				up[i][x] = -1;
			} else {
				up[i][x] = up[i - 1][up[i - 1][x]];
			}
		}
	}

	vector< vector<int> > ups(18, vector<int>(N, 0));
	int M;
	fin >> M;
	for (int i = 0; i < M; ++i) {
		int x, y;
		fin >> x >> y;
		--x; --y;
		int dd = lcad(x, y, up, d);
		add_up(x, d[x] - dd, up, ups);
		add_up(y, d[y] - dd, up, ups);
	}

	for (int i = 17; i > 0; --i) {
		for (int x = 0; x < N; ++x) {
			int c = ups[i][x];
			ups[i][x] = 0;
			ups[i - 1][x] += c;
			if (up[i - 1][x] >= 0) {
				ups[i - 1][up[i - 1][x]] += c;
			}
		}
	}

	for (int i = 0; i < N - 1; ++i) {
		int x = eedges[i].first, y = eedges[i].second;
		if (d[x] < d[y]) {
			swap(x, y);
		}
		fout << ups[0][x] << '\n';
	}

	return 0;
}