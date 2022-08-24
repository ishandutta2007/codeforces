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
	long long l, v1, v2;
	fin >> N >> l >> v1 >> v2;
	vector<long long> a(2 * N);
	for (int i = 0; i < N; ++i) {
		fin >> a[i];
		a[i + N] = a[i] + 2 * l;
	}
	a.push_back((long long)1e10);

	int li = 0, ri = 0;
	double x = 0;
	double d = 1.0 * v2 * l / (v1 + v2);
	
	while (a[ri] <= d) {
		++ri;
	}

	vector<double> probs(N + 1, 0.0);

	while (2 * l - x > 1e-6) {
		double dd = min(a[li] - x, a[ri] - x - d);
		dd = min(dd, 2 * l - x);
		probs[ri - li] += dd / (2 * l);
		x += dd;
		while (li < 2 * N && x - a[li] > -1e-6) {
			++li;
		}
		while (ri < 2 * N && x + d - a[ri] > -1e-6) {
			++ri;
		}
	}

	for (int i = 0; i <= N; ++i) {
		fout << probs[i] << '\n';
	}

	return 0;
}