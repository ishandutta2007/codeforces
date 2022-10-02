#include <iostream>
#include <sstream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;


#define P 1000000001LL


int n;
long long x[100000], y[100000];
long long mx, my, m1x, m1y;


int main() {
	cin >> n;
	mx = -P;
	my = -P;
	m1x = P;
	m1y = P;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		mx = max(mx, x[i]);
		m1x = min(m1x, x[i]);
		my = max(my, y[i]);
		m1y = min(m1y, y[i]);
	}
	long long ans = max(max((my - m1y), 1LL), max((mx - m1x), 1LL)) * max(max((my - m1y), 1LL), max((mx - m1x), 1LL));
	cout << ans << endl;
    return 0;
}