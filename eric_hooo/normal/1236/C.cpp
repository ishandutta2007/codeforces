#include <bits/stdc++.h>
using namespace std;
int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", (j & 1 ? i : n - i + 1) + (j - 1) * n);
		}
		printf("\n");
	}
	return 0;
}