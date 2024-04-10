#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 100005;
int n;
int query(int i) {
	if (i < 1 || i > n) return 2e9;
	printf("? %d\n", i);
	fflush(stdout);
	int t; scanf("%d", &t);
	return t;
}

int main() {
	scanf("%d", &n);
	int l = 0, r = n;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (query(mid) < query(mid + 1)) r = mid;
		else l = mid;
	}
	printf("! %d\n", r);
	return 0;
}