#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	if (s == "0") {
		cout << 0 << '\n';
	} else {
		int l = int(s.size() - 1) / 2;
		string t = "1" + string(l*2, '0');
		if (s == t) {
			cout << l << '\n';
		} else {
			cout << l+1 << '\n';
		}
	}

	return 0;
}