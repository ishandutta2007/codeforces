#include <bits/stdc++.h>
using namespace std;

bitset <2020> f, ful;
int n;
int a[10010];

bool Check(int N) {
	ful.reset();
	for (int i = 0; i <= N; i++) {
		ful[i] = 1;
	}
	f = ful;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		f = (f << x | f >> x) & ful;
	}
	for (int i = 0; i <= N; i++) {
		if (f[i]) return 1;
	}
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int l = 0, r = 2000;
		while (l < r) {
			int mid = l + r >> 1;
			if (Check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}