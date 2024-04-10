#include <bits/stdc++.h>
using namespace std;

int cnt[2];

int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int need = 0; cnt[0] = cnt[1] = 0;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < s.size(); j++) {
				cnt[s[j] - '0'] ^= 1;
			}
			if (s.size() & 1) need++;
		}
		if (need >= cnt[0] + cnt[1]) cout << n << endl;
		else cout << n - 1 << endl;
	}
	return 0;
}