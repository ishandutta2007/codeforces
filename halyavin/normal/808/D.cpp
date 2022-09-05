#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <set>

void run(std::istream &in, std::ostream &out) {
	int n;
	in >> n;
	std::vector<int64_t> as(n);
	for (int i = 0; i < n; i++) {
		in >> as[i];
	}
	int64_t sum = std::accumulate(as.begin(), as.end(), int64_t(0));
	if (sum % 2 != 0) {
		out << "NO\n";
		return;
	}
	int64_t target = sum / 2;
	std::set<int64_t> targets;
	targets.insert(target);
	int64_t cur = 0;
	for (int i = 0; i < n; i++) {
		cur += as[i];
		targets.insert(target + as[i]);
		if (targets.count(cur) > 0) {
			out << "YES\n";
			return;
		}
	}
	targets.clear();
	targets.insert(target);
	cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		cur += as[i];
		targets.insert(target + as[i]);
		if (targets.count(cur) > 0) {
			out << "YES\n";
			return;
		}
	}
	out << "NO\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}