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


long long n, mm, dx, dy;
long long x[1000502], y[1000502];
long long m[1000502];
long long py[1000502];


int main() {
	cin >> n >> mm >> dx >> dy;
	for (int i = 0; i < mm; i++) {
		cin >> x[i] >> y[i];
	}
	long long dx1 = 0, dy1 = 0;
	for (int i = 0; i < n; i++) {
		py[dx1] = dy1;
		dx1 += dx;
		dx1 %= n;
		dy1 += dy;
		dy1 %= n;
	}
	for (int i = 0; i < mm; i++) {
		long long k = (y[i] - py[x[i]] + n) % n;
		//cout << k << endl;
		m[k]++;
	}
	long long ans = -1;
	long long t = 0;
	for (int i = 0; i < n; i++) {
		if (ans < m[i]) {
			ans = m[i];
			t = i;
		}
	}
	cout << 0 << ' ' << t << endl;
    return 0;
}