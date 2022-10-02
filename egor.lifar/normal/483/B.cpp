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


long long a, b, x, y;


long long nod(long long a, long long b) {
    if (a == 0LL) {
        return b;
    }
    return nod(b % a, a);
}


bool get(long long t) {
	long long c = t - t / x;
	long long d = t - t / y;
	if (c < a || d < a) {
		return false;
	}
	long long k = c - a;
	long long e = t - t / x - t / y + t / ((x * y) / nod(x, y));
	if (d - max(0LL, e - k) >= b) {
		return true;
	}
	return false;
}



int main() {
	cin >> a >> b >> x >> y;
	long long l = 1;
	long long r = 1000000000000000LL;
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