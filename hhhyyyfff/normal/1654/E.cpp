#include <bits/stdc++.h>

using namespace std;
#define D 31000000
#define M 300
#define K 340

int n, a[100000], b[100000], f[100000];
int lst[D * 2], tim[D * 2], cnt[200000], pos[200000], ans = 2;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < D * 2; ++i) tim[i] = INT_MAX;
	for (int i = -M; i <= M; ++i) {
		for (int j = 1; j < n; ++j) b[j] = a[j] - a[j - 1] - i;
		f[0] = 1;
		lst[D] = 0;
		tim[D] = i;
		for (int j = 1, s = 0; j < n; ++j) {
			s += b[j];
			if (tim[s + D] == i) ans = max(ans, f[j] = f[lst[s + D]] + 1);
			else {
				f[j] = 1;
				tim[s + D] = i;
			}
			lst[s + D] = j;
		}
	}
	for (int i = 0; i < n; ++i) {
		int l = max(0, i - K), r = min(n - 1, i + K);
		for (int j = l; j <= r; ++j) {
			if (i == j) continue;
			if ((a[i] - a[j]) % (i - j) != 0) continue;
			int t = (a[i] - a[j]) / (i - j);
			if (pos[t + 100000] != i) {
				pos[t + 100000] = i;
				cnt[t + 100000] = 2;
			} else ans = max(ans, ++cnt[t + 100000]);
		}
	}
	printf("%d\n", n - ans);
	return 0;
}