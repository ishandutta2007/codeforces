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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct TPos {
	int x, y, d;
	TPos(int _x = 0, int _y = 0, int _d = 0)
		: x(_x)
		, y(_y)
		, d(_d)
	{
	}
};

int main() {
	fout.precision(10);
	fout << fixed;

	int N, M;
	fin >> N >> M;
	vector<string> field(N);
	for (int i = 0; i < N; ++i) {
		fin >> field[i];
	}

	vector< vector< vector<int> > > minWay(N, vector<vector<int> >(M, vector<int>(4, (int)1e9)));
	minWay[N - 1][M - 1][3] = 0;
	vector< vector<TPos> > q(2);
	int cur = 0;
	q[0].push_back(TPos(N - 1, M - 1, 3));
	while (!q[0].empty() || !q[1].empty()) {
		if (q[cur].empty()) {
			cur = 1 - cur;
		}
		TPos curpos = q[cur].back();
		q[cur].pop_back();
		int x = curpos.x;
		int y = curpos.y;
		int d = curpos.d;
		for (int dd = 0; dd < 4; ++dd) {
			int xx, yy;
			if (dd == d) {
				xx = x + dx[d];
				yy = y + dy[d];
				if (xx < 0 || xx >= N || yy < 0 || yy >= M) {
					continue;
				}
			} else {
				if (field[x][y] == '.') {
					continue;
				}
				xx = x;
				yy = y;
			}
			if (minWay[xx][yy][dd] == (int)1e9) {
				if (dd == d) {
					minWay[xx][yy][dd] = minWay[x][y][d];
					q[cur].push_back(TPos(xx, yy, dd));
				} else {
					minWay[xx][yy][dd] = minWay[x][y][d] + 1;
					q[1 - cur].push_back(TPos(xx, yy, dd));
				}
			}
		}
	}

	int ans = minWay[0][0][3];
	if (ans == (int)1e9) {
		fout << -1 << '\n';
	} else {
		fout << ans << '\n';
	}

	return 0;
}