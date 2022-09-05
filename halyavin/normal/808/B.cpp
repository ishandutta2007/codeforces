#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
	int k, n;
	in >> n >> k;
	std::vector<int64_t> nums(n);
	for (int i = 0; i < n; i++) {
		in >> nums[i];
	}
	int64_t cur = std::accumulate(nums.begin(), nums.begin() + k, int64_t(0));
	int64_t sum = cur;
	for (int i = 1; i + k - 1 < n; i++) {
		cur += nums[i + k - 1];
		cur -= nums[i - 1];
		sum += cur;
	}
	out.precision(15);
	out << double(sum) / (n - k + 1) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}