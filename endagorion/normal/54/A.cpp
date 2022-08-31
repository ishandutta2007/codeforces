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

	int N, K, C;
	fin >> N >> K >> C;
	int cur = 0;
	int ans = -1;
	for (int i = 0; i <= C; ++i) {
		int next;
		if (i < C) {
			fin >> next;
		} else {
			next = N + 1;
		}
		while (cur + K < next) {
			++ans;
			cur += K;
		}
		cur = next;
		++ans;
	}

	fout << ans << '\n';

	return 0;
}