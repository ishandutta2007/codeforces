#include <cstdio>
#include <cstring>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
typedef long long LL;

const int maxN = ((int)2e5 + 233) << 1;
const int maxL = 1e9 + 233;
int n, len;
int a[maxN], b[maxN];

int abs(int x) { return x < 0 ? -x : x; }

int getd(int x, int y) {
	return std::min({abs(x - y), x + len - y, y + len - x});
}

LL c[maxN * 3], d[maxN];

bool check(int limit) {
	int L = 1, R = 3 * n;
	for(int i = 1; i <= n; ++i) {
		int lb = std::lower_bound(c + 1, c + 3*n + 1, d[i] - (LL)limit) - c,
			rb = std::upper_bound(c + 1, c + 3*n + 1, d[i] + (LL)limit) - c - 1;
		++L; ++R;
		L = std::max(L, lb); R = std::min(R, rb);
		if(L > R) return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &len);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	std::sort(a + 1, a + n + 1); std::sort(b + 1, b + n + 1);
	int L = 0, R = len / 2;
	for(int i = 1; i <= n; ++i) c[i] = b[i], c[i + n] = b[i] + len, c[i + n + n] = b[i] + (LL)len + (LL)len;
	for(int i = 1; i <= n; ++i) d[i] = a[i] + len;
	while(L < R) {
		int M = (L + R) >> 1;
		if(check(M)) R = M;
		else L = M + 1;
	}
	printf("%d\n", L);
	return 0;
}