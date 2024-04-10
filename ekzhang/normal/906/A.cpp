#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N;
bool ok[26];
bool seen[26];
int num = 26;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	memset(ok, 1, sizeof ok);
	cin >> N;
	int ans = N;
	for (int q = 0; q < N - 1; q++) {
		string t;
		string s;
		cin >> t >> s;
		if (t[0] == '!') {
			// is one of
			memset(seen, 0, sizeof seen);
			for (char c : s) {
				seen[c - 'a'] = true;
			}
			for (int i = 0; i < 26; i++) {
				if (!seen[i] && ok[i]) {
					ok[i] = false;
					--num;
				}
			}
		}
		else {
			for (char c : s) {
				int i = c - 'a';
				if (ok[i]) {
					ok[i] = false;
					--num;
				}
			}
		}
		if (num == 1) {
			ans = q + 1;
			break;
		}
	}

	int ac = 0;
	for (int q = ans; q < N - 1; q++) {
		string t, s;
		cin >> t >> s;
		if (t[0] == '!' || t[0] == '?') ac++;
	}

	cout << ac << endl;
	return 0;
}