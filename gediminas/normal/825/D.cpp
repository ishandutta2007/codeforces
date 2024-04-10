/*input
abcd
abacaba
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false),cin.tie(0);
	string s, t;
	int pas[26] = {};
	int kl = 0;
	int past[26] = {};
	cin >> s >> t;

	for (int i = 0; i < t.size(); i++)
		past[t[i] - 'a']++;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			kl++;
			continue;
		}

		pas[s[i] - 'a']++;
	}

	int it = 0;
	for (int i = 0; i < kl; i++) {

		while (s[it] != '?')
			it++;

		int ma = 0;

		for (int j = 0; j < 26; j++) {
			if (past[ma] == 0 or (past[j] != 0 and pas[j] / past[j] < pas[ma] / past[ma]))
				ma = j;
		}

		pas[ma]++;
		s[it] = ma + 'a';
	}

	cout << s;

	return 0;
}