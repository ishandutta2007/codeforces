#include <bits/stdc++.h>
using namespace std;

const int B = 316;
const int N = 100000;

int n;
int a[100010];
int cnt[200010];
int owo[70000000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int r = min(n, i + B);
		for (int j = i + 1; j < r; j++) {
			if (abs(a[j] - a[i]) % (j - i) == 0) {
				int x = (a[j] - a[i]) / (j - i);
				cnt[N + x]++;
				ans = max(ans, cnt[N + x] + 1);
			}
		}
		for (int j = i + 1; j < r; j++) {
			if (abs(a[j] - a[i]) % (j - i) == 0) {
				int x = (a[j] - a[i]) / (j - i);
				cnt[N + x]--;
			}
		}
	}
	int lim = 0; while (lim * (B - 1) <= N) lim++;
	int Base = lim * (n - 1) + N;
	for (int d = -lim; d <= lim; d++) {
		for (int i = 0; i < n; i++) {
			int x = a[i] - i * d;
			owo[Base + x]++;
			ans = max(ans, owo[Base + x]);
		}
		for (int i = 0; i < n; i++) {
			int x = a[i] - i * d;
			owo[Base + x]--;
		}
	}
	printf("%d\n", n - ans);
	return 0;
}