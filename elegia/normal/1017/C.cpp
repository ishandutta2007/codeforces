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

int n, b;
int p[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	b = sqrt(n);
	while (b* b < n)
		++b;
	int i;
	for (i = 1; i + b - 1 <= n; i += b) {
		for (int j = 0; j < b; ++j)
			p[i + j] = i + b - j - 1;
	}
	int c = n;
	for (; i <= n; ++i)
		p[i] = c--;
	for (int i = 1;i <= n; ++i) {
		printf("%d ", p[i]);
	}

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}