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

	int x, y;
	fin >> x >> y;
	int d = 0;
	while (d * d < x * x + y * y) {
		++d;
	}
	bool black = (d * d == x * x + y * y) || ((d % 2 == 0) != (x * y >= 0));

	if (black) {
		fout << "black\n";
	} else {
		fout << "white\n";
	}

	return 0;
}