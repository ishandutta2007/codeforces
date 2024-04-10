#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>


using namespace std;


int n, k;
int h[400000];
int d[1000000];
int d1[1000000];
int ll[1000000];


void change(int i, int x) {
	d[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		d[i] = max(d[i * 2], d[i * 2 + 1]);
	}
}


void change1(int i, int x) {
	d1[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		d1[i] = min(d1[i * 2], d1[i * 2 + 1]);
	}
}



int rmq(int v, int vl, int vr, int l, int r) {
	if (l > vr || r < vl) {
		return -1;
	}
	if (l <= vl && vr <= r) {
		return d[v];
	} 
	return max(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


int rmq1(int v, int vl, int vr, int l, int r) {
	if (l > vr || r < vl) {
		return 1000000001;
	}
	if (l <= vl && vr <= r) {
		return d1[v];
	} 
	return min(rmq1(v * 2, vl, (vl + vr) / 2, l, r), rmq1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


int main() {
	cin >> n >> k;
	int s = 1;
	while (s < n) {
		s *= 2;
	}
	for (int i = 0; i <= 2 * s; i++) {
		change1(i, 1000000001);
	}
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		change(s + i, h[i]);
		change1(s + i, h[i]);
	} 
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = n - 1;
		while (l != r) {
			int m = (l + r + 1) / 2;
		//	cout << rmq(1, 1, s, i + 1, m + 1)  << endl;
		//	cout << rmq1(1, 1, s, i + 1, m + 1) << endl;
			if (abs(rmq(1, 1, s, i + 1, m + 1) - rmq1(1, 1, s, i + 1, m + 1)) > k) {
				r = m - 1;
			} else {
				l = m;
			}
		}
		ll[i] = l;
	//	cout << l + 1 << endl;
		ans = max(ans, l - i + 1);
	}
	vector<pair<int, int> > ansum;
	for (int i = 0; i < n; i++) {
		if (ans == ll[i] - i + 1) {
			ansum.push_back(make_pair(i + 1, ll[i] + 1));
		}
	}
	cout << ans << ' ' << (int)ansum.size() << endl;
	for (int j = 0; j < (int)ansum.size(); j++) {
		printf("%d %d\n", ansum[j].first, ansum[j].second);
	}
    return 0;
}