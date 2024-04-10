// July 13, 2018


#include <bits/stdc++.h>

using namespace std;


bool is_vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	string s;
	cin >> s;
	int n = s.length();
	for (int i = 1; i < n; i++) {
		if (!is_vowel(s[i]) && !is_vowel(s[i - 1]) && s[i - 1] != 'n') {
			cout << "NO\n";
			return 0;
		}
	}

	if (!is_vowel(s.back()) && s.back() != 'n') {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}


	return 0;
}