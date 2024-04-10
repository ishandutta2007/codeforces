#include <iostream>
#include <vector>

using namespace std;

inline void sumXorNaive(int64_t *beg, int64_t *res, int pow) {
	for (int i = 0; i < (1 << pow); i++) {
		for (int j = 0; j < (1 << pow); j++) {
			res[i ^ j] += beg[i] * beg[j];
		}
	}
}

// Karatsuba-style
inline void sumXor(int64_t *beg, int64_t *res, int pow) {
	if (pow == 0) {
		res[0] = beg[0] * beg[0];
		return;
	}
	if (pow < 3) {
		sumXorNaive(beg, res, pow);
		return;
	}
	int mid = 1 << (pow-1);
	sumXor(beg, res, pow-1);
	sumXor(beg + mid, res + mid, pow-1);
	for (int i = 0; i < mid; i++) {
		beg[i] += beg[mid+i];
		res[i] += res[mid+i];
		res[mid+i] = 0;
	}
	sumXor(beg, res + mid, pow-1);
	for (int i = 0; i < mid; i++) {
		beg[i] -= beg[mid+i];
		res[mid+i] -= res[i];
	}
}

inline vector<int64_t> sumXor(vector<int64_t> v, int pow) {
	vector<int64_t> res(1 << pow);
	sumXor(&v[0], &res[0], pow);
	return res;
}

inline vector<int64_t> sumDistAnd(vector<int64_t> v, int pow) {
	vector<int64_t> res(1 << pow);
	for (int i = 0; i < (1 << pow); i++) {
		int q = ((1 << pow) - 1) ^ i;
		for (int j = q; j >= 0; j--, j &= q) {
			res[i + j] += v[i] * v[j];
			if (j == 0) {
				break;
			}
		}
	}
	return res;
}

const int mod = (int)1e9 + 7;

inline vector<int64_t> merge(vector<int64_t> a, vector<int64_t> b, int pow) {
	vector<int64_t> gc(1 << pow);
	for (int i = 0; i < (1 << pow); i++) {
		int64_t ga = 0, gb = 0;
		int q = ((1 << pow) - 1) ^ i;
		for (int j = q; j >= 0; j--, j &= q) {
			ga += a[j | i]; gb += b[j | i];
			if (j == 0) {
				break;
			}
		}
		ga %= mod; gb %= mod;
		gc[i] = (ga * gb) % mod;
	}
	vector<int64_t> c(1 << pow);
	for (int i = (1 << pow) - 1; i >= 0; i--) {
		c[i] = gc[i];
		int q = ((1 << pow) - 1) ^ i;
		for (int j = q; j > 0; j--, j &= q) {
			c[i] -= c[j | i];
		}
		c[i] = (c[i] % mod + mod) % mod;
	}
	for (int i = 0; i < (1 << pow); i++) {
		c[i] %= mod;
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	const int pow = 17;
	vector<int64_t> c(1 << pow);
	for (int i = 0; i < n; i++) {
		int q; cin >> q;
		c[q]++;
	}
	auto de = sumXor(c, pow);
	auto ab = sumDistAnd(c, pow);
	int a = 0, b = 1;
	for (int i = 0; i < (1 << pow); i++) {
		c[i] = ((c[i] % mod) * a) % mod;
		ab[i] = ((ab[i] % mod) * a) % mod;
		de[i] = ((de[i] % mod) * a) % mod;
		int d = (a + b) % mod;
		a = b; b = d;
	}
	c = merge(ab, c, pow);
	c = merge(c, de, pow);
	int ans = 0;
	for (int i = 0; i < pow; i++) {
		ans += c[1 << i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}