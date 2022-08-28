#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010;

int n, x1, y1, x2, y2, x3, y3, x4, y4, cnt;
int x[N], y[N];
bool f[N];

bool tst(int a, int b);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &x[i], &y[i]);
	if (tst(1, 2) || tst(2, 3) || tst(1, 3))
		puts("YES");
	else
		puts("NO");
	return 0;
}

bool tst(int a, int b) {
	fill(f + 1, f + n + 1, true);
	f[a] = f[b] = false;
	x1 = x[a];
	y1 = y[a];
	x2 = x[b];
	y2 = y[b];
	cnt =0;
	for (int i = 1; i <= n; ++i) {
		if ((x[i] - x1) * (ll)(y2 - y1) - (x2 - x1) * (ll)(y[i] - y1) == 0 || !f[i])
			f[i] = false;
		else if (cnt == 0) {
			++cnt;
			x3 = x[i];
			y3 = y[i];
		} else {
			x4 = x[i];
			y4 = y[i];
			++cnt;
		}
	}
	if (cnt <= 1)
		return true;
	for (int i = 1; i <= n; ++i) {
		if (f[i]) {
			if ((x[i] - x3) * (ll)(y4 - y3) - (x4 - x3) * (ll)(y[i] - y3) != 0) {
				return false;
			}
		}
	}
	return true;
}