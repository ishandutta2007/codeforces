#include <bits/stdc++.h>
using namespace std;

int n; long long S;
int L[200010], R[200010];
int id[200010];

bool cmp(int x, int y) {
	return L[x] < L[y];
}

bool check(long long mid) {
	int need = n + 1 >> 1; long long cur = S;
	for (int i = n - 1; i >= 0; i--) {
		int x = id[i];
		if (L[x] >= mid) {
			need--;
			if (need == 0) return 1;
		}
		else {
			if (need >= 1 && R[x] >= mid) {
				need--, cur -= mid - L[x];
				if (cur < 0) return 0;
			}
		}
	}
	return need <= 0 && cur >= 0;
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%I64d", &n, &S);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &L[i], &R[i]);
			S -= L[i], id[i] = i;
		}
		sort(id, id + n, cmp);
		long long l = 0, r = 200000000000000;
		while (l < r) {
			long long mid = l + r + 1 >> 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%I64d\n", l);
	}
	return 0;
}