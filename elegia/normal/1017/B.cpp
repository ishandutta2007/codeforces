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
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010;

char a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n;
	scanf("%d%s%s", &n, a + 1, b + 1);
	int c00 = 0, c01 = 0, c11 = 0, c10 = 0;
	for (int i = 1; i <= n; ++i)
		if (b[i] == '0') {
			if (a[i] == '1')
				++c10;
			else
				++c00;
		} else if (b[i] == '1') {
			if (a[i] == '1')
				++c11;
			else
				++c01;
		}
	printf("%lld\n", c00 * (ll)c10 + c00 * (ll)c11 + c01 * (ll)c10);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}