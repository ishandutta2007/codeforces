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
#define SOLVE int t; cin >> t; while(t--) solve();
// #define double long double

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

const int MOD = 1e9 + 7;
const int N = 2e5 + 228;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * pow(a, b - 1)) % MOD;
	int z = pow(a, b / 2);
	return (z * z) % MOD;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);	
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.rbegin(), a.rend());
	int sum = 0;
	int ans = 0;
	int kol = 0;
	for(int i = 0; i < n; ++i) {
		if (sum + a[i] >= x * (kol + 1)) {
			++ans;
			++kol;
			sum += a[i];
		}
		else
			break;
	}
	cout << ans << '\n';
}

signed main() {
	setup();
	SOLVE;

	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}