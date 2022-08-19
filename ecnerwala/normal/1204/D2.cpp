#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	reverse(s.begin(), s.end());
	string t;
	int num0 = 0;
	for (char c : s) {
		if (c == '0') {
			num0 ++;
			t += c;
		} else {
			if (num0 <= 0) {
				t += '0';
			} else {
				t += '1';
				num0 --;
			}
		}
	}
	reverse(t.begin(), t.end());
	cout << t << '\n';

	return 0;
}