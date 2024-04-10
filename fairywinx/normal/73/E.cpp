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

// #include <algorithm>
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
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int N = 1e8 + 228;
bitset<N> pr;

signed main() {
	setup();	

	int n, x;
	cin >> n >> x;
	set<int> a;
	for(int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		a.insert(b);
	}
	if (a.count(1) && x != 2) {
		cout << 1;
		return 0;
	}
	int ans = 0;
	for(int i = 2; i < min(N, x); ++i) {
		if (!pr[i]) {
			// cout << i << ' ';
			++ans;
			if (!a.count(i)) {
				cout << -1;
				return 0;
			}
			if ((long long) i * i >= N)
				continue;
			for(int j = i * i; j < min(N, x); j += i) 
				pr[j] = true;
		}
	}
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}