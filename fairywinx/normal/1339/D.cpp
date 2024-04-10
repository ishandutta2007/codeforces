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

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3");

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

const int N = 2e5 + 228;
const int MOD = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * pow(a, b - 1)) % MOD;
	int z = pow(a, b / 2);
	return (z * z) % MOD; 
}

vector<int> G[N];
bool _ = true;

pair<int, bool> ans_min(int v, int p) {
	// cout << v << ' ';
	int koll = 0;
	int kol_1 = 0, kol_0 = 0;
	bool l = true;
	for(auto i: G[v]) {
		// ++koll;
		if (i == p)
			continue;
		++koll;
		auto z = ans_min(i, v);
		if (z.second)
			++kol_1;
		else {
			if (z.first == 1)
				++kol_0;
			else 
				++kol_1;
		}
	}

	// cout << v + 1 << ' ' << kol_1 << ' ' << kol_0 << ' ' << koll << '\n';

	if (koll == 0)
		return {1, true};
	if (kol_0 != 0 && kol_1 != 0) {
		_ = false;
		return {0, false};
	}
	if (kol_1 != 0)
		return {1, false};
	else
		return {0, false};
}

int anss = 0;

bool dfs_max(int v, int p) {
	int koll = 0;
	bool res = false;
	for(auto i: G[v]) {
		if (i == p)
			continue;
		++koll;
		if (dfs_max(i, v))
			res = true;
	} 
	// cout << v << ' ' << koll << '\n';
	if (res)
		++anss;
	// cout << v << ' ' << res << '\n';
	if (koll == 0) {
		return true;
	}
	return false;
}

signed main() {
	setup();
	// SOLVE;

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int s;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if (G[i].size() != 1) {
			// cout << i + 1 << ' ' << G[i].size() << '\n';
			s = i;
		}
		else
			++ans;
	}
	// cout << s << '\n';
	ans_min(s, -1);
	if (_)
		cout << 1 << ' ';
	else
		cout << 3 << ' ';
	dfs_max(s, -1);
	cout << n - ans - 1 + anss;



	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}