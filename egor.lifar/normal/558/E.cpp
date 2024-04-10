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


int n, q;
string s;
int d[560001][26];
int mod[560001][26];


void change(int i, int t) {
	d[i][t] = 1;
	while (i / 2 > 0) {
		i /= 2;
		d[i][t] = d[i * 2][t] + d[i * 2 + 1][t];
	}
}


void push(int v, int t, int g) {
	if (mod[v][t] != -1) {
		d[v][t] = mod[v][t] * g;
		mod[v * 2][t] = mod[v][t];
		mod[v * 2 + 1][t] = mod[v][t];
		mod[v][t] = -1;
	}
}


void add(int v, int t, int vl, int vr,  int l, int r, int x) {
	if (vr < l || vl > r) {
		push(v, t, vr - vl + 1);
		return;
	}
	if (l <= vl && vr <= r) {
		mod[v][t] = x;
		push(v, t, vr - vl + 1);
		return;
	}
	push(v, t, vr - vl + 1);
	add(v * 2, t, vl, (vl + vr) / 2, l, r, x);
	add(v * 2 + 1, t, (vl + vr) / 2 + 1, vr, l, r, x);
	d[v][t] = d[v * 2][t] + d[v * 2 + 1][t];
}


int rmq(int v, int t, int vl, int vr, int l, int r) {
	if (vr < l || vl > r) {
		push(v, t, vr - vl + 1);
		return 0;
	}
	if (l <= vl && vr <= r) {
		push(v, t, vr - vl + 1);
		return d[v][t];
	}
	push(v, t, vr - vl + 1);
	int ans = rmq(v * 2, t, vl, (vl + vr) / 2, l, r) + rmq(v * 2 + 1, t, (vl + vr) / 2 + 1, vr, l, r);
	d[v][t] = d[v * 2][t] + d[v * 2 + 1][t];
	return ans;
}


int main() {
	cin >> n >> q >> s;
	int ss = 1;
	while (ss < n) {
		ss *= 2;
	}
	for (int i = 0; i < 2 * ss; i++) {
		for (int j = 0; j < 26; j++) {
			mod[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		change(ss + i, s[i] - 'a');
	}
	for (int i1 = 0; i1 < q; i1++) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		l--;
		r--;
		if (k == 1) {
			int l1 = l;
			for (int i = 0; i < 26; i++) {
				int s = rmq(1, i, 1, ss, l + 1, r + 1);
				add(1, i, 1, ss, l + 1, r + 1, 0);
				if (s != 0) {
					add(1, i, 1, ss, l1 + 1, l1 + s, 1);
					l1 += s;
				}
			}
		} else {
			int l1 = l;
			for (int i = 25; i >= 0; i--) {
				int s = rmq(1, i, 1, ss, l + 1, r + 1);
				add(1, i, 1, ss, l + 1, r + 1, 0);
				if (s != 0) {
					add(1, i, 1, ss, l1 + 1, l1 + s, 1);
					l1 += s;
				}
			}
		}
	}
	//cout << rmq(1, 0, 1, ss, 3, 6) << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if (rmq(1, j, 1, ss, i + 1, i + 1) == 1) {
				cout << char('a' + j);
				break;
			}
		}
	}
	cout << endl;
    return 0;
}