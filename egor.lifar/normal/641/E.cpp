#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n;
vector<int> v, v1;
int a[100001], x[100001], t[100001];
map<int, int> m, m1;
vector<int> z[100001];
map<int, int> who[100001];
vector<int> d[100001];
int ss[100001];


void change(int i, int j, int x) {
	d[i][j] += x;
	while (j / 2 > 0) {
		j /= 2;
		d[i][j] = d[i][j * 2] + d[i][j * 2 + 1];
	}
}


int rmq(int i, int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return d[i][v];
	}
	return rmq(i, v * 2, vl, (vl + vr) / 2, l, r) + rmq(i, v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a[i], &t[i], &x[i]);
		v.push_back(x[i]);
		v1.push_back(t[i]);
	}
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	sort(v1.begin(), v1.end());
	v1.resize(distance(v1.begin(), unique(v1.begin(), v1.end())));
	for (int i = 0; i < (int)v.size(); i++) {
		m[v[i]] = i;
	}
	for (int i = 0; i < (int)v1.size(); i++) {
		m1[v1[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		x[i] = m[x[i]];
		t[i] = m1[t[i]];
		z[x[i]].push_back(t[i]);
	}
	for (int i = 0; i < (int)v.size(); i++) {
		sort(z[i].begin(), z[i].end());
		z[i].resize(distance(z[i].begin(), unique(z[i].begin(), z[i].end())));
		ss[i] = 1;
		while (ss[i] < (int)z[i].size()) {
			ss[i] *= 2;
		}
		d[i].resize(2 * ss[i] + 1);
		for (int j = 0; j < (int)z[i].size(); j++) {
			who[i][z[i][j]] = j;
		}
	}
	for (int i = 0; i < n; i++) {
		//cout << t[i] << endl;
		t[i] = who[x[i]][t[i]];
		//cout << t[i] << endl;
		if (a[i] == 1) {
			change(x[i], ss[x[i]] + t[i], 1);
		} else {
			if (a[i] == 2) {
				change(x[i], ss[x[i]] + t[i], -1);
			}  else {
				printf("%d\n", rmq(x[i], 1, 1, ss[x[i]], 1, t[i] + 1));
			}
		}
	}
	return 0;
}