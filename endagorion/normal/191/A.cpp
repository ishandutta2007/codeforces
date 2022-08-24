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
	vector< vector<int> > w(26, vector<int>(26, -1e9));
	for (int i = 0; i < 26; ++i) {
		w[i][i] = 0;
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		string s;
		fin >> s;
		int e = s[s.size() - 1] - 'a', b = s[0] - 'a';
		int l = s.length();
		for (int st = 0; st < 26; ++st) {
			w[st][e] = max(w[st][e], w[st][b] + l);
		}
	}
	ans = 0;
	for (int i = 0; i < 26; ++i) {
		ans = max(ans, w[i][i]);
	}
	fout << ans << '\n';

	return 0;
}