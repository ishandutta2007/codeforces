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


long long M = 1000000007;
int f[2000002];


int pow1(int a, int x) {
	if (x == 0) {
		return 1;
	} else {
		if (x % 2 == 1) {
			return (1LL * a * pow1(a, x - 1)) % M;
		} else {
			int g = pow1(a, x >> 1);
			return (1LL * g * g) % M;
		}
	}
}


int main() {
	int n;
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= 2 * n; i++) {
		f[i] = (1LL * f[i - 1] * i) % M;
	}
	int ans = (pow1(2, n + 1) - 1 + M) % M;
	int g = pow1(2, n);
	int t1 = 0;
	int sh = pow1(f[n], M - 2LL);
	for (int i = 0; i < n; i++) {
		int t = (1LL * f[n + i] * sh) % M;
		t = (1LL * t * pow1(f[i], M - 2LL)) % M;
		t = (2 * t) % M;
		int ff = (t - t1 >= 0 ? t - t1: t - t1 + M);
		int kk = (g - ff >= 0 ? g - ff: g - ff + M);
		int l = (2 * kk) % M;
		ans += l;
		ans %= M;
		ans += (1LL * ff * (n - i)) % M;
		ans %= M;
		g = l;
 		t1 = t;
	}
	cout << ans << endl;
	return 0;
}