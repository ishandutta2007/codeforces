#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 205;

int n;

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'b') putchar('b');
		}
		for (int i = 0; i < n; i++) {
			if (s[i] != 'b') putchar(s[i]);
		}
		puts("");
	}	
	return 0;
}