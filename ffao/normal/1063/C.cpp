#include <bits/stdc++.h>
using namespace std;

char resp[10];
int n;

void binsearch(int n, int a, int b, int c, int d) {
	if (n == 0) {
		printf("%d %d %d %d\n", 0, 0, a+c, b+d); return;
	}

	printf("%d %d\n", a+c, b+d);
	fflush(stdout);
	scanf("%s", resp);
	if (resp[0] == 'b') binsearch(n-1, a+c, b+d, c, d);
	else binsearch(n-1, a, b, a+c, b+d);
}

int main() {
	scanf("%d", &n);

	binsearch(n, 0, 1, 1, 0);
}