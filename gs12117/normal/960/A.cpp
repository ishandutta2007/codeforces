#include<cstdio>
char s[100100];
int n;
int main() {
	int acnt, bcnt, ccnt;
	scanf("%s", s);
	for (n = 0; s[n]; n++);
	acnt = 0;
	bcnt = 0;
	ccnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			acnt++;
			if (bcnt + ccnt != 0) {
				printf("NO");
				return 0;
			}
		}
		else if (s[i] == 'b') {
			bcnt++;
			if (ccnt != 0) {
				printf("NO");
				return 0;
			}
		}
		else {
			ccnt++;
		}
	}
	if (acnt == 0 || bcnt == 0) {
		printf("NO");
		return 0;
	}
	if (acnt == ccnt || bcnt == ccnt) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}