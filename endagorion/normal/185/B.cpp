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

	int S, a, b, c;
	fin >> S >> a >> b >> c;

	if (a == 0 && b == 0 && c == 0) {
		fout << "0 0 0\n";
		return 0;
	}
	int q = 0;
	while (c == 0) {
		++q;
		int d = c;
		c = b;
		b = a;
		a = d;
	}

	double A = a + c;
	double B = a;
	double C = a * S;
	double D = b;
	double E = b + c;
	double F = b * S;
	double R = B * D - A * E;
	double x = (B * F - C * E) / R;
	double y = (C * D - A * F) / R;
	double z = S - x - y;
	for (size_t i = 0; i < q; ++i) {
		double w = x;
		x = y;
		y = z;
		z = w;
	}

	fout << x << ' ' << y << ' ' << z << '\n';

	return 0;
}