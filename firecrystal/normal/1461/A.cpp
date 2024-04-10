#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) putchar('a' + (i % 3));
		puts("");
	}	
	return 0;
}