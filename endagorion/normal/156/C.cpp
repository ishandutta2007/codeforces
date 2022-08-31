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

const long long MOD = 1000000007;

int main() {
	fout << fixed;

	int T;
	fin >> T;

	vector< vector<long long> > ways(101, vector<long long>(2601, 0));
	ways[0][0] = 1;

	for (int l = 1; l <= 100; ++l) {
		for (int s = 0; s <= 26 * l; ++s) {
			for (int q = 0; q <= s && q < 26; ++q) {
				ways[l][s] = (ways[l][s] + ways[l - 1][s - q]) % MOD;
			}
		}
	}

	for (int t = 0; t < T; ++t) {
		string s;
		fin >> s;
		int L = s.length();
		int S = 0;
		for (int i = 0; i < L; ++i) {
			S += s[i] - 'a';
		}
		fout << (ways[L][S] + MOD - 1) % MOD << '\n';
	}

	return 0;
}