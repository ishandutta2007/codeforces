#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <random>
#include <limits>
#include <numeric>
#include <functional>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010;

int xm, ym, zm, n, m, k;
int xl, xr, yl, yr, zl, zr;
int ans[N];
int fw[N];

vector<pair<int, int> > pt[N * 2];
vector<pair<pair<int, int>, int> > qry[N * 2];

int conv(int l, int r, int v);
int lowBit(int k) { return k & -k; }
void ch(int k, int x);
int qmax(int k);
int sgn(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

int main() {
	scanf("%d%d%d%d%d%d", &xm, &ym, &zm, &n, &m, &k);
	xl = xm;
	yl = ym;
	zl = zm;
	for (int i = 1; i <= n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		xl = min(xl, x);
		xr = max(xr, x);
		yl = min(yl, y);
		yr = max(yr, y);
		zl = min(zl, z);
		zr = max(zr, z);
	}
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (xl <= x && x <= xr &&
				yl <= y && y <= yr &&
				zl <= z && z <= zr) {
			puts("INCORRECT");
			return 0;
		}
		x = conv(xl, xr, x);
		y = conv(yl, yr, y);
		z = conv(zl, zr, z);
		pt[x + xm].emplace_back(y, z);
	}
	puts("CORRECT");
	for (int i = 1; i <= k; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x = conv(xl, xr, x);
		y = conv(yl, yr, y);
		z = conv(zl, zr, z);
		if (x == 0 && y == 0 && z == 0) {
			ans[i] = 1;
			continue;
		}
		qry[x + xm].emplace_back(make_pair(y, z), i);
	}

	for (int sx = -1; sx <= 1; ++sx) {
		if (sx == 0) continue;
		for (int sy = -1; sy <= 1; ++sy) {
			if (sy == 0) continue;
			for (int sz = -1; sz <= 1; ++sz) {
				if (sz == 0) continue;
				fill(fw, fw + N, numeric_limits<int>::max());
				for (int rx = 0; rx <= xm; ++rx) {
					int x = rx * sx;
					for (auto po : pt[x + xm]) {
						if (po.first * sy >= 0 && po.second * sz >= 0)
							ch(po.first * sy, po.second * sz);
					}
					for (auto qr : qry[x + xm]) {
						int y = qr.first.first * sy, z = qr.first.second * sz;
						if (y < 0 || z < 0)
							continue;
//						printf("%d: %d %d\n", qr.second, qmax(y), z);
						if (qmax(y) <= z)
							ans[qr.second] = -1;
					}
				}
			}
		}
	}

	for (int i = 1; i <= k; ++i) {
		if (ans[i] == 1)
			puts("OPEN");
		else if (ans[i] == 0)
			puts("UNKNOWN");
		else
			puts("CLOSED");
	}
	return 0;
}

void ch(int k, int x) {
//	printf("CHANGE %d %d\n", k, x);
	++k;
	for (; k <= ym + 1; k += lowBit(k))
		fw[k] = min(fw[k], x);
}

int qmax(int k) {
//	printf("QRY %d\n", k);
	++k;
	int ret = numeric_limits<int>::max();
	for (; k; k -= lowBit(k))
		ret = min(ret, fw[k]);
	return ret;
}

int conv(int l, int r, int x) {
	if (x < l)
		return x - l;
	if (x <= r)
		return 0;
	return x - r;
}