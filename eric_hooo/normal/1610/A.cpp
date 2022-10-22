#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		if (n == 1 && m == 1) printf("0\n");
		else if (n == 1 || m == 1) printf("1\n");
		else printf("2\n");
	}
	return 0;
}