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

const int N = 1010;

int n;
pair<int, int> ar[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		ar[i].first = a + b + c + d;
		ar[i].second = n - i + 1;
	}
	stable_sort(ar + 1, ar + n + 1, greater<pair<int, int> >());
	for (int i = 1; i <= n; ++i)
		if (ar[i].second == n) {
			printf("%d\n", i);
		}

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}