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

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	set<int> u;
	for(int i = 0; i < n; ++i)
		u.insert(a[i]);
	int res = 0;
	int i = 1;
	while(true) {
		if (!u.count(i++)) {
			--x;
			if (x < 0) {
				cout << i - 2 << '\n';
				break;
			}
		}
	}
}
signed main() {
	setup();
	SOLVE;



	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}