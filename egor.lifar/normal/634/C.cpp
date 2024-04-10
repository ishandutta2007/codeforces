#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;


int n, k, q;
int a, b;
int d[1000001];
int d1[1000001];


void change(int i, int x) {
	d[i] += x;
	d[i] = min(d[i], a);
	while (i / 2 > 0) {
		i /= 2;
		d[i] = d[i * 2] + d[i * 2 + 1];
	}
}


void change1(int i, int x) {
	d1[i] += x;
	d1[i] = min(d1[i], b);
	while (i / 2 > 0) {
		i /= 2;
		d1[i] = d1[i * 2] + d1[i * 2 + 1];
	}
}


int rmq(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return d[v];
	}
	return rmq(v * 2, vl, (vl + vr) / 2, l, r) + rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


int rmq1(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return d1[v];
	}
	return rmq1(v * 2, vl, (vl + vr) / 2, l, r) + rmq1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


int main() {
	cin >> n >> k >> a >> b >> q;
	int ss = 1;
	while (ss < n) {
		ss *= 2;
	}
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int dd, aa;
			scanf("%d %d", &dd, &aa);
			dd--;
			change(dd + ss, aa);
			change1(dd + ss, aa);
		} else {
			int p;
			scanf("%d", &p);
			p--;
			int ans = 0;
			if (p != 0) {
				ans += rmq1(1, 1, ss, 1, p);
			}
			if (p + k != n) {
				ans += rmq(1, 1, ss, p + k + 1, n);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}