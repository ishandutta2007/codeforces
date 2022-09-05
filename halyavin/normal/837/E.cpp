#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

template<class T>
T gcd(T x, T y) {
	while (y != T()) {
		T t = y;
		y = x % y;
		x = t;
	}
	return x;
}

std::vector<int64_t> allPrimes(int64_t x) {
	std::vector<int64_t> res;
	for (int64_t i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			res.push_back(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		res.push_back(x);
	}
	return res;
}

void run(std::istream &in, std::ostream &out) {
	int64_t a, b;
	in >> a >> b;
	int64_t d = gcd(a, b);
	a /= d;
	b /= d;
	int64_t answer = 0;
	while (b > 0) {
		if (a == 1) {
			answer += b;
			break;
		}
		std::vector<int64_t> ps = allPrimes(a);
		int64_t minDiff = b;
		for (int64_t p : ps) {
			minDiff = std::min(minDiff, b % p);
		}
		answer += minDiff;
		b -= minDiff;
		if (b > 0) {
			d = gcd(a, b);
			a /= d;
			b /= d;
		}
	}
	out << answer << std::endl;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	run(std::cin, std::cout);
	return 0;
}