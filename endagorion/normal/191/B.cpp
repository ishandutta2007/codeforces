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

	int N, K;
	fin >> N >> K;
	long long B;
	fin >> B;
	vector< long long > sq(N);
	for (int i = 0; i < N; ++i) {
		fin >> sq[i];
	}

	int ans = N;
	multiset< long long > exp;
	long long S = 0;
	for (int i = N - 2; i >= 0; --i) {
		if (S + sq[i] > B) {
			ans = i + 1;
		}
		S += sq[i];
		exp.insert(sq[i]);
		if (exp.size() > K - 1) {
			S -= *exp.begin();
			exp.erase(exp.begin());
		}
	}

	fout << ans << '\n';

	return 0;
}