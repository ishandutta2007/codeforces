#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int x; scanf("%d", &x);
		int sum = 0;
		while (x >= 10) {
			sum += x / 10 * 10;
			x = x - x / 10 * 10 + x / 10;
		}
		sum += x;
		printf("%d\n", sum);
	}
	return 0;
}