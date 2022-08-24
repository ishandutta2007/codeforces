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

	int N, A, D;
	fin >> N >> A >> D;

	double last = 0.0;

	for (int i = 0; i < N; ++i) {
		int t, v;
		fin >> t >> v;
		double cur;
		double L = 0.5 * v * v / A;
		double T = 1.0 * v / A;
		if (L < D) {
			cur = t + T + (D - L) / v;
		} else {
			cur = t + sqrt(2.0 * D / A);
		}

		last = max(last, cur);
		fout << last << '\n';
	}

	return 0;
}