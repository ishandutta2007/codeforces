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
	fout << fixed;

	string s, t;
	fin >> s >> t;

	int N = s.length();

	vector< vector<int> > nextLet(N, vector<int>(26));
	for (int j = 0; j < 26; ++j) {
		nextLet[N - 1][j] = -1;
		for (int i = N - 2; i >= 0; --i) {
			if (s[i + 1] == (char)('a' + j)) {
				nextLet[i][j] = i + 1;
			} else {
				nextLet[i][j] = nextLet[i + 1][j];
			}
		}
		if (s[0] == (char)('a' + j)) {
			nextLet[N - 1][j] = 0;
		} else {
			nextLet[N - 1][j] = nextLet[0][j];
		}
		for (int i = N - 2; i >= 0 && nextLet[i][j] == -1; --i) {
			nextLet[i][j] = nextLet[i + 1][j];
		}
	}

	int M = t.length();

	int ans = 1;
	int cur = nextLet[N - 1][t[0] - 'a'];
	if (cur < 0) {
		fout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i < M; ++i) {
		if (nextLet[cur][t[i] - 'a'] < 0) {
			ans = -1;
			break;
		} else {
			if (nextLet[cur][t[i] - 'a'] <= cur) {
				++ans;
			}
			cur = nextLet[cur][t[i] - 'a'];
		}
	}

	fout << ans << '\n';

	return 0;
}