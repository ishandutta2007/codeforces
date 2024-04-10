#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
	int n, m;
	in >> n >> m;
	std::vector<std::string> flag(n);
	for (int i = 0; i < n; i++) {
		in >> flag[i];
	}
	if (n % 3 == 0) {
		bool good = true;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (flag[i][j] != flag[i][j - 1]) {
					good = false;
				}
			}
		}
		for (int k = 0; k < 3; k++) {
			for (int i = 1; i < n / 3; i++) {
				if (flag[i + k * (n / 3)][0] != flag[i - 1 + k * (n / 3)][0]) {
					good = false;
				}
			}
			for (int l = 0; l < k; l++) {
				if (flag[l * (n / 3)][0] == flag[k * (n / 3)][0]) {
					good = false;
				}
			}
		}
		if (good) {
			out << "YES\n";
			return;
		}
	}
	if (m % 3 == 0) {
		bool good = true;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (flag[i][j] != flag[i - 1][j]) {
					good = false;
				}
			}
		}
		for (int k = 0; k < 3; k++) {
			for (int i = 1; i < m / 3; i++) {
				if (flag[0][i + k * (m / 3)] != flag[0][i - 1 + k * (m / 3)]) {
					good = false;
				}
			}
			for (int l = 0; l < k; l++) {
				if (flag[0][l * (m / 3)] == flag[0][k * (m / 3)]) {
					good = false;
				}
			}
		}
		if (good) {
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