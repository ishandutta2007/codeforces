#include<cstdio>
int n;
char s[200100];
int ans[200100];
int main() {
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%s", s);
		for (n = 0; s[n]; n++);
		for (int i = 0; i < n; i++) {
			ans[i] = 0;
		}
		for (int i = 0; i + 2 < n; i++) {
			if (s[i] == 'o'&&s[i + 1] == 'n'&&s[i + 2] == 'e')ans[i + 1] = 1;
			if (s[i] == 't'&&s[i + 1] == 'w'&&s[i + 2] == 'o')ans[i + 1] = 1;
		}
		for (int i = 0; i + 2 < n; i++) {
			if (ans[i] == 1 && ans[i + 2] == 1) {
				ans[i] = 0;
				ans[i + 1] = 1;
				ans[i + 2] = 0;
			}
		}
		int sans = 0; // wow!
		for (int i = 0; i < n; i++) {
			sans += ans[i];
		}
		printf("%d\n", sans);
		for (int i = 0; i < n; i++) {
			if (ans[i])printf("%d ", i + 1);
		}
		printf("\n");
	}
	return 0;
}