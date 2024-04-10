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

	string s, t;
	fin >> s >> t;

	string q = "";
	for (size_t i = 0; i < t.length(); ++i) {
		q += '1';
	}

	s = q + s + q;

	int ans = 1e9;
	for (size_t i = 0; i + t.length() <= s.length(); ++i) {
		int res = 0;
		for (size_t j = 0; j < t.length(); ++j) {
			if (s[i + j] != t[j]) {
				++res;
			}
		}
		ans = min(ans, res);
	}
	fout << ans << '\n';

	return 0;
}