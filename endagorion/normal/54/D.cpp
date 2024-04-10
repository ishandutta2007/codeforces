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

	int N, K;
	fin >> N >> K;
	string P, Q;
	fin >> P >> Q;

	int M = P.size();

	vector< vector<int> > next(M + 1, vector<int>(K));
	for (int i = 0; i <= M; ++i) {
		for (int j = 0; j < K; ++j) {
			string pref = P.substr(0, i) + (char)(j + 'a');
			next[i][j] = 0;
			for (size_t l = 1; l <= pref.size() && l <= M; ++l) {
				bool ok = true;
				for (int p = 1; p <= l; ++p) {
					ok = ok && (pref[pref.size() - p] == P[l - p]);
				}
				if (ok) {
					next[i][j] = l;
				}
			}
		}
	}

	vector< vector<int> > prev(N + 1, vector<int>(M + 1, -1)), cv(N + 1, vector<int>(M + 1, -1));
	prev[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int c = 0; c < K; ++c) {
				int jj = next[j][c];
				bool ok = prev[i][j] != -1;
				if (i + 1 >= M && (Q[i + 1 - M] == '1') != (jj == M)) {
					ok = false;
				}
				if (ok) {
					prev[i + 1][jj] = j;
					cv[i + 1][jj] = c;
				}
			}
		}
	}

	string ans;
	int cur = -1;
	for (int i = 0; i <= M; ++i) {
		if (prev[N][i] != -1) {
			cur = i;
		}
	}

	if (cur != -1) {
		int i = N;
		while (i > 0) {
			ans += (char)('a' + cv[i][cur]);
			cur = prev[i][cur];
			--i;
		}
		reverse(ans.begin(), ans.end());
		fout << ans << '\n';
	} else {
		fout << "No solution\n";
	}

	return 0;
}