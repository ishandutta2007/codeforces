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
		int n, m, k; cin >> n >> m >> k;
		vector<int> a(k);
		for (int& x : a) cin >> x;
		auto solve = [&]() {
			long long tot = 0;
			bool par = false;
			for (int x : a) {
				if (x / n >= 2) {
					tot += x / n;
					if (x / n > 2) par = true;
				}
			}
			if (par) return tot >= m;
			return tot >= m && (tot - m) % 2 == 0;
		};
		bool ans = solve();
		swap(n, m); ans |= solve();
		cout << (ans ? "Yes" : "No") << '\n';
	}

	return 0;
}