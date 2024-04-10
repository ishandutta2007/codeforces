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


using namespace std;


int n, m;
vector<int> v[200001];
int a[200001];
int l[200001];
int r[200001];
int l1[200001];
int r1[200001];
int f[200001];
int t = 0;
int t1 = 0;
int used[200001];
long long d[1000001][2];
long long mod[1000001][2];


void change(int i, int t, int x) {
	d[i][t] = x;
	while (i / 2 > 0) {
		i /= 2;
		d[i][t] = d[i * 2][t] + d[i * 2 + 1][t];
	}
}


void push(int v, int t, long long g) {
	if (mod[v][t] != 0) {
		mod[v * 2][t] += mod[v][t];
		mod[v * 2 + 1][t] += mod[v][t];
		d[v][t] += mod[v][t] * g;
		mod[v][t] = 0;
	}
}


void add(int v, int t, int vl, int vr, int l, int r, int x) {
	if (vr < l || vl > r) {
		return;
	}
	if (l <= vl && vr <= r) {
		mod[v][t] += x;
		push(v, t, vr - vl + 1);
		return;
	}
	push(v, t, vr - vl + 1);
	int vm = (vl + vr) / 2;
	add(v * 2, t, vl, vm, l, r, x);
	add(v * 2 + 1, t, vm + 1, vr, l, r, x);
	d[v][t] = d[v * 2][t] + d[v * 2 + 1][t];
}


long long rmq(int v, int t, int vl, int vr, int l, int r) {
	if (vr < l || vl > r) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		push(v, t, vr - vl + 1);
		return d[v][t];
	}
	push(v, t, vr - vl + 1);
	int vm = (vl + vr) / 2;
	long long s = rmq(v * 2, t, vl, vm, l, r) + rmq(v * 2 + 1, t, vm + 1, vr, l, r); 
	d[v][t] = d[v * 2][t] + d[v * 2 + 1][t];
	return s;
}


void dfs(int u) {
	if (used[u] % 2 == 1) {
		t++;
		f[u] = t;
		l[u] = t;
		if ((int)v[u].size() > 1 || (u == 0 && (int)v[u].size() >= 1)) {
			l1[u] = t1 + 1;
		} else {
			l1[u] = -1;
		}
	} else {
		t1++;
		f[u] = t1;
		l1[u] = t1;
		if ((int)v[u].size() > 1 || (u == 0 && (int)v[u].size() >= 1)) {
			l[u] = t + 1;
		} else {
			l[u] = -1;
		}
	}
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			used[h] = used[u] + 1;
			dfs(h);
		}
	}
	r[u] = t;
	r1[u] = t1;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	used[0] = 1;
	dfs(0);
	int ss = 1;
	while (ss < n) {
		ss *= 2;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] % 2 == 1) {
			change(ss + f[i] - 1, 0, a[i]);
		} else {
			change(ss + f[i] - 1, 1, a[i]);
		}
	}
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, val;
			scanf("%d %d", &x, &val);
			if (used[x - 1] % 2 == 1) {
				if (l[x - 1] != -1) { 
				//	cout << l[x - 1] << endl;
					add(1, 0, 1, ss, l[x - 1], r[x - 1], val);
				} 
				if (l1[x - 1] != -1) {
					add(1, 1, 1, ss, l1[x - 1], r1[x - 1], -val);
				}
			} else {
				if (l1[x - 1] != -1) {
					add(1, 1, 1, ss, l1[x - 1], r1[x - 1], val);
				}
				if (l[x - 1] != -1) { 
					add(1, 0, 1, ss, l[x - 1], r[x - 1], -val);
				}
			}
		} else {
			int x;
			scanf("%d", &x);
		//cout << 1 - (used[x - 1] % 2LL) << endl;
			printf("%d\n", (int)rmq(1, 1 - (used[x - 1] % 2LL), 1, ss, f[x - 1], f[x - 1]));
		}
	}
    return 0;
}