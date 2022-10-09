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
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> col(n);
	int now = 0;
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	for(int i = 2; i < 500; ++i) {
		if (prime(i)) {
			int z = 0;
			for(int j = 0; j < n; ++j) {
				if (a[j] % i == 0 && !col[j])
					++z;
			}
			if (z != 0) {
				++now;
				for(int j = 0; j < n; ++j) {
					if (a[j] % i == 0 && !col[j])
						col[j] = now;
				}
			}
		}
	}
	cout << now << '\n';
	for(auto i: col)
		cout << i << ' ';
	cout << '\n';
}

signed main() {
	setup();
	SOLVE;


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}