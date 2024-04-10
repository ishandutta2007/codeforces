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
	int n, m, k;
	fin >> n >> m >> k;

	bool firstFree = false, secondFree = false;
	bool posMove = false;
	int xsum = 0;
	vector<int> grs;
	for (int i = 0; i < n; ++i) {
		string s;
		fin >> s;
		int first = -1, second = -1;
		bool stuck = true;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'G') {
				first = j;
			}
			if (s[j] == 'R') {
				second = j;
			}
			if (s[j] == '-') {
				stuck = false;
			}
		}

		if (stuck) {
			continue;
		}
		firstFree |= (first != -1 && second == -1);
		secondFree |= (second != -1 && first == -1);
		if (first >= 0 && second >= 0) {
			grs.push_back(abs(first - second) - 1);
		}
	}

	bool lose = true;
	while (true) {
		bool cont = false;
		int s = 0;
		for (size_t i = 0; i < grs.size(); ++i) {
			s += grs[i] % 2;
			grs[i] /= 2;
			if (grs[i] > 0) {
				cont = true;
			}
		}
		if (s % (k + 1) != 0) {
			lose = false;
		}
		if (!lose || !cont) {
			break;
		}
	}
	
	if (firstFree) {
		if (secondFree) {
			fout << "Draw\n";
		} else {
			fout << "First\n";
		}
	} else {
		if (secondFree) {
			fout << "Second\n";
		} else {
			if (lose) {
				fout << "Second\n";
			} else {
				fout << "First\n";
			}
		}
	}

	return 0;
}