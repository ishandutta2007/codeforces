#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int bal0 = 0, bal1 = 0;
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;
		for (auto now : s) {
			if (now == '0')
				bal1++;
			else
				bal0++;
		}
		vector <int> bal(n + 1);
		for (int i = 1; i <= n; i++) {
			bal[i] = bal[i - 1];
			if (s[i - 1] == '0')
				bal[i]++;
			if (s[i - 1] == '1')
				bal[i]--;
		}
		int ans = 0;
		int mi = 1000000, ma = -1000000;
		for (int i = 0; i <= n; i++) {
			mi = min(mi, bal[i]);
			ma = max(ma, bal[i]);
		}
		if ((mi > x && bal[n] >= 0) || (ma < x && bal[n] <= 0)) {
			cout << "0" << endl;
			continue;
		}
		if (bal[n] == 0) {
			cout << "-1" << endl;
			continue;
		}
		if (bal[n] > 0) {
			for (int i = 0; i < n; i++)
				if (((bal[i] % bal[n] + bal[n]) % bal[n] == (x % bal[n] + bal[n]) % bal[n]) && x >= bal[i])
					ans++;
		}
		else {
			for (int i = 0; i < n; i++)
				if (((bal[i] % bal[n] + bal[n]) % bal[n] == (x % bal[n] + bal[n]) % bal[n]) && x <= bal[i])
					ans++;
		}
		cout << ans << endl;
	}
	return 0;
}