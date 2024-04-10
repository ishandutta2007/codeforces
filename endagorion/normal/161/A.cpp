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

	int N, M, x, y;
	fin >> N >> M >> x >> y;
	vector<int> a(N), b(M);
	for (int i = 0; i < N; ++i) {
		fin >> a[i];
	}
	for (int i = 0; i < M; ++i) {
		fin >> b[i];
	}
	int c1 = 0, c2 = 0;
	vector< pair<int, int> > pairs;
	while (c1 < N && c2 < M) {
		if (b[c2] > a[c1] + y) {
			++c1;
			continue;
		}
		if (b[c2] < a[c1] - x) {
			++c2;
			continue;
		}
		pairs.push_back(make_pair(c1 + 1, c2 + 1));
		++c1;
		++c2;
	}

	fout << pairs.size() << '\n';
	for (size_t i = 0; i < pairs.size(); ++i) {
		fout << pairs[i].first << ' ' << pairs[i].second << '\n';
	}

	return 0;
}