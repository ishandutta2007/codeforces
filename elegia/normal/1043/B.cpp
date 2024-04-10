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

const int N = 1010;

int n;
int a[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = n; i; --i)
		a[i] -= a[i - 1];
	vector<int> ans;
	for (int k = 1; k <= n; ++k) {
		bool flag = true;
		for (int i = k + 1; i <= n; ++i)
			if (a[i] != a[i - k]) {
				flag = false;
				break;
			}
		if(flag)
			ans.push_back(k);
	}
	printf("%lu\n", ans.size());
	for (int l : ans)
		printf("%d ", l);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}