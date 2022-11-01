#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 100005;
int f[MAXN], a[MAXN], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int ans = 0, lst = 0, lp = 0;
	for (int i = 1; i <= n;) {
		int j = i;
		while (j < n && a[j + 1] == a[i]) ++j;
		if (j > i) {
			if (a[i] == lst) {
				bool flag = false;
				for (int k = lp + 1; k < i; k++)
					if (a[k] != lst && a[k + 1] != lst) flag = true;
				if (flag) ans += 2;
				else ++ans;
			} else ans += 2;
			lst = a[i];
			lp = j;
		} else ++ans;
		i = j + 1;
	}
	printf("%d\n", ans);
	return 0;
}