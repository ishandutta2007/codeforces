#include<cstdio>
int n;
int p[100100];
int s[100100];
int l[100100];
int ls[100100];
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	int chk = 0;
	for (int i = n; i >= 1; i--) {
		if (s[i] == 0)l[i] = 1;
		if (l[i] == 0 && ls[i] < 3)chk = 1;
		s[p[i]]++;
		ls[p[i]] += l[i];
	}
	if (chk == 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}