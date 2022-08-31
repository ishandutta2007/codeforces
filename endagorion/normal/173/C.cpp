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
	vector< vector<int> > field(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			fin >> field[i][j];
		}
	}
	vector< vector<int> > sums(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			sums[i][j] = field[i][j];
			if (i > 0) {
				sums[i][j] += sums[i - 1][j];
			}
			if (j > 0) {
				sums[i][j] += sums[i][j - 1];
			}
			if (i > 0 && j > 0) {
				sums[i][j] -= sums[i - 1][j - 1];
			}
		}
	}

	vector< vector< vector<int> > > spirals(2);
	spirals[0] = spirals[1] = field;
	int cur = 1;
	int ans = -1e9;
	for (int k = 3; k <= min(N, M); k += 2) {
		for (int i = 0; i + k - 1 < N; ++i) {
			for (int j = 0; j + k - 1 < M; ++j) {
				int sq = sums[i + k - 1][j + k - 1];
				if (i > 0) {
					sq -= sums[i - 1][j + k - 1];
				}
				if (j > 0) {
					sq -= sums[i + k - 1][j - 1];
				}
				if (i > 0 && j > 0) {
					sq += sums[i - 1][j - 1];
				}
				spirals[cur][i][j] = sq - spirals[1 - cur][i + 1][j + 1] - field[i + 1][j];
				ans = max(ans, spirals[cur][i][j]);
			}
		}
		cur = 1 - cur;
	}

	fout << ans << '\n';

	return 0;
}