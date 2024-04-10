#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n;
int mod[2 * 1000 * 1000], d[2 * 1000 * 1000];
int a[2 * 1000 * 1000];


void push(int v) {
	if (mod[v] > 0) {
		d[v] = mod[v];
		mod[v * 2] = mod[v];
		mod[v * 2 + 1] = mod[v];
		mod[v] = 0;
	}
}


int rmq(int vl, int vr, int v, int l, int r) {
	if (vr < l || vl > r) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		push(v);
		return d[v];
	}
	push(v);
	int f = max(rmq(vl, (vl + vr) / 2, v * 2, l, r), rmq((vl + vr) / 2 + 1, vr, v * 2 + 1, l, r));
	d[v] = max(d[v * 2], d[v * 2 + 1]);
	return f;
}


void add(int vl, int vr, int v, int l, int r, int x) {
	if (vr < l || vl > r) {
		return;
	}
	if (l <= vl && vr <= r) {
		mod[v] = x;
		push(v);
		return;
	}
	push(v);
	add(vl, (vl + vr) / 2, v * 2, l, r, x); add((vl + vr) / 2 + 1, vr, v * 2 + 1, l, r, x);
	d[v] = max(d[v * 2], d[v * 2 + 1]);
}


int r[2 * 1000 * 1000];
int l[2 * 1000 * 1000];


int main() {
	cin >> n;
	int s = 1;
	while (s < n) {
		s *= 2;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		while (!v.empty() && a[v.back()] >= a[i]) {
			v.pop_back();
		}
		l[i] = (v.empty() ? -1: v.back());
		v.push_back(i);
	}
	v.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!v.empty() && a[v.back()] >= a[i]) {
			v.pop_back();
		}
		r[i] = (v.empty() ? n: v.back());
		v.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		int ll = l[i] + 1;
		int rr = r[i] - 1;
		if (rmq(1, s, 1, rr - ll + 1, rr - ll + 1) > a[i]) {
			continue;
		}
		int l = 0;
		int r = rr - ll;
		while (l != r) {
			int m = (l + r) / 2;
			if (rmq(1, s, 1, m + 1, m + 1) > a[i]) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		add(1, s, 1, l + 1, rr - ll + 1, a[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", rmq(1, s, 1, i + 1, i + 1));
	}
	printf("\n");
	return 0;	
}