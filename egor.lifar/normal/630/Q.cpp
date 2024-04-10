#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;


#define Pi acos(-1)


int main() {
	double l[3];
	cin >> l[0] >> l[1] >> l[2];
	double sum;
	if (1) {
		double p = (3.0 * l[0]) / 2.0;
		double s = sqrt(p * (p - l[0]) * (p - l[0]) * (p - l[0]));
		double h = (s * 2.0) / l[0];
		double h1 = l[0] / (2.0 * tan(2.0 * Pi / (2.0 * 3.0)));
		h1 = abs(h1);
		double h2 = sqrt(h * h - h1 * h1);
		sum = h2 * s / 3.0;
	}
	if (1) {
		double p = (3.0 * l[1]) / 2.0;
		double s = sqrt(p * (p - l[1]) * (p - l[1]) * (p - l[1]));
		double h = (s * 2.0) / l[1];
		double h1 = l[1] / (2.0 * tan(2.0 * Pi / (2.0 * 4.0)));
		h1 = abs(h1);
		double h2 = sqrt(h * h - h1 * h1);
		double s1 = 0.5 * h1 * 4.0 * l[1];
		sum += h2 * s1 / 3.0;
	}
	if (1) {
		double p = (3.0 * l[2]) / 2.0;
		double s = sqrt(p * (p - l[2]) * (p - l[2]) * (p - l[2]));
		double h = (s * 2.0) / l[2];
		double h1 = l[2] / (2.0 * tan(2.0 * Pi / (2.0 * 5.0)));
		h1 = abs(h1);
		double h2 = sqrt(h * h - h1 * h1);
		double s1 = 0.5 * h1 * 5.0 * l[2];
		sum += h2 * s1 / 3.0;
	}
	printf("%.10lf\n", sum);
	return 0;
}