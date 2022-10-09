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

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

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

const int inf = 1e18;
const int N = 3e5 + 228;
const int mod = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * pow(a, b - 1)) % mod;
	int z = pow(a, b / 2);
	return (z * z) % mod;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	vector<pair<int, int>> cnt(n, make_pair(0, 0));
	for(int i = 0; i < n - 1; ++i) {
		cnt[i + 1] = cnt[i];
		if (a[i] == 1) 
			++cnt[i + 1].first;
		if (a[i] == -1)
			++cnt[i + 1].second;
	}
	bool res = true;
	for(int i = 0; i < n; ++i) {
		if (b[i] > a[i] && cnt[i].first == 0)
			res = false;
		if (b[i] < a[i] && cnt[i].second == 0)
			res = false;
	}
	if (res)
		cout << "YES\n";
	else
		cout << "NO\n";
}

signed main() {
	setup();
	SOLVE;
	


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}