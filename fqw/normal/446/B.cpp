#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

typedef long long int64;

std::vector<int64> comp(const std::vector<int64> &a, int k, int64 p) {
	std::vector<int64> c(k + 1);
	std::multiset<int64> set;
	int64 sum = 0;
	for (size_t i = 0; i < a.size(); i++)
		set.insert(a[i]);
	for (int i = 0; i <= k; i++) {
		c[i] = sum;
		int64 cur = *(--set.end());
		set.erase(set.find(cur));
		set.insert(cur - p);
		sum += cur;
	}
	return c;
}

int main() {
	int n, m, k; 
	int64 p;
	static int a[1000][1000];
	std::cin >> n >> m >> k >> p;
	std::vector<int64> x(n, 0);
	std::vector<int64> y(m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
			x[i] += a[i][j];
			y[j] += a[i][j];
		}
	}
	std::vector<int64> rx = comp(x, k, p * m);
	std::vector<int64> ry = comp(y, k, p * n);
	int64 ans = LLONG_MIN;
	for (int i = 0; i <= k; i++) {
		int64 vx = rx[i];
		int64 vy = ry[k - i];
		int64 vz = int64(i) * int64(k - i) * p;
		ans = std::max(ans, vx + vy - vz);
	}
	std::cout << ans << std::endl;
	return 0;
}