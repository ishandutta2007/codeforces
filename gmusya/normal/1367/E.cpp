#include <iostream>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b) {
	if (a % b) return gcd(b, a % b);
	return b;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <int> cnt(26);
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			cnt[c - 'a']++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int g = i / gcd(k, i);
			int _ans = 0;
			for (int j = 0; j < 26; j++)
				_ans += cnt[j] / g * g;
			if (_ans >= i)
				ans = i;
		}
		cout << ans << '\n';
	}
	return 0;
}