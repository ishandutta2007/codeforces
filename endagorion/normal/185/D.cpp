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

long long deg(long long x, long long d, long long P) {
	if (d == 0) {
		return 1;
	}
	long long y = deg(x, d / 2, P);
	y = (y * y) % P;
	if (d % 2) {
		y = (y * x) % P;
	}
	return y;	
}

int main() {
	fout.precision(10);
	fout << fixed;

	int T;
	fin >> T;
	for (int t = 0; t < T; ++t) {
		long long K, L, R, P;
		fin >> K >> L >> R >> P;
		if (P == 2) {
			fout << (K + 1) % 2 << '\n';
			continue;
		}
		long long d = deg(2, L, P - 1);
		long long q = deg(K, d, P);
		if (K % P == 0) {
			q = 0;
		}
		R -= L - 1;
		long long ans;
		if (q == 0) {
			ans = 1;
		} else
		if (q == 1) {
			ans = deg(2, R, P);
		} else {
			long long rd = deg(2, R, P - 1);
			ans = (deg(q, rd, P) + P - 1) % P;
			ans = (ans * deg((q + P - 1) % P, P - 2, P)) % P;
		}
		if (K % 2 == 1) {
			long long _2 = deg(2, P - 2, P);
			ans = (ans * deg(_2, R - 1, P)) % P;
		}
		fout << ans << '\n';
	}

	return 0;
}