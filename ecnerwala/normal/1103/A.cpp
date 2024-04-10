#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int vind = 0;
	int hind = 0;
	for (char c : s) {
		if (c == '0') {
			cout << (vind % 2) * 2 + 1 << ' ' << 1 << '\n';
			vind ++;
		} else if (c == '1') {
			cout << hind % 4 + 1 << ' ' << 2 + 1 << '\n';
			hind ++;
		} else assert(false);
	}

	return 0;
}