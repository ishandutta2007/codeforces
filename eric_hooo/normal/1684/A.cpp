#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		static string s; s.clear();
		while (n) s.push_back('0' + n % 10), n /= 10;
		if (s.size() == 2) {
			printf("%c\n", s[0]);
			continue;
		}
		char minj = '9' + 1;
		for (auto it : s) {
			minj = min(minj, it);
		}
		printf("%c\n", minj);
	}
	return 0;
}