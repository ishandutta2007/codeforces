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

int game(char first, char second) {
	if (first == second) {
		return 0;
	}
	switch (first) {
	case 'R': return (second == 'S') ? 1 : -1;
	case 'S': return (second == 'P') ? 1 : -1;
	case 'P': return (second == 'R') ? 1 : -1;
	}
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N;
	fin >> N;
	string s, t;
	fin >> s >> t;
	int M = s.length(), K = t.length();

	int first = 0, second = 0;
	int full = N / (M * K);
	int firstFull = 0, secondFull = 0;

	for (int i = 0; i < M * K; ++i) {
		int res = game(s[i % M], t[i % K]);
		if (res > 0) {
			++firstFull;
		}
		if (res < 0) {
			++secondFull;
		}
	}
	first = full * firstFull;
	second = full * secondFull;
	for (int i = 0; i < N % (M * K); ++i) {
		int res = game(s[i % M], t[i % K]);
		if (res > 0) {
			++first;
		}
		if (res < 0) {
			++second;
		}
	}
	
	fout << second << ' ' << first << '\n';

	return 0;
}