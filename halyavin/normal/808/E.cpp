#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>

void run(std::istream &in, std::ostream &out) {
	int n, m;
	in >> n >> m;
	std::vector<int> q3;
	std::vector<int> q2;
	std::vector<int> q1;

	for (int i = 0; i < n; i++) {
		int w, c;
		in >> w >> c;
		if (w == 1) {
			q1.push_back(c);
		}
		else if (w == 2) {
			q2.push_back(c);
		}
		else {
			q3.push_back(c);
		}
	}
	while (q1.size() <= m) q1.push_back(0);
	std::sort(q1.begin(), q1.end(), std::greater<int>());
	std::sort(q2.begin(), q2.end(), std::greater<int>());
	std::sort(q3.begin(), q3.end(), std::greater<int>());
	std::vector<int64_t> dyn(m + 1, 0);
	int cura = 0;
	int curb = 0;
	int64_t curCost = 0;
	for (int i = 1; i <= m; i++) {
		curCost += q1[cura];
		cura++;
		while (curb < q2.size() && cura >= 2) {
			int64_t diff = q2[curb];
			diff -= q1[cura - 1] + q1[cura - 2];
			if (diff > 0) {
				curCost += diff;
				curb++;
				cura -= 2;
			}
			else {
				break;
			}
		}
		dyn[i] = curCost;
	}
	int64_t opt = dyn[m];
	int64_t cur = 0;
	for (size_t i = 0; i < q3.size() && 3 * (i + 1) <= m; i++) {
		cur += q3[i];
		int64_t curValue = cur + dyn[m - 3 * (i + 1)];
		opt = std::max(opt, curValue);
	}
	out << opt << std::endl;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	run(std::cin, std::cout);
	return 0;
}