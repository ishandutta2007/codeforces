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

using namespace std;


#define INF 1000000000


int n, m;
int a[100001];
int t[100001];
int tl[100001], tr[100001];
int d[400001];


void change(int i, int x) {
	d[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		d[i] = max(d[i * 2], d[i * 2 + 1]);
	}
}



int rmq(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return d[v];
	}
	return max(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < n - 1; j++) {
		t[j] = abs(a[j + 1] - a[j]);
	}
	int ss = 1;
	while (ss < n) {
		ss *= 2;
	}
	for (int i = 0; i < n - 1; i++) {
		change(ss + i, t[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int l = i;
		int r = n - 2;
		while (l != r) {
			int mm = (l + r + 1) / 2;
			if (rmq(1, 1, ss, i + 1, mm + 1) > t[i]) {
				r = mm - 1;
			} else {
				l = mm;
			}
		}
		tl[i] = l;        
		l = i - 1;
		r = 0;
		///cout << i + 1 << endl;
		while (l > r) {
			int mm = (l + r) / 2;
			if (rmq(1, 1, ss, mm + 1, i) >= t[i]) {
				r = mm + 1;
			} else {
				l = mm;
			}
		}
		//cout << i + 1 << endl;
		if (t[l] >= t[i]) {
			l++;
		}
		tr[i] = l;
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		long long ans = 0;
		for (int j = l; j < r; j++) {
			int g = j - max(tr[j], l) + 1;
			int g1 = min(r - 1, tl[j]) - j + 1;
			//cout << min(r, tl[j]) << endl;
			ans += 1LL * t[j] * (1LL * g * g1);
		}
		cout << ans << endl;
	}
	return 0;
}