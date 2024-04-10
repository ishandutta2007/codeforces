#include <bits/stdc++.h>
using namespace std;

set <string> all;
char buf[10];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int ans = 0;
		all.clear();
		for (int i = 0; i < n; i++) {
			scanf("%s", buf); string s = buf;
			string old = s;
			auto Check = [&](string s) -> bool {
				string t = s; reverse(t.begin(), t.end());
				return s == t;
			};
			if (Check(s)) ans = 1;
			if (s.size() == 2) {
				reverse(s.begin(), s.end());
				if (all.count(s)) ans = 1;
				s.push_back('a');
				for (char c = 'a'; c <= 'z'; c++) {
					s.back() = c;
					if (all.count(s)) ans = 1;
				}
			} else if (s.size() == 3) {
				reverse(s.begin(), s.end());
				if (all.count(s)) ans = 1;
				s.pop_back();
				if (all.count(s)) ans = 1;
			}
			all.insert(old);
		}
		printf(ans ? "YES\n" : "NO\n");
	}
	return 0;
}