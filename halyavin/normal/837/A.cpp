#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
	std::string n;
	getline(in, n);
	std::string test;
	getline(in, test);
	int answer = 0;
	int cur = 0;
	for (size_t i = 0; i < test.length(); i++) {
		if (test[i] >= 'A' && test[i] <= 'Z') {
			cur++;
			answer = std::max(answer, cur);
		}
		else if (test[i] <= 32) {
			cur = 0;
		}
	}
	std::cout << answer << std::endl;

}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	run(std::cin, std::cout);
	return 0;
}