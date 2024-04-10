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

	int x;
	fin >> x;
	switch (x) {
	case 1:
		fout << 1 << '\n';
		break;
	case 2:
	case 4:
	case 5:
		fout << 3 << '\n';
		break;
	case 3:
		fout << 5 << '\n';
		break;
	default:
		for (int n = 3; ; ++n) {
			int m = 4 * ((n - 1) * (n - 1) / 2 + (n - 1) % 2) + 4 * ((n - 1) / 2) + 1;
			if (x <= m) {
				fout << 2 * n - 1 << '\n';
				break;
			}
		}
	}

	return 0;
}