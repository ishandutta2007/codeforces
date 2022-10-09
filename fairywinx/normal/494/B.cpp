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

struct super_string {
	string s;
	super_string(string _s) {s = _s;};
	super_string() {}

	// pair<vector<int>, vector<int>> manacher() {
	// 	vector<int> ans_chet(s.size(), 1);
	// 	vector<int> ans_nechet(s.size());
	// 	int l = 0, r = 0;
	// 	for(int i = 1; i < s.size(); ++i) {
	// 		ans_nechet[i] = max(0, min(r - i, ans_nechet[l + r - i]));
	// 		while(i - ans_nechet[i] >= 0 && i + ans_nechet[i] < s.size() && s[i - ans_nechet[i]] == s[i + ans_nechet[i]]) 
	// 			++ans_nechet[i];
	// 		if (i + ans_nechet[i] - 1 > r) 
	// 			r = i + ans_nechet[i] - 1, l = i - ans_nechet[i] + 1;
	// 	}
	// 	l = 0, r = 0;
	// 	for(int i = 1; i < s.size(); ++i) {
	// 		ans_chet[i] = max(0, min(r - i + 1, ans_chet[r - i + l + 1]));
	// 		while(i + ans_chet[i] < s.size() && i - ans_chet[i] - 1 >= 0 && s[i + ans_chet[i]] == s[i - ans_chet[i] - 1]) 
	// 			++ans_chet[i];
	// 		if (i + ans_chet[i] - 1 > r) 
	// 			l = i - ans_chet[i], r = i + ans_chet[i] - 1;
	// 	}
	// 	return make_pair(ans_chet, ans_nechet);
	// }

	// long long manacher_kol() {
	// 	auto z = manacher();
	// 	long long res = 0;
	// 	for(auto i: z.first)
	// 		res += i;
	// 	for(auto i: z.second)
	// 		res += i;
	// 	return res;
	// }

	vector<int> pref_function() {
		vector<int> res(s.size(), 0);
		for(int i = 1; i < s.size(); ++i) {
			res[i] = res[i - 1];
			while(res[i] > 0 && s[i] != s[res[i]]) res[i] = res[res[i] - 1];
			if (s[i] == s[res[i]]) ++res[i];
		}
		return res;
	}

	vector<int> z_function() {
		vector<int> res(s.size(), s.size());
		int l = 0, r = 0;
		for(int i = 1; i < s.size(); ++i) {
			res[i] = max((long long) 0, min(r - i, res[i - l]));
			while(res[i] + i < s.size() && s[res[i]] == s[res[i] + i]) ++res[i];
			if (res[i] + i > r) r = res[i] + i, l = i;
		}
		return res;
	}
};

const int MOD = 1e9 + 7;
const int N = 1e5 + 228;

int dp[N][2];

signed main() {
	setup();	

	string s, t;
	cin >> s >> t;
	super_string O(t + "$" + s);
	auto z = O.z_function();
	vector<int> good(s.size() + 10);
	for(int i = 0; i < s.size(); ++i) {
		if (z[i + t.size() + 1] == t.size()) {
			// cout << i + 1 << ' ';
			good[i + 1] = 1;
		}
	}
	// cout << '\n';
	for(int i = 0; i < N - 1; ++i) {
		dp[i][1] = 0;
		dp[i][0] = 1;
	}
	if (good[0] && t.size() == 1) 
		dp[1][1] = 1;
	vector<int> pref(s.size() + 1, 1);
	for(int i = 1; i <= s.size(); ++i) {
		pref[i] = pref[i - 1];
		if (i < t.size()) {
			pref[i] = (pref[i] + dp[i][0] + dp[i][1]) % MOD;
			continue;
		}
		if (good[i - t.size() + 1]) {
			// cout << i << ' ' << pref[i - t.size()] << '\n';
			dp[i][1] = ((pref[i - t.size()] - dp[i - 1][1]) % MOD + MOD) % MOD;
		}
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
		pref[i] = (pref[i] + dp[i][0] + dp[i][1]) % MOD;
	}
	// for(int i = 0; i <= s.size(); ++i)
	// 	cout << pref[i] << ' ';
	// cout << '\n';
	// for(int i = 1; i <= s.size(); ++i) 
	// 	cout << dp[i][0] << ':' << dp[i][1] << ' ';
	// cout << '\n';
	cout << (dp[s.size()][0] + dp[s.size()][1] - 1) % MOD;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}