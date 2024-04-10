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

double prob[201][201][401];

int main() {
	fout.precision(10);
	fout << fixed;

	int N, L, K;
	fin >> N >> L >> K;

	vector<int> p(N), pr(N);

	for (int i = 0; i < N; ++i) {
		fin >> p[i];
	}

	for (int i = 0; i < N; ++i) {
		fin >> pr[i];
	}

	for (int i = 0; i < 201; ++i) {
		for (int j = 0; j < 201; ++j) {
			for (int k = 0; k < 401; ++k) {
				prob[i][j][k] = 0.0;
			}
		}
	}

	prob[0][0][200 + K] = 1.0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= 400; ++k) {
				if (pr[i] > 0) {
					prob[i + 1][j + 1][min(k + pr[i], 400)] += 0.01 * prob[i][j][k] * p[i];
				} else {
					prob[i + 1][j + 1][max(k - 1, 0)] += 0.01 * prob[i][j][k] * p[i];
				}
				prob[i + 1][j][k] += 0.01 * prob[i][j][k] * (100 - p[i]); 
			}
		}
	}

	double ans = 0.0;
	for (int j = L; j <= N; ++j) {
		for (int k = 200; k <= 400; ++k) {
			ans += prob[N][j][k];
		}
	}

	fout << ans << '\n';

	return 0;
}