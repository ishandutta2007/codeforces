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
#define SOLVE int t; cin >> t; while(t--) solve();

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3")

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
		return a * pow(a, b - 1) % MOD;
	int z = pow(a, b / 2);
	return z * z % MOD;
}

int fact(int n) {
	int ans = 1;
	for(int i = 1; i <= n; ++i)
		ans = ans * i % MOD;
	return ans;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> ans(n * k);
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	set<int> used;
	for(int i = 0; i < n; ++i) 
		used.insert(a[i]);
	if (used.size() > k) {
		cout << -1 << '\n';
		return;
	}
	for(int i = 0; i < n * k; i += k) {
		int j = i;
		for(auto i: used) {
			ans[j] = i;
			++j;
		}
		for(; j < i + k; ++j) 
			ans[j] = 1;
	}
	cout << ans.size() << '\n';
	for(auto i: ans)
		cout << i << ' ';
	cout << '\n';
}

signed main() {
	setup();
	SOLVE;
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}