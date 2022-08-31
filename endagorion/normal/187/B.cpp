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

int N, M, R;
int state[61][61][61];

int getState(int s, int t, int k, const vector< vector< int > > &W) {
	if (s == t) {
		return 0;
	}
	if (k == -1) {
		return 1e9;
	}
	if (state[s][t][k] != -1) {
		return state[s][t][k];
	}
	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, W[s][i] + getState(i, t, k - 1, W));
	}

	return state[s][t][k] = ans;
}

int main() {
	fout.precision(10);
	fout << fixed;

	fin >> N >> M >> R;
	vector< vector< vector<int> > > w(M, vector< vector<int> >(N, vector<int>(N)));

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				fin >> w[i][j][k];
			}
		}
	}

	for (int c = 0; c < M; ++c) {
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					w[c][i][j] = min(w[c][i][j], w[c][i][k] + w[c][k][j]);
				}
			}
		}
	}

	vector< vector<int> > W(N, vector<int>(N, 1e9));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int c = 0; c < M; ++c) {
				W[i][j] = min(W[i][j], w[c][i][j]);
			}
		}
	}

	for (int i = 0; i < 61; ++i) {
		for (int j = 0; j < 61; ++j) {
			for (int k = 0; k < 61; ++k) {
				state[i][j][k] = -1;
			}
		}
	}

	for (int r = 0; r < R; ++r) {
		int s, t, k;
		fin >> s >> t >> k;
		int ans = 1e9;
		--s; --t;
		for (int i = 0; i < M; ++i) {
			ans = min(ans, getState(s, t, min(k, N), W));
		}
		fout << ans << '\n';
	}

	return 0;
}