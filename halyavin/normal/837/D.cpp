#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
	int n, k;
	in >> n >> k;
	std::vector<std::pair<int, int>> as(n);
	for (int i = 0; i < n; i++) {
		int64_t x;
		in >> x;
		while (x % 2 == 0) {
			as[i].first++;
			x /= 2;
		}
		while (x % 5 == 0) {
			as[i].second++;
			x /= 5;
		}
	}
	int max5 = 0;
	for (int i = 0; i < n; i++) {
		max5 += as[i].second;
	}
	std::vector<std::vector<int>> dyn(k + 1, std::vector<int>(max5 + 1, -1));
	dyn[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int shift5 = as[i].second;
		int shift2 = as[i].first;
		for (int nums = k - 1; nums >= 0; nums--) {
			for (int j = 0; j + shift5 <= max5; j++) {
				if (dyn[nums][j] == -1) continue;
				dyn[nums + 1][j + shift5] = std::max(dyn[nums + 1][j + shift5], dyn[nums][j] + shift2);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= max5; i++) {
		if (dyn[k][i] >= 0) {
			answer = std::max(answer, std::min(i, dyn[k][i]));
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