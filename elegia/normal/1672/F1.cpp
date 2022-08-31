/*
   
   
   
   
 */
#include <cmath>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <complex>
#include <limits>
#include <functional>
#include <random>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using ll = long long;
using ull = unsigned long long;

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> a(N);
		vector<vector<int>> pos(N);
		for (int i = 0; i != N; ++i) {
			cin >> a[i]; --a[i];
			pos[a[i]].push_back(i);
		}
		vector<int> b(N);
		vector<pair<int, int>> sz(N);
		for (int i = 0; i != N; ++i) {
			sz[i] = make_pair(pos[i].size(), i);
		}
		sort(sz.begin(), sz.end(), greater<pair<int, int>>());
		int rest = N, len = N;
		while (rest) {
			vector<int> cyc;
			for (int rep = 0; rep < len; ++rep) {
				int i = sz[rep].second;
				if (pos[i].empty()) {
					len = rep; break;
				}
				cyc.push_back(pos[i].back()); pos[i].pop_back();
			}
			rest -= len;
			for (int i = 0; i < len; ++i) {
				b[cyc[i]] = cyc[(i + 1) % len];
			}
		}
		for (int i = 0; i != N; ++i) cout << a[b[i]] + 1 << " ";
		cout << '\n';
	}

	return 0;
}