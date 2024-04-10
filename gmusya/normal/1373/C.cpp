#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		long long bal = 0;
		long long mi = 0;
		long long ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '-') bal--;
			else bal++;
			if (bal < mi) {
				ans += (i + 1);
				mi = bal;
			}
		}
		cout << ans + s.size() << '\n';
	}
	return 0;
}