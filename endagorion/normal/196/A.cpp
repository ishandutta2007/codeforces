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

	string s;
	fin >> s;

	int N = s.length();
	vector<int> maxI(N);
	maxI[N - 1] = N - 1;
	for (int i = N - 2; i >= 0; --i) {
		if (s[i] >= s[maxI[i + 1]]) {
			maxI[i] = i;
		} else {
			maxI[i] = maxI[i + 1];
		}
	}

	int cur = 0;
	while (cur < N) {
		fout << s[maxI[cur]];
		cur = maxI[cur] + 1;
	}
	fout << '\n';

	return 0;
}