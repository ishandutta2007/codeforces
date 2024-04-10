#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <random>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1000010;

char a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n;
	scanf("%d%s%s", &n, a + 1, b + 1);
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] != b[i]) {
			if (a[i + 1] != b[i + 1]) {
				if (a[i] != a[i + 1]) {
					++ans;
					a[i + 1] = a[i];
				} else
					++ans;
			} else
				++ans;
		}
	}
	if (a[n] != b[n])
		++ans;
	printf("%d\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}