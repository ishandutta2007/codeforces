#include <bits/stdc++.h>
using namespace std;

char s[200010];
int cnt[26];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}
		for (int i = 0; i < n; i++) {
			if (cnt[s[i] - 'a'] == 1) {
				printf("%s\n", s + i);
				break;
			}
			cnt[s[i] - 'a']--;
		}
	}
	return 0;
}