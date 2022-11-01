#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5005;
int n;
char s[N], ans[N], a[N];

bool judge() {
	for (int i = 1; i <= n; i++) {
		if (a[i] < ans[i]) return true;
		else if(a[i] > ans[i]) return false;
	}
	return false;
}

bool check(int x) {
	for (int i = 1; i + x - 1 <= n; i++) a[i] = s[i + x - 1];
	int t = n - x + 1;
	for (int i = 1; i < x; i++) a[i + (n - x + 1)] = s[i];
	if (t & 1) {
		reverse(a + (n - x + 2), a + n + 1);
	}
	return judge();
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s + 1);
		int v = 1;
		for (int i = 1; i <= n; i++) ans[i] = s[i];
		for (int k = 2; k <= n; k++) {
			if (check(k)) {
				v = k;
				for (int j = 1; j <= n; j++) ans[j] = a[j];
			}
		}
		for (int i = 1; i <= n; i++) printf("%c", ans[i]);
		printf("\n%d\n", v);
	}
	return 0;
}