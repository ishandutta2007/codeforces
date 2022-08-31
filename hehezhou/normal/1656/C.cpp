#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int a[200010], n, k;
void rmain() {
	scanf("%d", &n);
	int cont0 = 0, cont1 = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] == 0) cont0 = 1, i--, n--;
		else if (a[i] == 1) cont1 = 1, i--, n--;
	}
	sort(a + 1, a + 1 + n);
	if (cont0 && cont1) return puts("NO"), void();
	if (!cont1) return puts("YES"), void();
	if (n && a[1] == 2) return puts("NO"), void();
	for (int i = 1; i < n; i++) {
		if (a[i + 1] == a[i] + 1) return puts("NO"), void();
	}
	puts("YES");
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}