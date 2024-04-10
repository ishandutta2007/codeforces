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

const long long P = 1000000000 + 7;

int main() {
	fout.precision(10);
	fout << fixed;

	long long N;
	fin >> N;

	if (N == 0) {
		fout << "1\n";
		return 0;
	}

	long long Q = (deg(2, 2 * N - 1, P) + deg(2, N - 1, P)) % P;
	fout << Q << '\n';

	return 0;
}