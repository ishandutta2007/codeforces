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
	long long N;
	fin >> N;

	long long minA = 1e18;
	long long maxA = -1e18;

	for (long long a = 1; a * a * a <= N; ++a) {
		if (N % a != 0) {
			continue;
		}
		for (long long b = a; a * b * b <= N; ++b) {
			if (N % (a * b) != 0) {
				continue;
			}
			long long c = N / (a * b);
			minA = min(minA, (a + 1) * (b + 2) * (c + 2) - a * b * c);
			minA = min(minA, (a + 2) * (b + 1) * (c + 2) - a * b * c);
			minA = min(minA, (a + 2) * (b + 2) * (c + 1) - a * b * c);
			maxA = max(maxA, (a + 1) * (b + 2) * (c + 2) - a * b * c);
			maxA = max(maxA, (a + 2) * (b + 1) * (c + 2) - a * b * c);
			maxA = max(maxA, (a + 2) * (b + 2) * (c + 1) - a * b * c);
		}
	}

	fout << minA << ' ' << maxA << '\n';
	return 0;
}