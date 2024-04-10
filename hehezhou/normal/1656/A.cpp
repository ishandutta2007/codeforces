#include <bits/stdc++.h>
using namespace std;
int T;
int a[100010], n, id[100010];
void rmain() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), id[i] = i;
	sort(id + 1, id + 1 + n, [](int x, int y) {
		return a[x] < a[y];
	});
	printf("%d %d\n", id[1], id[n]);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}