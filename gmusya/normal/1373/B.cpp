#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') cnt0++;
			else cnt1++;
		}
		if (cnt0 > cnt1) swap(cnt0, cnt1);
		if (cnt0 % 2) cout << "DA\n";
		else cout << "NET\n";
	}
	return 0;
}