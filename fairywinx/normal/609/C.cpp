#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif
	//srand(time(NULL));
}

signed main() {
	setup();

	int n;
	cin >> n;
	vector<int> a;
	int sum = 0;
	int last = 1;
	for(int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		sum += b;
		a.push_back(b);
	}

	int ans = 0;
	if (sum % n == 0) {
		for(int i = 0; i < n; ++i) 
			ans += abs(a[i] - sum / n);
	}
	else {
		int z = n - sum % n;
		sort(all(a));
		for(auto i: a) {
			if (z != 0) {
				--z;
				ans += abs(i - sum / n);
			}
			else 
				ans += abs(i - (sum + n - 1) / n);
		}
	}
	cout << ans / 2;
}