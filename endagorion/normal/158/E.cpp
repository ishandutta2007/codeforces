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
	int N, K;
	fin >> N >> K;

	vector<int> t(N), d(N);
	for (int i = 0; i < N; ++i) {
		fin >> t[i] >> d[i];
	}

	vector< vector<int> > minLast(N + 1, vector<int> (K + 1, 86401));
	minLast[0].assign(K + 1, 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			if (j > 0) {
				minLast[i][j] = min(minLast[i][j], minLast[i - 1][j - 1]);
			}
			minLast[i][j] = min(minLast[i][j], max(minLast[i - 1][j], t[i - 1]) + d[i - 1]);
		}
	}

	int ans = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			int begin = minLast[i][j];
			int end;
			if (i + K - j >= N) {
				end = 86401;
			} else {
				end = t[i + K - j];
			}
			ans = max(ans, end - begin);
		}
	}

	fout << ans << '\n';

	return 0;
}