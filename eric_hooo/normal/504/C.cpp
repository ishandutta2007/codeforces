#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int cnt[100010], TOTOT = 2333;
int vis[100010];
int MID = -1;

bool check(int l, int r) {
	memset(cnt, 0, sizeof(cnt));
	int nl = n - r - 1, nr = n - l - 1;
	for (int i = 0; i < n; i++) {
		if ((i < l || i > r) && (i < nl || i > nr)) {
			int j = n - i - 1;
			if ((j < l || j > r) && (j < nl || j > nr)) {
				if (a[i] != a[j]) return 0;
			}
		}
	}
	if (n & 1) {
		int mid = n >> 1;
		if ((mid < l || mid > r) && (mid < nl || mid > nr)) {
			if (a[mid] != MID) return 0;
		}
	}
	if (nl > r || nr < l) {
		for (int i = l; i <= r; i++) {
			int x = a[i];
			cnt[x]++;
		}
		for (int i = nl; i <= nr; i++) {
			int x = a[i];
			if (!cnt[x]) return 0;
			cnt[x]--;
		}
		return 1;
	}
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (l <= i && i <= r) {
			cnt[x]++;
		}
	}
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (nl <= i && i <= nr && (i < l || i > r)) {
			if (!cnt[x]) return 0;
			cnt[x]--;
		}
	}
	if (MID != -1 && cnt[MID] % 2 == 0) return 0;
	if (MID != -1) cnt[MID]--;
	for (int i = 0; i < n; i++) {
		if (cnt[i] & 1) return 0;
	}
	return 1;
}

int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[i] & 1) {
			if (MID != -1) {
				printf("0\n");
				return 0;
			}
			MID = i;
		}
	}
	if (n % 2 == 0 && MID != -1) {
		printf("0\n");
		return 0;
	}
	int L = 0, R = n - 1;
	while (L < R && a[L] == a[R]) L++, R--;
	if (L >= R) {
		printf("%I64d\n", 1ll * n * (n + 1) / 2);
		return 0;
	}
	if (!check(0, n - 1)) {
		printf("0\n");
		return 0;
	}
	int l = L, r = R;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(L, mid)) r = mid;
		else l = mid + 1;
	}
	long long ans = (L + 1ll) * (n - l);
	l = L, r = R;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid, R)) l = mid;
		else r = mid - 1;
	}
	ans += 1ll * (n - R) * (l - L);
	printf("%I64d\n", ans);
	return 0;
}