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
		vector<int> a(N), b(N), cnt(N);
		for (int i = 0; i != N; ++i) { cin >> a[i]; --a[i]; ++cnt[a[i]]; }
		for (int i = 0; i != N; ++i) { cin >> b[i]; --b[i]; }
		int C = max_element(cnt.begin(), cnt.end()) - cnt.begin();
		vector<int> vis(N);
		vector<set<int>> rest(N);
		for (int i = 0; i != N; ++i) if (a[i] == C || b[i] == C) vis[i] = 2;
		else rest[a[i]].insert(i);
		bool ans = true;
		function<void(int)> dfs = [&](int u) {
			vis[u] = 1;
			while (!rest[b[u]].empty()) {
				int v = *rest[b[u]].begin();
				if (vis[v] == 1) {
					ans = false;
					return;
				}
				dfs(v);
				if (!ans) return;
			}
			vis[u] = 2;
			rest[a[u]].erase(u);
		};
		for (int i = 0; i != N; ++i) if (vis[i] == 0) {
			dfs(i);
			if (!ans) break;
		}
		cout << (ans ? "AC" : "WA") << '\n';
	}

	return 0;
}