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

	long long a, b, m, r;
	fin >> a >> b >> m >> r;
	vector<long long> last(m, -1);
	long long cur = 0;
	while (last[r] < 0) {
		last[r] = cur++;
		r = (a * r + b) % m;
	}

	fout << cur - last[r] << '\n';

	return 0;
}