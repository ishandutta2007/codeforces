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

const int MOD = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1) 
		return (a * pow(a, b - 1)) % MOD;
	int z = pow(a, b / 2);
	return (z * z) % MOD;
}

const int N = 2e5 + 228;
vector<int> G[N];
bool kr[N];
int d[N];
int pr[N];
vector<int> z;

int dfs(int v, int p, int k) {
	d[v] = k;
	pr[v] = p;
	int res = 0;
	for(auto i: G[v]) {
		if (i != p) {
			res += dfs(i, v, k + 1);
		}
	}
	z.push_back(k - res);
	return res + 1;
}

signed main() {
	setup();	
	// SOLVE;

	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0, 0, 0);
	sort(z.rbegin(), z.rend());
	int ans = 0;
	for(int i = 0; i < k; ++i)
		ans += z[i];
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}