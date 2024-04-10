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


using namespace std;


int main () {
	long long n;
	cin >> n;
	if (n == 0) {
		cout << 0 <<  ' ' << 0 << endl;
		return 0;
	}
	long long l = 0;
	long long r = n / 3LL;
	while (l != r) {
		long long m = (l + r + 1) / 2;
		if (m > (long long)sqrt(n / 3LL) + 3LL) {
			r = m - 1;
			continue;
		}
		if (m * (m - 1) * 3LL < n) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	//cout << l << endl;
	n -= l * (l - 1) * 3LL;
	if (l == 0) {
		l = 1;
	}
	l++;
	long long x = 2LL * (l - 1);
	long long y = 0;
	int t = 0;
	if (n >= (l - 1)) {
		n -= (l - 1);
		x -= (l - 1);
		y += 2LL * (l - 1);
		t = 1;
	}
	if (n >= l - 1) {
		n -= (l - 1);
		x -= 2LL * (l - 1);
		t = 2;
	}
	if (n >= l - 1) {
		n -= (l - 1);
		x -= (l - 1);
		y -= 2LL * (l - 1);
		t = 3;
	}
	//cout << n<< endl;
	if (n >= l - 1) {
		x += 1LL * (l - 1);
		y -= 2LL * (l - 1);
		n -= (l - 1);
		t = 4;
	}
	if (n >= l - 1) {
		x += 2LL * (l - 1);
		n -= (l - 1);
		t = 5;
	}
	if (t == 0) {
		x -= n;
		y += 2LL * n;
	}
	if (t == 1) {
		x -= 2LL * n;
	}
	if (t == 2) {
		x -= n;
		y -= 2LL * n;
	}
	if (t == 3) {
		x += n;
		y -= 2LL * n;
	}
	if (t == 4) {
		x += 2LL * n;
	}
	if (t == 5) {
		x += n;
		y += 2LL * n;
	}
	cout << x << ' ' << y << endl;
 	return 0;
}