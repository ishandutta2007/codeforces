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

int n, m, k;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d", &n, &m, &k);
	int a = n, b = m;
	int g = gcd(a, k);
	a /= g;
	k /= g;
	g = gcd(b, k);
	b /= g;
	k /= g;
	if (k != 1 && k != 2) {
		puts("NO");
		return 0;
	}
	if (k == 1) {
		if (a < n)
			a *= 2;
		else if (b < m)
			b *= 2;
		else {
			puts("NO");
			return 0;
		}
	}
	printf("YES\n%d %d\n%d %d\n%d %d\n", 0, 0, 0, b, a, 0);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}