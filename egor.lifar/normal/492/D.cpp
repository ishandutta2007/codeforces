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
long long d[100000];
long long x, y; 
long long t;


long long nod(long long a, long long b) {
	return (a == 0LL ? b: nod(b % a, a));
}


bool get(long long m, long long x1) {
	return m / x + m / y >= x1;
}


int main() {
	cin >> n >> x >> y;
	t = x * y / nod(x, y);
	x = t / x;
	y = t / y;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
		long long l = 1;
		long long r = ((d[i] + x - 1) / x) * t;
		while (l != r) {
			long long m = (l + r) / 2;
			if (get(m, d[i])) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		//cout << l << endl;
		if (l % x == 0 && l % y == 0) {
			printf("Both\n");
			continue;
		}
		if (l % x == 0) {
			printf("Vanya\n");
			continue;
		}
		printf("Vova\n");
	}
    return 0;
}