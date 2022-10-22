#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		static char s[1000010]; scanf("%s", s);
		int N = n * m; reverse(s, s + N);
		auto F = [&](int x) -> int {return x < N ? s[x] - '0' : 0;};
		static int ans[1000010]; for (int i = 0; i < N; i++) ans[i] = (N - i + m - 1) / m + min(m, N - i);
		{
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += F(j);
			}
			static int del[1000010]; for (int i = 0; i < n * m; i++) del[i] = 0;
			for (int i = 0; i < N; i++) {
				if (sum == 0) {
					del[i]++;
				}
				sum -= F(i), sum += F(i + m);
			}
			for (int i = N - 1; i >= 0; i--) {
				if (i + m < N) del[i] += del[i + m];
				ans[i] -= del[i];
			}
		}
		{
			static int del[1000010]; for (int i = 0; i < n * m; i++) del[i] = 0;
			for (int rem = 0; rem < m; rem++) {
				int sum = 0;
				for (int j = 0; j < n; j++) {
					sum += F(j * m + rem);
				}
				for (int i = rem; i < N; i += m) {
					if (sum == 0) {
						del[i]++;
						if (i - m >= 0) del[i - m]--;
						// del[i - m + 1]++, del[i + 1]--;
					}
					sum -= F(i), sum += F(i + n * m);
				}
			}
			for (int i = N - 1; i >= 0; i--) {
				if (i + 1 < N) del[i] += del[i + 1];
				ans[i] -= del[i];
			}
			// for (int i = 0; i < N; i++) {
			// 	if (i) del[i] += del[i - 1];
			// 	ans[i] -= del[i];
			// }
		}
		for (int i = N - 1; i >= 0; i--) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}