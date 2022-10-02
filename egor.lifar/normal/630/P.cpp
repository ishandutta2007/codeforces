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

double n;
double r;


int main() {
	cin >> n >> r;
	double a = Pi / n, a1 = a / 2.0;
	double a2 = Pi - a - a1;
	double r1 = r * sinl(a) / sinl(a2);
	double s = 0.5 * r * r1 * sinl(a1);
	double s1 = 2.0 * n * s;
	printf("%.15lf\n", s1);
	return 0;
}