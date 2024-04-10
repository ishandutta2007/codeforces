// #define GLIBCXX_DEBUG

//    - 12:15

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

#include <algorithm>
#define int long long

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

int calc(pair<int, int> l, int a) {
	int len = l.second - l.first + 1;
	if (len < a)
		return 0;
	return (len - a) / (a + 1) + 1;
}

signed main() {
	setup();
	
	int n, k, a;
	cin >> n >> k >> a;
	set<pair<int, int>> z;
	z.emplace(n, 1);
	int q;
	cin >> q;
	int kol = calc({1, n}, a);
	for(int _ = 1; _ <= q; ++_) {
		int l;
		cin >> l;
		if (z.lower_bound({l, 0}) == z.end())
			continue;
		auto b = *z.lower_bound({l, 0});
		z.erase(b);
		swap(b.first, b.second);
		kol -= calc(b, a);
		kol += calc({b.first, l - 1}, a);
		kol += calc({l + 1, b.second}, a);
		z.emplace(l - 1, b.first);
		z.emplace(b.second, l + 1);
		if (kol < k) {
			cout << _;
			return 0;
		}
		// cout << kol << '\n';
	}
	cout << -1 << '\n';

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}