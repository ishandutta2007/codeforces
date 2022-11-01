#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt0 += (s[i] == '0');
		cnt1 += (s[i] == '1');
	}
	int n = t.size();
	vector <int> z(n);
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0, min(R - i, z[i - L]));
		while (i < n && t[z[i]] == t[i + z[i]]) z[i]++;
		if (i + z[i] > R) L = i, R = i + z[i];
	}
	int ans = n;
	for (int i = 0; i < n; i++)
		if (i + z[i] == n) {
			ans = n - z[i];
			break;
		}
	string period = t.substr(0, ans);
	for (int i = 0; i < s.size(); i++) {
		if (!cnt1) {
			cout << '0';
			continue;
		}
		if (!cnt0) {
			cout << '1';
			continue;
		}
		int pos = i % period.size();
		cout << period[pos];
		if (period[pos] == '0') cnt0--;
		else cnt1--;
	}
	return 0;
}