#include <bits/stdc++.h>
using namespace std;


int n,k;
int a,b,c,d;
void solve() {
	scanf("%d %d", &n, &k);
	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (n == 4 || k <= n) {
		printf("-1\n");
		return;
	}

	printf("%d %d ", a, c);
	for (int i = 1; i <= n; i++) if (i != a && i != b && i != c && i != d) {
		printf("%d ", i);
	}
	printf("%d %d\n", d, b);


	printf("%d %d ", c, a);
	for (int i = 1; i <= n; i++) if (i != a && i != b && i != c && i != d) {
		printf("%d ", i);
	}
	printf("%d %d\n", b, d);
}

int main() {
    solve();
}