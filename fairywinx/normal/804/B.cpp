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
// #include <cmath>
#include <bitset>

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
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif

	srand(time(0));
}

const int MOD = 1e9 + 7;

signed main() {
	setup();
	
	string s;
	cin >> s;
	int kol_b = 0;
	int ans = 0;
	for(int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == 'a') {
			ans = (ans + kol_b) % MOD;
			kol_b = (kol_b * 2) % MOD;
		}
		else
			kol_b = (kol_b + 1) % MOD;
	}
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}