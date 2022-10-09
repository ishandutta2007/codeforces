#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>

#define int long long
#define pb emplace_back

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
}

bool prime(int a) {
	for(int i = 2; i * i <= a; ++i) {
		if (a % i == 0)
			return false;
	}
	return true;
}

signed main() {
	setup();

	int n, t;
	cin >> n >> t;
	if (t == 10 && n == 1) {
		cout << -1;
		return 0;
	}
	if (t == 10) {
		cout << 1;
		for(int i = 0; i < n - 1; ++i)
			cout << 0;
		return 0;
	}
	for(int i = 0; i < n; ++i)
		cout << t;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}