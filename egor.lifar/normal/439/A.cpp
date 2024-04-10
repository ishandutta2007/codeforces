#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n, d;
long long s = 0;


int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		s += t;
	}
	s += 10 * (n - 1);
	int k = 2 * (n - 1);
	if (s > d) {
		cout << -1 << endl;
	} else {
		k += (d - s) / 5;
		cout << k << endl;
	}
    return 0;
}