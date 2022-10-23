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
		vector<int> vis(N), a(N), one;
		for (int i = 0; i != N; ++i) {
			cin >> a[i];
			if (a[i] != 0) one.push_back(i);
		}
		if (one.size() % 2) {
			cout << "-1\n";
			continue;
		}
		vector<pair<int, int>> vc;
		auto pb = [&](int l, int r) {
			vc.emplace_back(l + 1, r + 1);
			for (int i = l; i <= r; ++i) vis[i] = 1;
		};
		for (int i = 0; i != one.size(); i += 2) {
			int p = one[i], q = one[i + 1];
			// if (q - p == 1) {
			// 	if (a[p] - a[q] == 0) pb(p, q);
			// } else {
				if (a[p] - a[q] == 0) pb(q - 1, q);
			// }
		}
		for (int i = 0; i != N; ++i) if (!vis[i]) pb(i, i);
		sort(vc.begin(), vc.end());
		cout << vc.size() << '\n';
		for (const auto & pr : vc) cout << pr.first << ' ' << pr.second << '\n';
	}

	return 0;
}