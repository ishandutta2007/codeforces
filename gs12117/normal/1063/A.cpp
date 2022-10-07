#include<cstdio>
int n;
char s[100100];
long long int cnt[1000];
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	long long int ans = 0;
	for (int i = 0; s[i]; i++) {
		cnt[s[i]]++;
	}
	for (char i = 0; i <= 'z'; i++) {
		for (int j = 0; j < cnt[i]; j++)printf("%c", i);
	}
	return 0;
}