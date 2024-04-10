#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int filled = 0;
	for (char c : s) {
		if (c == 'L') {
			int i = 0;
			while (filled & (1 << i)) i++;
			filled |= (1 << i);
		} else if (c == 'R') {
			int i = 9;
			while (filled & (1 << i)) i--;
			filled |= (1 << i);
		} else {
			filled -= (1 << (c - '0'));
		}
	}
	for (int i = 0; i < 10; i++) cout << char('0' + bool(filled & (1 << i)));
	cout << '\n';

	return 0;
}