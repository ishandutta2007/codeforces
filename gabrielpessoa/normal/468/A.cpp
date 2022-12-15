#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n < 4) {
		puts("NO");
		return 0;
	}
	puts("YES");
	while(n > 5) {
		printf("%d - %d = 1\n1 * 1 = 1\n", n, n - 1);
		n -= 2;
	}
	if(n == 5) {
		printf("5 - 1 = 4\n4 - 2 = 2\n4 * 3 = 12\n12 * 2 = 24\n");
	} else {
		printf("4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24\n");
	}
	return 0;
}