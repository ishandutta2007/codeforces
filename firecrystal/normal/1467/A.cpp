#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

int n;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int a = 9;
		for (int i = 1; i <= n; i++) {
			putchar(a + '0');
			if (i == 1) a = 8;
			else a = (a + 1) % 10;
		}			
		puts("");
	}	
	return 0;
}