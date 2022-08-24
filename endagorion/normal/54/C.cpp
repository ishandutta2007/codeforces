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
	fout.precision(15);
	fout << fixed;

	int N;
	fin >> N;

	vector<long long> L(N), R(N);
	for (int i = 0; i < N; ++i) {
		fin >> L[i] >> R[i];
	}
	int K;
	fin >> K;

	vector< vector<long double> > prob(N + 1, vector<long double>(N + 1, 0.0));
	prob[0][0] = 1.0;

	vector<long double> q(N);
	for (int i = 0; i < N; ++i) {
		long long succ = 0;
		long long p = 1;
		for (int j = 0; j <= 18; p *= 10, ++j) {
			succ += max(min(R[i], 2 * p - 1) - max(L[i], p) + 1, 0LL);
		}
		q[i] = (long double)1.0 * succ / (R[i] - L[i] + 1);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			prob[i + 1][j + 1] += prob[i][j] * q[i];
			prob[i + 1][j] += prob[i][j] * ((long double)1.0 - q[i]);
		}
	}

	long double ans = 0.0;
	for (int i = 0; i <= N; ++i) {
		if (100 * i >= N * K) {
			ans += prob[N][i];
		}
	}

	fout << ans << '\n';

	return 0;
}