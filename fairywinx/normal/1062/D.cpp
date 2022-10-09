// #define GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
#include <cmath>
#include <bitset>

#include <algorithm>
// #define int long long

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif

	srand(time(0));
}

const int N = 2e5 + 228;
const int K = 1e5 + 10;

vector<pair<int, int>> G[N];
int used[N];

long long dfs(int a) {
	// cout << a - K << ' ';
	used[a] = 1;
	long long ans = 0;
	for(auto j: G[a]) {
		ans += j.second;
		if (!used[j.first]) {
			used[j.first] = 1;
			ans += dfs(j.first);
		}
	}
	return ans;
}

signed main() {
	setup();
	fill(used, used + N, 0);
	
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		int z = i * 2;
		while(z <= n) {
			int k = z / i;
			G[z + K].push_back({i + K, k});
			G[i + K].push_back({z + K, k});
			G[z + K].push_back({-i + K, k});
			G[-i + K].push_back({z + K, k});
			G[-z + K].push_back({-i + K, k});
			G[-i + K].push_back({-z + K, k});
			G[-z + K].push_back({i + K, k});
			G[i + K].push_back({-z + K, k});
			z += i;
		}
	}
// 	cout << id << '\n';

	long long ans = 0;
	for(int j = 0; j < N - 5; ++j) {
		if (G[j].size() != 0) {
			if (!used[j])
				ans = max(ans, dfs(j));
		}
	}
	cout << ans / 2;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}