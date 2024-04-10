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

int dfs(int x, int y, vector<string> &f) {
	f[x][y] = '$';
	int res = 1;
	int N = f.size();
	int M = f[0].size();
	for (int d = 0; d < 4; ++d) {
		int xx = x + dx[d];
		int yy = y + dy[d];
		if (xx < 0 || xx >= N || yy < 0 || yy >= M) {
			continue;
		}
		if (f[xx][yy] == '#') {
			res += dfs(xx, yy, f);
		}
	}
	return res;
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N, M;
	fin >> N >> M;
	vector<string> f(N);
	int filled = 0;
	for (int i = 0; i < N; ++i) {
		fin >> f[i];
		for (int j = 0; j < M; ++j) {
			if (f[i][j] == '#') {
				++filled;
			}
		}
	}

	if (filled <= 2) {
		fout << -1 << '\n';
		return 0;
	}

	int res = 2;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (f[i][j] == '.') {
				continue;
			}
			vector<string> ff = f;
			f[i][j] = '.';
			bool ok;
			for (int k = 0; k < N; ++k) {
				for (int l = 0; l < M; ++l) {
					if (f[k][l] == '#') {
						ok = (dfs(k, l, f) == filled - 1);
						k = N;
						break;
					}
				}
			}
			f = ff;
			if (!ok) {
				res = 1;
				i = N;
				break;
			}
		}
	}

	fout << res << '\n';

	return 0;
}