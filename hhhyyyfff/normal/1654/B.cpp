#include <bits/stdc++.h>

using namespace std;

char s[200001];
int t, cnt[26];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; s[i]; ++i) ++cnt[s[i] - 'a'];
		for (int i = 0; s[i]; ++i)
			if (!--cnt[s[i] - 'a']) {
				printf("%s\n", s + i);
				break;
			}
	}
	return 0;
}