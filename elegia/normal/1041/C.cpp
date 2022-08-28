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

const int N = 200010;

int n, m, d;
int ans[N];
pair<int, int> a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	int l = 1, ml = 1, mr = 1;
	for (int i = 1; i <= n; ++i) {
		while (a[i].first - a[l].first > d)
			++l;
		if (i - l > mr - ml) {
			ml = l;
			mr = i;
		}
	}
	int k = mr - ml + 1;
	printf("%d\n", k);
	for (int i = 1; i <= n; ++i) {
		ans[a[i].second] = ((ml - i) % k + k) % k + 1;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}