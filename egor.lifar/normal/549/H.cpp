#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


#define eps 0.00000000000000000001


long double a, b, c, d;


bool get(double m) {
	long double h = min((a + m) * (d + m), min((a - m) * (d - m), min((a + m) * (d - m), (a - m) * (d + m))));
	long double h1 = max((a + m) * (d + m), max((a - m) * (d - m), max((a + m) * (d - m), (a - m) * (d + m))));
	long double g = min((b + m) * (c + m), min((b - m) * (c - m), min((b + m) * (c - m), (b - m) * (c + m))));
	long double g1 = max((b + m) * (c + m), max((b - m) * (c - m), max((b + m) * (c - m), (b - m) * (c + m))));
	if (!(g1 + eps < h || g > eps + h1)) {
		return true;
	}
	return false;
}


int main() {
	cin >> a >> b >> c >> d;
	long double l = 0.0;
	long double r = 20000000000000000000.0;
	for (int i = 0; i < 1000000; i++) {
		long double m = (l + r) / 2.0;
		if (get(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	double g = (l + r) / 2.0;
	printf("%.10lf\n", g);
 	return 0;
}