#include <bits/stdc++.h>
using namespace std;

char s[200010], t[200010];
int cnt[26];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		goto BEG;
		GOOD:;
		printf("YES\n");
		continue;
		BAD:;
		printf("NO\n");
		continue;
		BEG:;
		int n; scanf("%d", &n);
		scanf("%s%s", s, t);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] != 0) goto BAD;
		}
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 1) goto GOOD;
		}
		memset(cnt, 0, sizeof(cnt));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x = s[i] - 'a';
			for (int j = x + 1; j < 26; j++) {
				ans = ans + cnt[j] & 1;
			}
			cnt[x]++;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			int x = t[i] - 'a';
			for (int j = x + 1; j < 26; j++) {
				ans = ans + cnt[j] & 1;
			}
			cnt[x]++;
		}
		if (ans == 1) goto BAD;
		else goto GOOD;
	}
	return 0;
}