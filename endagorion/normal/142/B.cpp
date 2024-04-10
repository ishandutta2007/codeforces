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
	int n, m;
	fin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	
	if (n == 1) {
		fout << m << '\n';
	} else {
		if (n == 2) {
			fout << 2 * ((m - 1) / 4 + 1) + 2 * ((m - 2) / 4 + 1) << '\n';
		} else {
			fout << (n * m) / 2 + (n * m) % 2 << '\n';
		}
	}

	return 0;
}