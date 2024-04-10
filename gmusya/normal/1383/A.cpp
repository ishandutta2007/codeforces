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
		int n;
		cin >> n;
		vector <char> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		bool tf = true;
		for (int i = 0; i < n; i++)
			if (a[i] > b[i])
				tf = false;
		if (!tf) {
			cout << -1 << '\n';
			continue;
		}
		int ans = 0;
		for (char x = 'a'; x <= 't'; x++) {
			char c = 'z';
			for (int i = 0; i < n; i++) 
				if (a[i] == x && b[i] != a[i]) 
					c = min(c, b[i]);
			if (c == 'z') continue;
			ans++;
			for (int i = 0; i < n; i++)
				if (a[i] == x && b[i] != a[i])
					a[i] = c;
		}
		cout << ans << '\n';
	}
	return 0;
}