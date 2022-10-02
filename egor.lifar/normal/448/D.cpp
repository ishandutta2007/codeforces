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


long long n, m, k;


bool get(long long s) {
	long long t = 0;
	for (int i = 0; i < n; i++) {
		t += min((s - 1) / (i + 1), m);
	}
	return t < k;
}


int main() {
	cin >> n >> m >> k;
	long long l = 1;
	long long r = n * m;
	while (l != r) {
		long long s = (l + r + 1) / 2;
		if (get(s)) {
			l = s;
		} else {
			r = s - 1;
		}
	}
	cout << l << endl;
	return 0;
}