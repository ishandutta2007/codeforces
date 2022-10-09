#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <iomanip>
#include <string>
#include <ctime>

// #include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

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

bool prime(int a) {
	for(int i = 2; i * i <= a; ++i) {
		if (a % i == 0)
			return false;
	}
	return true;
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int kol = n / k;
	vector<int> res(n, 1e9);
	int ans = 0;
	for(int i = 0; i < (k) / 2; ++i) {
		for(int c = 0; c < 26; ++c) {
			int z = 0;
			for(int j = 0; j < kol; ++j) {
				if (s[k * j + i] != (c + 'a')) {
					// cout << j << ' ' << s[k * j + i] << ' ' << k * j + i << ' ' << (char) (c + 'a') << '\n';
					++z;
				}
				if (s[k * (j + 1) - i - 1] != (c + 'a')) {
					// cout << '4' << ' ' << s[k * (j + 1) - i - 1] << ' ' << k * j + k - 1 + i << ' ' << (char) (c + 'a') << '\n';
					++z;
				}
			}
			res[i] = min(res[i], z);
		}	
		// cout << res[i] << ' ';
		ans += res[i];
	}
	if (k % 2 == 1) {
		int i = k / 2;
		for(int c = 0; c < 26; ++c) {
			int z = 0;
			for(int j = 0; j < kol; ++j) {
				if (s[k * j + i] != (c + 'a')) {
					// cout << j << ' ' << s[k * j + i] << ' ' << k * j + i << ' ' << (char) (c + 'a') << '\n';
					++z;
				}
			}
			res[i] = min(res[i], z);
			// cout << res[i] << ' ';
		}	
		ans += res[i];
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