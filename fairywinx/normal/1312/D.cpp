//#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <map>
#include <assert.h>

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int inf = 1e16 + 100;
const int MOD = 998244353;

int powz(int a, int b) {
	// cout << b << ' ';
	if (b == 0)
		return 1;
	int z = powz(a, b / 2);
	if (b % 2 == 0) {
		// cout << b << ' ' << (z * z) % MOD << ' ';
		return (z * z) % MOD;
	}
	else {
		// cout << b << ' ' << (z * z) % MOD << ' ';
		return (((z * z) % MOD) * a) % MOD;
	}
}

int fact(int n) {
	int ans = 1;
	for(int i = 1; i <= n; ++i)
		ans = (ans * i) % MOD;
	return ans;
}

int C(int n, int k) {
	int ans = 1;
	for(int i = 0; i < k; ++i) 
		ans = (ans * (n - i)) % MOD;
	int z = fact(k);
	// cout << z << '\n';
	// cout << powz(z, MOD - 1) << '\n';
	int o = powz(z, MOD - 2);
	// cout << o << ' ' << MOD - 1 << '\n' ;
	// cout << ans << '\n';
	return ((ans * powz(z, MOD - 2)) % MOD);
}

signed main() {
	setup();
	// SOLVE;	
	int n, m;
	cin >> n >> m;
	cout << ((C(m, n - 1) * powz(2, n - 3)) % MOD) * (n - 2) % MOD;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}