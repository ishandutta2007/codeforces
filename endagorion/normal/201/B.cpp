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
	vector< vector<long long> > a(N, vector<long long>(M));
	vector<long long> sx(N), sy(M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			fin >> a[i][j];
			sx[i] += a[i][j];
			sy[j] += a[i][j];
		}
	}

	long long mx = 1e18, my = 1e18;
	int xx = -1, yy = -1;
	for (int i = 0; i <= N; ++i) {
		long long s = 0;
		int x1 = 4 * i;
		for (int j = 0; j < N; ++j) {
			int x2 = 4 * j + 2;
			s += sx[j] * (x1 - x2) * (x1 - x2);
		}
		if (s < mx) {
			mx = s;
			xx = i;
		}
	}

	for (int i = 0; i <= M; ++i) {
		long long s = 0;
		int x1 = 4 * i;
		for (int j = 0; j < M; ++j) {
			int x2 = 4 * j + 2;
			s += sy[j] * (x1 - x2) * (x1 - x2);
		}
		if (s < my) {
			my = s;
			yy = i;
		}
	}

	fout << mx + my << '\n';
	fout << xx << ' ' << yy << '\n';

	return 0;
}