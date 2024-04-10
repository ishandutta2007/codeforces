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
	int N;
	fin >> N;
	vector<int> a(5);
	for (int i = 0; i < N; ++i) {
		int x;
		fin >> x;
		++a[x];
	}

	int ans = 0;
	while (a[4] >= 1) {
		--a[4];
		++ans;
	}
	while (a[2] >= 2) {
		a[2] -= 2;
		++ans;
	}
	while (a[3] >= 1) {
		--a[3];
		a[1] = max(a[1] - 1, 0);
		++ans;
	}
	while (a[2] >= 1) {
		--a[2];
		a[1] = max(a[1] - 2, 0);
		++ans;
	}
	while (a[1] >= 1) {
		a[1] = max(a[1] - 4, 0);
		++ans;
	}

	fout << ans << '\n';

	return 0;
}