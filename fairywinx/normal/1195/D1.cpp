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

const int MOD = 998244353;

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
	vector<int> cnt(13);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		string s = to_string(a[i]);
		cnt[s.size()]++;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		string s = to_string(a[i]);
		int len = s.size();
		for(int j = 0; j < 13; ++j) {
			int l_ans = 0;
			if (cnt[j] == 0)
				continue;
			int p = len, q = j;
			while(p > 0) {
				if (q > 0) 
					--q;
				if (p > 0) {
					l_ans = (l_ans + (s[p - 1] - '0') * pow(10 , (j + len) - (p + q + 0))) % MOD;
					--p;
				}
			}
			// cout << a[i] << ' ' << len << ' ' << j << ' ' << l_ans << '\n';
			ans = (ans + l_ans * cnt[j]) % MOD;
			l_ans = 0;
			p = len, q = j;
			while(p > 0) {
				if (p > 0) {
					l_ans = (l_ans + (s[p - 1] - '0') * pow(10 , (j + len) - (p + q + 0))) % MOD;
					--p;
				}
				if (q > 0)
					--q;
			}
			// cout << a[i] << ' ' << len << ' ' << j << ' ' << l_ans << '\n';
			ans = (ans + l_ans * cnt[j]) % MOD;
		}
	}
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}