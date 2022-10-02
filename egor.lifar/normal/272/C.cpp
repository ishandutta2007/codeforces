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
#include <unordered_map>


using namespace std;


int n;
long long a[100001];
int ss = 1;
long long d[500001], mod[500001];


void change(int i, long long x) {
	d[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		d[i] = max(d[i * 2], d[i * 2 + 1]);
	}
}


void push(int v, long long g) {
	if (mod[v] != 0) {
		mod[v * 2] = mod[v];
		mod[v * 2 + 1] = mod[v];
		d[v] = mod[v];
		mod[v] = 0;
	}
}


void add(int v, int vl, int vr, int l, int r, long long x) {
	if (vr < l || vl > r) {
		return;
	}
	if (l <= vl && vr <= r) {
		mod[v] = x;
		push(v, vr - vl + 1);
		return;
	}
	push(v, vr - vl + 1);
	int vm = (vl + vr) / 2;
	add(v * 2, vl, vm, l, r, x);
	add(v * 2 + 1, vm + 1, vr, l, r, x);
	d[v] = max(d[v * 2], d[v * 2 + 1]);
}


long long rmq(int v, int vl, int vr, int l, int r) {
	if (vr < l || vl > r) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		push(v, vr - vl + 1);
		return d[v];
	}
	push(v, vr - vl + 1);
	int vm = (vl + vr) / 2;
	long long s = max(rmq(v * 2, vl, vm, l, r), rmq(v * 2 + 1, vm + 1, vr, l, r)); 
	d[v] = max(d[v * 2], d[v * 2 + 1]);
	return s;
}



int main() {
	cin >> n;
	while (ss < n) {
		ss *= 2;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		change(ss + i, a[i]);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int w, h;
		scanf("%d %d", &w, &h);
		long long hh = rmq(1, 1, ss, 1, w);
		cout << hh << endl;
		add(1, 1, ss, 1, w, hh + h);
	}
    return 0;
}