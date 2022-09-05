#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

int findBig(std::vector<int>& as, int64_t k) {
	std::vector<int64_t> coeff(as.size(), 1);
	int answer = 1;
	while (true) {
		int64_t sum = 0;
		for (size_t i = 0; i < as.size(); i++) {
			if (k / coeff[i] < as[i]) {
				return answer;
			}
			sum += as[i] * coeff[i];
			if (sum >= k) {
				return answer;
			}
		}
		for (size_t i = as.size() - 1; i-- > 0;) {
			coeff[i] += coeff[i + 1];
		}
		answer++;
	}
}

int64_t findSmall(std::vector<int>& as, int64_t k) {
	int64_t left = 0;
	int64_t right = k;
	std::vector<int64_t> coeffs(as.size());
	while (right - left > 1) {
		int64_t middle = (right + left) / 2;
		coeffs[as.size() - 1] = 1;
		bool ok = false;
		for (size_t i = 1; i < as.size(); i++) {
			int64_t prev = coeffs[as.size() - i];
			if (k * i / (i + middle - 1) < prev) {
				ok = true;
				break;
			}
			coeffs[as.size() - i - 1] = (prev * (i + middle - 1)) / i;
		}
		if (ok) {
			right = middle;
			continue;
		}
		int64_t sum = 0;
		for (size_t i = 0; i < as.size(); i++) {
			if (k / coeffs[i] < as[i]) {
				ok = true;
				break;
			}
			sum += as[i] * coeffs[i];
			if (sum >= k) {
				ok = true;
				break;
			}
		}
		if (ok) {
			right = middle;
		}
		else {
			left = middle;
		}
	}
	return right;
}

void run(std::istream &in, std::ostream &out) {
	int n;
	int64_t k;
	in >> n >> k;
	std::vector<int> as(n);
	int minIndex = -1;
	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		in >> as[i];
		maxValue = std::max(maxValue, as[i]);
		if (as[i] > 0 && minIndex == -1) {
			minIndex = i;
		}
	}
	if (maxValue >= k) {
		out << "0\n";
		return;
	}
	for (int i = 0; i + minIndex < n; i++) {
		as[i] = as[i + minIndex];
	}
	as.resize(n - minIndex);
	if (as.size() < 8u) {
		out << findSmall(as, k) << std::endl;
	}
	else {
		out << findBig(as, k) << std::endl;
	}
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	run(std::cin, std::cout);
	return 0;
}