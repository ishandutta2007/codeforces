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

int pow(int a, int b) {
	if (b == 0) 
		return 1;
	if (b % 2 == 1)
		return (a * pow(a, b - 1)) % MOD;
	int z = pow(a, b / 2);
	return (z * z) % MOD;	
}

signed main() {
	setup();
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int j = i + 1;
		// cout << a[i] << ' ' << pow(2, j - 1) - pow(2, n - j) << '\n';
		ans = (ans + a[i] * (pow(2, j - 1) - pow(2, n - j))) % MOD;
	}
	cout << (ans + MOD) % MOD;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}