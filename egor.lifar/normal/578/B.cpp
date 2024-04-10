#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cstring>


using namespace std;


int n, k, x;
int a[200011];
long long b[200011];
long long c[200011];


int main() {
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int y = 1;
	if (k == 0) {
		y = 0;
	}
	for (int i = 0; i < k; i++) {
		y *= x;
	}
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		b[i] = (b[i - 1] | (1LL * a[i]));
	}
	c[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		c[i] = (c[i + 1] | (1LL * a[i]));
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, 1LL * ((i == 0 ? 0: b[i - 1]) | (1LL * a[i] * y) | (i == n - 1 ? 0: c[i + 1])));
	}
	cout << ans << endl;
	return 0;
}