#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			sum += x - 1;
		}
		if (sum & 1) printf("errorgorn\n");
		else printf("maomao90\n");
	}
	return 0;
}