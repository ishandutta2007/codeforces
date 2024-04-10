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



int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double d = b * b - 4.0 * a * c;
	//cout << d << endl;
	double s = (-b + sqrt(d)) / (2.0 * a);
	double s1 = (-b - sqrt(d)) / (2.0 * a);
	printf("%.10lf %.10lf\n", max(s, s1), min(s, s1));
	return 0;
}
//1 1 3
//1 3 1
//3 1 1
//1 2 2