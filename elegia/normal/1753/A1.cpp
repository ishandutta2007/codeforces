#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N % 2) {
			cout << "-1\n";
			while (N--) {
				int x; cin >> x;
			}
		} else {
			vector<pair<int, int>> v;
			for (int i = 1; i <= N; i += 2) {
				int a, b; cin >> a >> b;
				if (a + b == 0) {
					v.emplace_back(i, i);
					v.emplace_back(i + 1, i + 1);
				} else v.emplace_back(i, i + 1);
			}
			cout << v.size() << '\n';
			for (const auto& pr : v) cout << pr.first << ' ' << pr.second << '\n';
		}
	}

	return 0;
}