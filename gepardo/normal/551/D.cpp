#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

/*#ifndef DEBUG
	#define cin cin___42cin___
	#define cout cout___42cout___
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif*/

struct Mat {
	uint64_t _[2][2] = {1, 0, 0, 1};
};

inline Mat mul(Mat a, Mat b, uint64_t m) {
	Mat c;
	for (uint64_t i = 0; i < 2; i++) {
		for (uint64_t j = 0; j < 2; j++) {
			c._[i][j] =  0;
			for (uint64_t k = 0; k < 2; k++) {
				c._[i][j] += b._[i][k] * a._[k][j];
				c._[i][j] %= m;
			}
		}
	}
	return c;
}

inline Mat pow(Mat a, uint64_t n, uint64_t m) {
	Mat res;
	while (n) {
		if (n & 1) {
			res = mul(res, a, m);
		}
		a = mul(a, a, m);
		n >>= 1;
	}
	return res;
}

inline uint64_t pow(uint64_t a, uint64_t n, uint64_t m) {
	uint64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res;
}

signed main() {
	uint64_t n, k, l, m; cin >> n >> k >> l >> m;
	Mat fib;
	fib._[0][0] = 0;
	fib._[0][1] = fib._[1][0] = fib._[1][1] = 1;
	uint64_t k0 = pow(fib, n+1, m)._[1][1];
	uint64_t k1 = (pow(2, n, m) + m - k0) % m;
	uint64_t ans = 1;
	for (uint64_t i = 0; i < l; i++) {
		ans *= (k & 1) ? k1 : k0;
		ans %= m;
		k >>= 1;
	}
	if (k) {
		ans = 0;
	}
	cout << ans % m << endl;
	return 0;
}