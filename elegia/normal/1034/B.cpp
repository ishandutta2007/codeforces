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

int tb[6][6] = {
		{},//1 2  3  4  5
		{0, 0, 0, 0, 2, 4},
		{0, 0, 0, 4, 8, 10},
		{0, 0, 0, 8, 12, 14},
		{0, 0, 0, 0, 16, 20},
		{0, 0, 0, 0, 0,  24}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n, m;
	ll ans = 0;
	scanf("%d%d", &n, &m);
	if (n > m)
		swap(n, m);
	if (n == 1) {
		ans = n * (ll) m;
		n %= 6;
		m %= 6;
		ans -= n * m;
		ans += tb[n][m];
	} else if (n == 2) {
		if (m == 1 || m == 2)
			ans = 0;
		else if (m == 3)
			ans = 4;
		else if (m == 7)
			ans = 12;
		else
			ans = m * 2;
	} else {
		ans = n * (ll)m - (n & m & 1);
	}
	printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}