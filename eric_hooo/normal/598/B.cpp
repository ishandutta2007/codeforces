#include <bits/stdc++.h>
using namespace std;

char tmp[10010];

int main () {
	string s; cin >> s;
	int T; cin >> T;
	while (T--) {
		int l, r, k; cin >> l >> r >> k;
		l--, r--;
		k %= r - l + 1;
		for (int i = l; i <= r; i++) {
			tmp[l + k % (r - l + 1)] = s[i];
			k++;
		}
		for (int i = l; i <= r; i++) {
			s[i] = tmp[i];
		}
	}
	cout << s << endl;
	return 0;
}