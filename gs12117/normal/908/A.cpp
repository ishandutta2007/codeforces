#include<cstdio>
#include<cstring>
int n;
char s[55];
char rev[15] = "13579aeiou";
int main() {
	scanf("%s", s);
	n = strlen(s);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (s[i] == rev[j])ans++;
		}
	}
	printf("%d", ans);
	return 0;
}