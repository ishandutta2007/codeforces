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

int n;
char s[10], seq[1010];

bool ask(int x1, int y1, int x2, int y2) {
	if (x1 < 1 || y1 < 1)
		return false;
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	scanf("%s", s);
	return s[0] == 'Y';
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	int cnt = 2 * (n - 1), cx = n, cy = n;
	for (int rep = 1; rep < n; ++rep)
		if (ask(1, 1, cx - 1, cy)) {
			--cx;
			seq[cnt--] = 'D';
		} else {
			--cy;
			seq[cnt--] = 'R';
		}
	cnt = 0;
	cx = 1;
	cy = 1;
	for (int rep = 1; rep < n; ++rep) {
		if (ask(cx, cy + 1, n, n)) {
			++cy;
			seq[++cnt] = 'R';
		} else {
			++cx;
			seq[++cnt] = 'D';
		}
	}
	printf("! %s", seq + 1);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}