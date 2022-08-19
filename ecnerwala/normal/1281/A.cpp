#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		if (s.back() == 'o') {
			cout << "FILIPINO" << '\n';
		} else if (s.back() == 'u') {
			cout << "JAPANESE" << '\n';
		} else {
			cout << "KOREAN" << '\n';
		}

	}
	return 0;
}