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

bool win(long long a, long long b) {
	if (a > b) {
		swap(a, b);
	}
	if (a == 0) {
		return false;
	}
	bool next = win(a, b % a);
	return !next || (((b / a) % (a + 1)) % 2 == 0);
}

int main() {
	fout.precision(10);
	fout << fixed;
	
	int T;
	fin >> T;
	for (int t = 0; t < T; ++t) {
		long long A, B;
		fin >> A >> B;
		if (win(A, B)) {
			fout << "First\n";
		} else {
			fout << "Second\n";
		}
	}

	return 0;
}