#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		bool good = false;
		std::vector<bool> found(26*26);
		std::vector<bool> found3(26*26);
		std::vector<bool> found33(26*26*26);
		for (int i = 0; i < N; i++) {
			string s; cin >> s;
			if (s.size() == 1) {
				good = true;
				continue;
			} else if (s.size() == 2) {
				if (s[0] == s[1]) {
					good = true;
					continue;
				}
				if (found[(s[0]-'a')*26 + (s[1]-'a')] || found3[(s[0]-'a')*26 + (s[1]-'a')]) {
					good = true;
					continue;
				}
				found[(s[1]-'a')*26 + (s[0]-'a')] = true;
			} else if (s.size() == 3) {
				if (s[0] == s[2]) {
					good = true;
					continue;
				}
				if (found[(s[1]-'a')*26 + (s[2]-'a')] || found33[(s[0]-'a')*26*26 + (s[1]-'a')*26 + (s[2]-'a')]) {
					good = true;
					continue;
				}
				found3[(s[1]-'a')*26 + (s[0]-'a')] = true;
				found33[(s[2]-'a')*26*26 + (s[1]-'a')*26 + (s[0]-'a')] = true;
			} else assert(false);
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}