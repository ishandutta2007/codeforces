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

const long long P = 1000000007;

int main() {
	fout.precision(10);
	fout << fixed;

	string s, t;
	fin >> s >> t;

	vector< vector<int> > ways(2, vector<int>(t.length() + 1, 0));
	int ans = 0;

	for (size_t i = 0; i < s.length(); ++i) {
		ways[1 - i % 2].assign(t.length() + 1, 0);
		for (size_t j = 0; j < t.length(); ++j) {
			ways[1 - i % 2][j + 1] = ways[1 - i % 2][j];
			if (s[i] == t[j]) {
				ways[1 - i % 2][j + 1] += ways[i % 2][j] + 1;
				ways[1 - i % 2][j + 1] %= P;
			}
		}
		ans = (ans + ways[1 - i % 2][t.length()]) % P;
	}

	fout << ans << '\n';
	return 0;
}