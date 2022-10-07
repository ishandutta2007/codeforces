#include<cstdio>
char s[5];
int n;
char st[110][5];
int main() {
	scanf("%s", s);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", st[i]);
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (st[i][0] == s[0] && st[i][1] == s[1])flag = 3;
		if (st[i][1] == s[0])flag |= 1;
		if (st[i][0] == s[1])flag |= 2;
	}
	if (flag == 3) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}