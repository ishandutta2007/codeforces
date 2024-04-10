#include <cstdio>

char s[110];

int main() {
	int n;
	scanf("%d%s", &n, s + 1);
	bool f = false;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == s[i + 1] && s[i] != '?') {
			puts("No");
			return 0;
		}
		if (s[i] == '?' && !(i > 1 && i < n && s[i - 1] != '?' && s[i + 1] != '?' && s[i - 1] != s[i + 1]))
			f = true;
	}
	if (f)
		puts("Yes");
	else
		puts("No");
	return 0;
}