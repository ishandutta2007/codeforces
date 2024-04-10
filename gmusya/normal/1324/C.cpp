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
		int ma = 0;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') cnt++;
			if (s[i] == 'R') cnt = 0;
			ma = max(ma, cnt);
		}
		cout << ma + 1 << endl;
	}
	return 0;
}