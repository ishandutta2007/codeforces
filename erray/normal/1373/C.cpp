#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<int> pref(n + 1);
		for (int i = 0; i < n; ++i) {				
			pref[i + 1] = pref[i] + (s[i] == '+' ? 1 : -1);
		}
		int mn = *min_element(pref.begin(), pref.end());
		long long ans = n;
		if (!mn) {
			cout << ans << '\n';
			continue;
		}
		vector<int> vis(-(mn - 1));
		for (int i = 1; i < n + 1 && !vis[-mn]; ++i) {
			if (pref[i] < 0 && !vis[-pref[i]]) {
				ans += i;
				vis[-pref[i]] = 1;
			}
		}
		cout << ans << '\n';
	}
}