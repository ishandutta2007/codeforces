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

const double PI = 3.1415926535897932384626433832795;

int main() {
	int n, R, r;
	cin >> n >> R >> r;
	if (r <= R && (n == 1 || 2 * n * asin(1.0 * r / (R - r)) < 2 * PI + 1e-7)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";	
	}
	return 0;
}