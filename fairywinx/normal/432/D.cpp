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
// #define int long long

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

	pair<vector<int>, vector<int>> manacher() {
		vector<int> ans_chet(s.size(), 1);
		vector<int> ans_nechet(s.size());
		int l = 0, r = 0;
		for(int i = 1; i < s.size(); ++i) {
			ans_nechet[i] = max(0, min(r - i, ans_nechet[l + r - i]));
			while(i - ans_nechet[i] >= 0 && i + ans_nechet[i] < s.size() && s[i - ans_nechet[i]] == s[i + ans_nechet[i]]) 
				++ans_nechet[i];
			if (i + ans_nechet[i] - 1 > r) 
				r = i + ans_nechet[i] - 1, l = i - ans_nechet[i] + 1;
		}
		l = 0, r = 0;
		for(int i = 1; i < s.size(); ++i) {
			ans_chet[i] = max(0, min(r - i + 1, ans_chet[r - i + l + 1]));
			while(i + ans_chet[i] < s.size() && i - ans_chet[i] - 1 >= 0 && s[i + ans_chet[i]] == s[i - ans_chet[i] - 1]) 
				++ans_chet[i];
			if (i + ans_chet[i] - 1 > r) 
				l = i - ans_chet[i], r = i + ans_chet[i] - 1;
		}
		return make_pair(ans_chet, ans_nechet);
	}

	long long manacher_kol() {
		auto z = manacher();
		long long res = 0;
		for(auto i: z.first)
			res += i;
		for(auto i: z.second)
			res += i;
		return res;
	}

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
			res[i] = max(0, min(r - i, res[i - l]));
			while(res[i] + i < s.size() && s[res[i]] == s[res[i] + i]) ++res[i];
			if (res[i] + i > r) r = res[i] + i, l = i;
		}
		return res;
	}
};

signed main() {
	setup();	

	super_string s;
	cin >> s.s;
	int n = s.s.size();
	vector<int> z = s.z_function();
	vector<int> ans(n + 1);
	for(int i = 0; i < n; ++i) {
		ans[z[i]]++;
	}
	int res = n;
	vector<pair<int, int>> a;

	for(int i = 1; i <= n; ++i) {
		res -= ans[i - 1];
		if (z[n - i] == i)
			a.emplace_back(i, res);
	}
	cout << a.size() << '\n';
	for(auto i: a)
		cout << i.first << ' ' << i.second << '\n';


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}