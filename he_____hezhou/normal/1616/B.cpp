#include <bits/stdc++.h>
using namespace std;
int T, n, k;
char s[100010];
char ans[200010];
void rmain() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	if (s[1] == s[2]) {
		putchar(s[1]);
		putchar(s[1]);
		puts("");
		return;
	}
	k = n;
	for (int i = 1; i < n; i++) {
		if (s[i] < s[i + 1]) {
			k = i;
			break;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= k; i++) ans[++cnt] = s[i];
	for (int i = k; i > 0; i--) ans[++cnt] = s[i];
	ans[++cnt] = 0;
	puts(ans + 1);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}