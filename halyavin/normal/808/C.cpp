#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
	int n, w;
	in >> n >> w;
	std::vector<std::pair<int, int>> friends;
	for (int i = 0; i < n; i++) {
		int as;
		in >> as;
		friends.emplace_back(as, i);
	}
	std::sort(friends.begin(), friends.end());
	std::vector<int> bs(n);
	for (int i = 0; i < n; i++) {
		bs[i] = (friends[i].first + 1) / 2;
	}
	w -= std::accumulate(bs.begin(), bs.end(), 0);
	if (w < 0) {
		out << -1 << std::endl;
		return;
	}
	for (int i = n - 1; i >= 0; i--) {
		int v = std::min(w, friends[i].first - bs[i]);
		bs[i] += v;
		w -= v;
	}
	std::vector<int> result(n);
	for (int i = 0; i < n; i++) {
		result[friends[i].second] = bs[i];
	}
	for (int i = 0; i < n; i++) {
		out << result[i] << " ";
	}
	out << std::endl;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	run(std::cin, std::cout);
	return 0;
}