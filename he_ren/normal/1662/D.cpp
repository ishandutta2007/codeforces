#include <bits/stdc++.h>
using namespace std;

string read() {
	static char buf[210];
	scanf("%s", buf);
	return buf;
}

string Calc(string s) {
	while (1) {
		for (int i = 0; i + 1 < s.size(); i++) {
			if (s[i] == s[i + 1]) {
				s.erase(s.begin() + i, s.begin() + i + 2);
				goto END;
			}
		}
		for (int i = 0; i + 2 < s.size(); i++) {
			if (s[i] == s[i + 2] && (s[i] == 'B' || s[i + 1] == 'B')) {
				s.erase(s.begin() + i + 2), s.erase(s.begin() + i);
				goto END;
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'B') {
				for (int j = i + 1; j < s.size(); j++) {
					if (s[j] == 'B') {
						s.erase(s.begin() + j), s.erase(s.begin() + i);
						goto END;
					}
				}
			}
		}
		break;
		END:;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B') {
			s.erase(s.begin() + i);
			s.push_back('B');
			break;
		}
	}
	return s;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		string s = read(), t = read();
		printf(Calc(s) == Calc(t) ? "YES\n" : "NO\n");
	}
	return 0;
}