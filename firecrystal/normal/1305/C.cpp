#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200005;
typedef long long LL;
int n, P, a[N], b[N];
int main() {
	scanf("%d%d", &n, &P);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	if (n > P) {
		puts("0");
		return 0;
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans = (LL)ans * (a[j] - a[i]) % P;
		}
	}
	printf("%d\n", ans);
	return 0;
}