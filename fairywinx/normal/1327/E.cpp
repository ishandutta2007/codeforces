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

const int N = 2e5 + 228;
const int MOD = 998244353;

int pw[N];

signed main() {
	setup();	
	pw[0] = 1;
	for(int i = 1; i < N; ++i)
		pw[i] = (pw[i - 1] * 10) % MOD;
	
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i) {
		if (i != n - 1)
			cout << (180 * pw[n - i - 1] + 810 * (n - 1 - i) * pw[n - i - 2]) % MOD << ' '; 
		else 
			cout << (180 * pw[n - i - 1]) % MOD << ' ';
	}
	cout << 10;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}