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

	int n;
	cin >> n;
	if (n == 3) {
		cout << 1 << '\n' << 3;
		return 0;
	}
	for(int i = n - 2; i >= 0; --i) {
		if (prime(i)) {
			int a = n - i;
			if (prime(a)) {
				cout << 2 << '\n';
				cout << i << ' ' << a << '\n';
				return 0;
			}
			for(int j = 2; j < a; ++j) {
				if (prime(j) && prime(a - j)) {
					cout << 3 << '\n';
					cout << j << ' ' << a - j << ' ' << i << '\n';
					return 0;
				}
			}
		}
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}