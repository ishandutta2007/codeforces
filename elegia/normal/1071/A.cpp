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

const int N = 90010;

int a, b;

bool pred(int x) {
	ll sum = x * (ll)(x + 1) / 2;
	int ra = a;
	for (int i = x; i; --i) {
		if (ra >= i) {
			ra -= i;
			sum -= i;
		}
	}
	return sum <= b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif


	scanf("%d%d", &a, &b);

	int l = 0, r = N - 1;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (pred(mid))
			l = mid;
		else
			r = mid - 1;
	}
	vector<int> va, vb;
	ll sum = l * (ll)(l + 1) / 2;
	int ra = a;
	for (int i = l; i; --i) {
		if (ra >= i) {
			ra -= i;
			sum -= i;
			va.push_back(i);
		} else
			vb.push_back(i);
	}
	printf("%lu\n", va.size());
	for (int x : va)
		printf("%d ", x);
	putchar('\n');
	printf("%lu\n", vb.size());
	for (int x : vb)
		printf("%d ", x);
	putchar('\n');


#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}