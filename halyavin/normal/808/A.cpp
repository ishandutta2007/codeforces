#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
	int n;
	in >> n;
	int res = 1;
	n++;
	int mult = 1;
	while (n >= 10) {
		if (n % 10 != 0) {
			res += mult * (10 - (n % 10));
		}
		n = (n + 9) / 10;
		mult *= 10;
	}
	out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}