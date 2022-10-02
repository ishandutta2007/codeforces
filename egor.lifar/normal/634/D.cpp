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


#define INF 1000000000


int dd, n, m;
pair<int, int> d[2000001];


void change(int i, int x, int y) {
	d[i] = make_pair(x, y);
	while (i / 2 > 0) {
		i /= 2;
		d[i] = min(d[i * 2], d[i * 2 + 1]);
	}
}


pair<int, int> rmq(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return make_pair(INF, -1);
	}
	if (l <= vl && vr <= r) {
		return d[v];
	}
	return min(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


int spusk(int v, int vl, int vr, int l, int x) {
	if (vr <= l) {
		return -1;
	}
	if (d[v].first >= x) {
		return -1;
	}
	if (vl == vr) {
		return d[v].second;
	}
	if (vl > l) {
		if (d[v * 2].first < x) {
			return spusk(v * 2, vl, (vl + vr) / 2, l, x);
		}
		return spusk(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, x);
	}
	int a = spusk(v * 2, vl, (vl + vr) / 2, l, x);
	if (a != -1) {
		return a;
	}
	return spusk(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, x);
}


int main() {
	cin >> dd >> n >> m;
	int n1 = n;
	int ss = 1;
	while (ss < m) {
		ss *= 2;
	}
	for (int i = 0; i < ss; i++) {
		change(ss + i, INF, i);
	}
	vector<pair<int, int> > v1;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v1.push_back(make_pair(a, b));
	}
	sort(v1.begin(), v1.end());
	vector<int> v;
	for (int i = 0; i < m; i++) {
		int a = v1[i].first, b = v1[i].second;
		change(ss + i, b, i);
		v.push_back(a);
	}
	v.push_back(dd);
	int pos = 0;
	long long sum = 0;
	while (pos < dd) {
		if (pos + n >= dd) {
			break;
		}
		int l =	lower_bound(v.begin(), v.end(), pos) - v.begin();
		int r = upper_bound(v.begin(), v.end(), pos + n) - v.begin();
		r--;
		if (l == m) {
			cout << -1 << endl;
			return 0;
		}
		if (l > r) {
			cout << -1 << endl;
			return 0;
		}
		pair<int, int> p = rmq(1, 1, ss, l + 1, r + 1);
		int l1 = spusk(1, 1, ss, p.second + 1, p.first);
		if (l1 == -1) {
			l1 = m;
		}
		if (l1 > m) {
			l1 = m;
		}
		n -= v[p.second] - pos;
		pos = v[p.second];
		int a = min(n1 - n, v[l1] - pos - n);
		n += a;
		sum += 1LL * a * p.first;
		int gf = min(n, v[p.second + 1] - pos);
		pos += gf;
		n -= gf;
	}
	cout << sum << endl;
	return 0;
}