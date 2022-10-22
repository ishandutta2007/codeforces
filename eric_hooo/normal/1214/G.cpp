#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int B = 32;

ull a[2010][B];
int cnt[2010];
int n, m, q;
int gnum[67];
int pnt[1 << 16];

int LowBit(ull x) {
	return gnum[(x & -x) % 67];
}

int PopCount(ull x) {
	return pnt[x & 65535] + pnt[x >> 16 & 65535] + pnt[x >> 32 & 65535] + pnt[x >> 48];
}

struct cmp {
	bool operator () (const int &x, const int &y) {
		return cnt[x] != cnt[y] ? cnt[x] < cnt[y] : x < y;
	}
};

set <int, cmp> S;
set <int> bad;

bool IsSub(int x, int y) {
	if (x == -1 || y == -1) return 1;
	int qwq = 0, pwp = 0;
	for (int i = 0; i < B; i++) {
		if (a[x][i] & ~a[y][i]) qwq = 1;
		if (~a[x][i] & a[y][i]) pwp = 1;
	}
	return !qwq || !pwp;
}

void Insert(int x) {
	auto it = S.lower_bound(x);
	int suc = it == S.end() ? -1 : *it, pre = it == S.begin() ? -1 : *--it;
	if (!IsSub(pre, suc)) bad.erase(pre);
	if (!IsSub(pre, x)) bad.insert(pre);
	if (!IsSub(x, suc)) bad.insert(x);
	S.insert(x);
}

void Erase(int x) {
	S.erase(x);
	auto it = S.lower_bound(x);
	int suc = it == S.end() ? -1 : *it, pre = it == S.begin() ? -1 : *--it;
	if (!IsSub(pre, x)) bad.erase(pre);
	if (!IsSub(x, suc)) bad.erase(x);
	if (!IsSub(pre, suc)) bad.insert(pre);
}

void Query() {
	if (bad.size() == 0) {
		printf("-1\n");
		return ;
	}
	int x = *bad.begin(), y = *S.upper_bound(x);
	if (x > y) swap(x, y);
	int p = -1, q = -1;
	for (int i = 0; i < B; i++) {
		if (a[x][i] & ~a[y][i]) p = i << 6 | LowBit(a[x][i] & ~a[y][i]);
		if (~a[x][i] & a[y][i]) q = i << 6 | LowBit(~a[x][i] & a[y][i]);
	}
	if (p > q) swap(p, q);
	printf("%d %d %d %d\n", x + 1, p + 1, y + 1, q + 1);
}

int main() {
	for (int i = 0; i < (1 << 16); i++) {
		pnt[i] = pnt[i >> 1] + (i & 1);
	}
	for (int i = 0; i < 64; i++) {
		gnum[(1ull << i) % 67] = i;
	}
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		S.insert(i);
	}
	while (q--) {
		int x, l, r; scanf("%d%d%d", &x, &l, &r), x--, l--, r--;
		Erase(x);
		int ll = l >> 6, rr = r >> 6, lt = l & 63, rt = r & 63;
		for (int i = ll + 1; i <= rr - 1; i++) {
			a[x][i] ^= -1;
		}
		if (ll == rr) a[x][ll] ^= (1ull << rt) - (1ull << lt) ^ (1ull << rt);
		else {
			a[x][ll] ^= -1, a[x][ll] ^= (1ull << lt) - 1;
			a[x][rr] ^= (1ull << rt) - 1, a[x][rr] ^= 1ull << rt;
		}
		cnt[x] = 0;
		for (int i = 0; i < B; i++) {
			cnt[x] += PopCount(a[x][i]);
		}
		Insert(x);
		Query();
	}
	return 0;
}