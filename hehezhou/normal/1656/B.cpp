#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int a[200010], n, k;
void rmain() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		int need = k + a[i];
		auto ite = lower_bound(a + 1, a + 1 + n, need);
		if (ite != a + 1 + n && *ite == need) return puts("YES"), void();
	}
	puts("NO");
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}