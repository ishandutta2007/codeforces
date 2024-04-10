#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
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

const int N = 100010;

bool vis[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n;
	scanf("%d", &n);
	int mex = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (a > mex) {
			printf("%d\n", i + 1);
			return 0;
		}
		vis[a] = true;
		while (vis[mex])
			++mex;
	}
	puts("-1");

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}