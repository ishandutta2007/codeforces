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

long long bind(int x, long long P) {
	if (x == 0) {
		return 1;
	}
	long long y = bind(x / 2, P);
	y = (y * y) % P;
	if (x % 2 == 1) {
		y = (2 * y) % P;
	}
	return y;
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N, M;
	fin >> N >> M;
	if (N % 2 != M % 2) {
		fout << 0 << '\n';
		return 0;
	}

	int K;
	fin >> K;
	int conds = (N - 1) * (M - 1) - K;
	vector<int> rows(N), cols(M), rowssum(N, 1), colssum(M, 1);
	bool ok = true;
	for (int i = 0; i < K; ++i) {
		int a, b, c;
		fin >> a >> b >> c;
		--a; --b;
		++rows[a]; rowssum[a] *= c;
		++cols[b]; colssum[b] *= c;
	}

	for (int i = 0; i < N; ++i) {
		if (rows[i] == M) {
			ok &= (rowssum[i] == -1);
			++conds;
		}
	}

	for (int i = 0; i < M; ++i) {
		if (cols[i] == N) {
			ok &= (colssum[i] == -1);
			++conds;
		}
	}

	int P;
	fin >> P;
	if (!ok) {
		fout << 0 << '\n';
	} else {
		fout << bind(conds, P);
	}

	return 0;
}