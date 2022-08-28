#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <random>
#include <limits>
#include <numeric>
#include <functional>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 40;

bool f[N];

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; ++i) {
		puts("1");
		fflush(stdout);
		int g;
		scanf("%d", &g);
		if (g == 0) {
			return 0;
		}
		if (g == -1)
			f[i] = true;
	}
	int l = 1, r = m, i = 1;
	while (l < r) {
		int mid = (l + r) / 2;
		printf("%d\n", mid);
		fflush(stdout);
		int g;
		scanf("%d", &g);
		if (g == 0) {
			return 0;
		}
		if (f[i])
			g = -g;
		if (g == 1) {
			l = mid + 1;
		} else
			r = mid - 1;
		if (++i == n + 1)
			i = 1;
	}
	printf("%d\n", l);
	fflush(stdout);
	return 0;
}