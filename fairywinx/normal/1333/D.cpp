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

signed main() {
	setup();
	
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<vector<int>> can;

	int now = 0;
	int gl = 0;
	while(true) {
		vector<int> can_now;
		string cur;
		for(int i = 0; i < n - 1; ++i) {
			if (s[i] == 'R' && s[i + 1] == 'L') {
				s[i] = 'L';
				s[i + 1] = 'R';
				++gl;
				can_now.push_back(i);
				++i;
			} 
			else
				cur += s[i];
		}
		if (can_now.size() == 0)
			break;
		can.push_back(can_now);
	}

	// for(auto i: can) {
	// 	for(auto j: i)
	// 		cout << j + 1 << ' ';
	// 	cout << '\n';
	// }
	// cout << '\n';

	vector<vector<int>> ans;
	if (k > gl || k < can.size()) {
		cout << -1;
		return 0;
	}

	int cur_level = 0;
	int cur_p = 0;
	for(int i = 0; i < k; ++i) {	
		ans.push_back(vector<int> ());
		int z = 0;
		while(true) {
			ans.back().push_back(can[cur_level][cur_p++]);
			--gl;
			bool o = false;
			if (cur_p == can[cur_level].size())
				cur_p = 0, ++cur_level, ++z, o = true;
			if ((k - 1 - i) == gl)
				break;
			if ((k - 1 - i) == can.size() - cur_level || o)
				break;
		}
	}	
	for(auto i: ans) {
		// cout << "MEOW";
		cout << i.size() << ' ';
		for(auto j: i)
			cout << j + 1 << ' ';
		cout << '\n';
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}