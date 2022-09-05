#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

int getPrim(std::pair<int, int> r1, std::pair<int, int> r2, std::pair<int, int> area) {
	if (r1.first > area.first) return 0;
	if (r1.second > area.second) return 0;
	if (r2.first > area.first) return 0;
	if (r2.second > area.second) return 0;
	if (r1.first + r2.first <= area.first || r1.second + r2.second <= area.second) {
		return r1.first * r1.second + r2.first * r2.second;
	}
	return 0;
}

int get(std::pair<int, int> r1, std::pair<int, int> r2, std::pair<int, int> area) {
	int res = 0;
	res = std::max(res, getPrim(r1, r2, area));
	std::swap(r2.first, r2.second);
	res = std::max(res, getPrim(r1, r2, area));
	std::swap(r1.first, r1.second);
	res = std::max(res, getPrim(r1, r2, area));
	std::swap(r2.first, r2.second);
	res = std::max(res, getPrim(r1, r2, area));
	return res;
}

void run(std::istream &in, std::ostream &out) {
	int n;
	std::pair<int, int> area;
	in >> n >> area.first >> area.second;
	std::vector<std::pair<int, int>> rectangles(n);
	for (int i = 0; i < n; i++) {
		in >> rectangles[i].first >> rectangles[i].second;
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			answer = std::max(answer, get(rectangles[i], rectangles[j], area));
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