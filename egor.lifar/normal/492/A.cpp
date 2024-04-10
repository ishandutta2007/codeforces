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


int n;


bool get(int x) {
	long long a = 0, b = 0;
	for (int i = 0; i < x; i++) {
		b += (i + 1);
		a += b;
	}
	return a <= n;
}


int main() {
	cin >> n;
	int l = 1;
	int r = 10000;
	while (l != r) {
		int m = (l + r + 1) / 2;
		if (get(m)) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	cout << l << endl;
    return 0;
}