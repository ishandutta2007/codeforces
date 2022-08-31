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
	int N;
	fin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		fin >> a[i];
	}
	int ans = -1e9;
	for (int k = 1; k <= N / 3; ++k) {
		if (N % k != 0) {
			continue;
		}
		vector<int> sums(k);
		for (int i = 0; i < N; ++i) {
			sums[i % k] += a[i];
		}
		for (int i = 0; i < k; ++i) {
			ans = max(ans, sums[i]);
		}
	}

	fout << ans << '\n';

	return 0;
}