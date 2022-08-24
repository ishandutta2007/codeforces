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
	int N, K;
	fin >> N >> K;
	--K;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		fin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] >= a[K] && a[i] > 0) {
			++ans;
		}
	}

	fout << ans << '\n';

	return 0;
}