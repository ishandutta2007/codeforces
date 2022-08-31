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

int qry(int pos) {
	pos %= n;
	if (pos <= 0)
		pos += n;
	printf("? %d\n", pos);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

int delt(int pos) {
	int a1, a2;
	a1 = qry(pos);
	a2 = qry(pos + n / 2);
	if (a1 == a2) {
		pos %= n;
		if (pos <= 0)
			pos += n;
		printf("! %d\n", pos);
		exit(0);
	}
	return a1 - a2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	if (n % 4) {
		puts("! -1");
		return 0;
	}
	int l, r;
	if (delt(1) < 0) {
		l = 1;
		r = n / 2 + 1;
	} else {
		l = n / 2 + 1;
		r = n + 1;
	}
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (delt(mid) < 0)
			l = mid;
		else
			r = mid;
	}

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}