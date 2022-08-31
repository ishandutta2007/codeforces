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

	int N;
	fin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		fin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		fin >> B[i];
	}

	int i = 0, j = 0;
	while (i < N) {
		while (j < N && B[j] != A[i]) {
			++j;
		}
		if (j == N) {
			break;
		}
		++i;
	}

	fout << N - i << '\n';

	return 0;
}