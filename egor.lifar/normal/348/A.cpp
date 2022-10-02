#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
long long a[100000];
long long s;
long long f;
long long k;


bool get(long long m) {
	return s + (m - f) * n >= m;
}


int main() {
	cin >> n;
	long long l = 0;
	long long r = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		l = max(l, a[i]);
		r += a[i];
		k += a[i];
	}
	for (int i = 0; i < n; i++) {
		s += l - a[i];
	}
	f = l;
	while (l != r) {
		long long m = (l + r) / 2;
		if (get(m)) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << l << endl;
	return 0;
}