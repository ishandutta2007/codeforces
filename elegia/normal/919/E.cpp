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

int a, b, p;
ll x;

void exGcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1;
		y = 0;
		return;
	}
	exGcd(b, a % b, y, x);
	y -= a / b * x;
}

int inv(int a, int p) {
	int x, y;
	exGcd(a, p, x, y);
	if (x < 0)
		x += p;
	return x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d%lld", &a, &b, &p, &x);
	int ord = 0, tmp = 1;
	do {
		++ord;
		tmp = tmp * (ll)a % p;
	} while (tmp != 1);
	int in = inv(a, p);
	ll loop = ord * (ll)p;
	ll ans = x / loop * ord;
	x %= loop;
	tmp = b;
	for (int i = 0; i < ord; ++i) {
		ll q2 = inv(p, ord) * (ll)p % loop, q1 = inv(ord, p) * (ll)ord % loop;
		ll index = (tmp * (ll)q1 + i * (ll)q2) % loop;
		if (index == 0)
			index = loop;
		if (index <= x)
			++ans;
		tmp = tmp * (ll)in % p;
	}
	printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}