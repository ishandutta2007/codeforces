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

int black(int n, int m) {
	if (n <= 0 || m <= 0) {
		return 0;
	}
	return n * m / 2 + n * m % 2;
}

int main() {
	fout.precision(10);
	fout << fixed;

	int n, m, x;
	fin >> n >> m >> x;
	
	fout << black(n - 2 * x + 2, m - 2 * x + 2) - black(n - 2 * x, m - 2 * x) << '\n';

	return 0;
}