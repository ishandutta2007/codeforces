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

const int N = 200010, LGN = 18, X = 1 << LGN, P = 1000000007;

int n, q;
int a[N], w[N];
int fw[N];
ll wfw[X];

int lowBit(int k) { return k & -k; }
ll lq(int k);
void lch(int k, int x);
int bound(ll v);
int qr(int k);
void ch(int k, int x);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] -= i;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
		ch(i, w[i] * (ll)a[i] % P);
		lch(i, w[i]);
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < 0) {
			x = -x;
			int delt = y - w[x];
			w[x] = y;
			lch(x, delt);
			if ((delt %= P) < 0)
				delt += P;
			ch(x, delt * (ll)a[x] % P);
		} else {
			int pos = bound(lq(x - 1) + (lq(y) - lq(x - 1) + 1) / 2);
			int ans = ((qr(y) - qr(pos)) % P - (lq(y) - lq(pos)) % P * a[pos] % P) % P;
			if (ans < 0)
				ans += P;
			ans = (ans + (lq(pos - 1) - lq(x - 1)) % P * a[pos] % P - (qr(pos - 1) - qr(x - 1)) % P) % P;
			if (ans < 0)
				ans += P;
			printf("%d\n", ans);
		}
	}

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

int qr(int k) {
	int ret = 0;
	for (; k; k -= lowBit(k))
		if ((ret += fw[k]) >= P)
			ret -= P;
	return ret;
}

void ch(int k, int x) {
	for (; k <= n; k += lowBit(k))
		if ((fw[k] += x) >= P)
			fw[k] -= P;
}

ll lq(int k) {
	ll ret = 0;
	for (; k; k -= lowBit(k))
		ret += wfw[k];
	return ret;
}

void lch(int k, int x) {
	for (; k < X; k += lowBit(k))
		wfw[k] += x;
}

int bound(ll x) {
	int ret = 0;
	for (int k = LGN - 1; k >= 0; --k)
		if (x > wfw[ret | (1 << k)])
			x -= wfw[ret |= 1 << k];
	return ret + 1;
}