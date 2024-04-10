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
#include <assert.h>


using namespace std;


int n;
long long a[500000];
long long d[500000];
long long c = 0;
bool b[500000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c += a[i];
	}
	if (c % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	c /= 3;
	long long t = 0;
	for (int i = 0; i < n; i++) {
		t += a[i];
		if (t == c) {
			b[i] = true;
		}
		d[i] = (i > 0 ? d[i - 1]: 0) + b[i];
	}
	long long k = 0;
	long long t1 = 0;
	for (int i = n - 1; i >= 2; i--) {
		t1 += a[i];
		if (t1 == c) {
			k += d[i - 2];
		}
	}
	cout << k << endl;
    return 0;
}