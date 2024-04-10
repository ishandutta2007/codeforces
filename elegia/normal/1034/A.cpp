#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <bitset>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 300010, X = 15000010;

int n, pc;
int a[N], pr[X / 10], cnt[X];
int fc[X];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int g = accumulate(a + 1, a + n + 1, 0, gcd);
	for (int i = 1; i <= n; ++i)
		a[i] /= g;
	if (count(a + 1, a + n + 1, 1) == n) {
		puts("-1");
		return 0;
	}
	for (int x = 2; x < X; ++x) {
		if (!fc[x]) {
			pr[++pc] = x;
			fc[x] = x;
		}
		for (int i = 1; x * pr[i] < X; ++i) {
			fc[x * pr[i]] = pr[i];
			if (x % pr[i] == 0)
				break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int x = a[i], lst = 0;
		while (x != 1) {
			int pp = fc[x];
			if (lst != pp)
				++cnt[pp];
			lst = pp;
			x /= pp;
		}
	}
	printf("%d\n", n - *max_element(cnt + 1, cnt + X));

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}