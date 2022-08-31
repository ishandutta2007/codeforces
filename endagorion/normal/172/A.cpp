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
	vector<string> numbers(N);
	for (int i = 0; i < N; ++i) {
		fin >> numbers[i];
	}

	int k = 0;
	int M = numbers[0].length();
	bool ok = true;
	while (k < M) {
		for (int i = 1; i < N; ++i) {
			ok = ok & (numbers[i][k] == numbers[0][k]);
		}
		if (!ok) {
			break;
		}
		++k;
	}

	fout << k << '\n';

	return 0;
}