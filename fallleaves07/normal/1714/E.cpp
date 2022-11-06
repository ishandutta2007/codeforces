#include<bits/stdc++.h>
using LL = long long;

bool solve() {
	int n, cntx = 0;
	std::cin >> n;
	std::set<int> fixed, add;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		if ((a % 10) % 2 == 1) {
			a += a % 10;
		}
		if (a % 10 == 2 || a % 10 == 4 || a % 10 == 8) {
			a -= a % 10;
		} else if (a % 10 == 6) {
			a -= 16;
		} else {
			fixed.insert(a);
			++cntx;
		}
		add.insert(a);
	}
	if ((int)fixed.size() > 1) {
		return false;
	}
	if (!fixed.empty() && cntx < n) {
		return false;
	}
	int x = *add.rbegin();
	for (auto v : add) {
		if ((x - v) % 20) {
			return false;
		}
	}
	return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		puts(solve() ? "Yes" : "No");
	}
    return 0;
}