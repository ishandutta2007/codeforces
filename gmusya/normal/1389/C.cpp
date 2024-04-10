#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int ans = n;
		for (char c0 = '0'; c0 <= '9'; c0++)
			for (char c1 = '0'; c1 <= '9'; c1++) {
				int sum = 0;
				bool tf = true;
				for (int i = 0; i < n; i++) {
					if (s[i] != c0 && s[i] != c1) {
						sum++;
						continue;
					}
					if (tf) {
						if (s[i] == c0) tf = false;
						else sum++;
						continue;
					}
					if (s[i] == c1) tf = true;
					else sum++;
				}
				if (c0 == c1) ans = min(ans, sum);
				else {
					if ((n - sum) % 2) sum++;
					ans = min(ans, sum);
				}
			}
		cout << ans << '\n';
	}
	return 0;
}