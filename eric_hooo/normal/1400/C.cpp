#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s; int k; cin >> k;
		int n = s.length();
		string w; w.resize(n, '1');
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i - k >= 0) w[i - k] = '0';
				if (i + k < n) w[i + k] = '0';
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				int pd = 0;
				if (i - k >= 0) pd |= w[i - k] == '1';
				if (i + k < n) pd |= w[i + k] == '1';
				if (!pd) {
					printf("-1\n");
					goto END;
				}
			}
		}
		cout << w << endl;
		END:;
	}
	return 0;
}