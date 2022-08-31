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
	long long A = 1, B = 1;
	for (int i = 0; i < N; ++i) {
		string s;
		fin >> s;
		if (s == "UR" || s == "DL") {
			++A;
		}
		if (s == "UL" || s == "DR") {
			++B;
		}
		if (s == "ULDR") {
			++A; ++B;
		}
	}

	fout << A * B << '\n';
	return 0;
}