#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


#define y1 yy1


int n, m, w;
int t[4000002], x1[4000002], y1[4000002], x2[4000002], y2[4000002];
int v[4000002];
long long d[9000002][2];
long long mod[9000002][2];
int ss = 1;


void push(int v, int g, int id) {
	if (mod[v][id] != 0) {
		d[v][id] += 1LL * g * mod[v][id];
		if (v * 2 + 1 < 9000002) {
			mod[v * 2][id] += mod[v][id];
			mod[v * 2 + 1][id] += mod[v][id];
		}
		mod[v][id] = 0;
	} 
}


void add(int v, int l, int r, int vl, int vr, int x, int id) {
	push(v, vr - vl + 1, id);
	if (l > vr || vl > r) {
		return;
	}
	if (l <= vl && vr <= r) {
		mod[v][id] += 1LL * x;
		push(v, vr - vl + 1, id);
		return;
	}
	add(v * 2, l, r, vl, (vl + vr) / 2, x, id);
	add(v * 2 + 1, l, r, (vl + vr) / 2 + 1, vr, x, id);
	d[v][id] = d[v * 2][id] + d[v * 2 + 1][id];
}


long long rmq(int v, int l, int r, int vl, int vr, int id) {
	push(v, vr - vl + 1, id);
	if (l > vr || vl > r) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return d[v][id];
	}
	return rmq(v * 2, l, r, vl, (vl + vr) / 2, id) + rmq(v * 2 + 1, l, r, (vl + vr) / 2 + 1, vr, id);
}



int main() {
	cin >> n >> m >> w;
	while (ss <= n || ss <= m) {
		ss *= 2;
	}
	long long sum = 0;
	for (int i = 0; i < w; i++) {
		scanf("%d %d %d %d %d", &t[i], &x1[i], &y1[i], &x2[i], &y2[i]);
		if (t[i] == 0) {
			scanf("%d", &v[i]);
			sum += 1LL * v[i] * (y2[i] - y1[i] + 1LL) * (x2[i] - x1[i] + 1LL);
			add(1, x1[i], x2[i], 1, ss, 1LL * v[i] * (y2[i] - y1[i] + 1LL), 0);
			add(1, y1[i], y2[i], 1, ss, 1LL * v[i] * (x2[i] - x1[i] + 1LL), 1);
		} else {
			printf("%I64d\n", rmq(1, x1[i], x2[i], 1, ss, 0) + rmq(1, y1[i], y2[i], 1, ss, 1) - sum);
		}
	}
	return 0;
}