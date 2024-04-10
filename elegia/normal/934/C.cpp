#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <limits>
#include <numeric>
#include <iostream>

#ifdef LBT_DEBUG
#define LOG(FMT...) fprintf(stderr, "[LOG MESSAGE]: " FMT)
#define OUT(X) std::cerr << "[LOG #" #X "]: " << X << std::endl
#else
#define LOG(FMT...)
#define OUT(X)
#endif

typedef long long ll;

const int N = 2010;

int a[N];
int f1[N], f2[N], g1[N], g2[N], h1[N], h2[N];

int main() {
#ifdef LBT_DEBUG
	freopen("test.in", "r", stdin);
#endif
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		if (a[i] == 1) {
			f1[i] = f1[i - 1] + 1;
			f2[i] = f2[i - 1];
		} else {
			f1[i] = f1[i - 1];
			f2[i] = std::max(f1[i - 1], f2[i - 1]) + 1;
		}
	for (int i = n; i; --i)
		if (a[i] == 2) {
			g2[i] = g2[i + 1] + 1;
			g1[i] = g1[i + 1];
		} else {
			g2[i] = g2[i + 1];
			g1[i] = std::max(g2[i + 1], g1[i + 1]) + 1;
		}
	for (int i = 1; i <= n; ++i) {
		int c1 = 0;
		h1[i - 1] = h2[i - 1] = 0;
		for (int j = i; j <= n; ++j) {
			if (a[j] == 2) {
				h2[j] = h2[j - 1] + 1;
				h1[j] = h1[j - 1];
			} else {
				++c1;
				h2[j] = h2[j - 1];
				h1[j] = std::max(h2[j - 1], h1[j - 1]) + 1;
			}
			ans = std::max(ans, std::max(std::max(f1[i - 1] + c1 + g1[j + 1],
			                                      f1[i - 1] + h2[j] + g2[j + 1]),
			                             std::max(f2[i - 1] + h2[j] + g2[j + 1],
			                                      f1[i - 1] + h1[j] + g2[j + 1])));
		}

	}
	printf("%d\n", ans);
	return 0;
}