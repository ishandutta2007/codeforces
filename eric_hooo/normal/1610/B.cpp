#include <bits/stdc++.h>
using namespace std;

int a[200010];
int n;

bool Check(int x) {
	int l = 0, r = n - 1;
	while (1) {
		while (l < r && a[l] == x) l++;
		while (l < r && a[r] == x) r--;
		if (l >= r) return 1;
		if (a[l] != a[r]) return 0;
		l++, r--;
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int l = 0, r = n - 1;
		while (l < r && a[l] == a[r]) l++, r--;
		if (l >= r) {
			printf("YES\n");
			continue;
		}
		if (Check(a[l]) || Check(a[r])) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}