#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		pair <string, int> ans;
		for (int i = 0; i < n; i++)
			ans.first += 'z';
		ans.second = 0;
		for (int k = 0; k < n; k++) {
			string t;
			for (int i = 0; i < n; i++)
				t += s[(i + k) % n];
			if ((n + k) % 2)
				reverse(t.begin() + n - k, t.begin() + n);
			ans = min({ t, k }, ans);
		}
		cout << ans.first << endl << ans.second + 1 << endl;
	}
	return 0;
}