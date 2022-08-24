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

	const int MAXN = 10000010;
	vector<long long> pages(MAXN + 1), sums(MAXN + 1);
	for (int q = 1; q * q <= MAXN; ++q) {
		for (int k = 1; k * q * q <= MAXN; ++k) {
			pages[k * q * q] = k;
		}
	}
	sums[0] = 0;
	for (int i = 1; i <= MAXN; ++i) {
		sums[i] = sums[i - 1] + pages[i];
	}

	int A, N;
	fin >> A >> N;
	fout << sums[A + N - 1] - sums[A - 1] << '\n';

	return 0;
}