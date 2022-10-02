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


#define INF 100000000000000000LL


int n, x;
long long l[5001], r[5001];
long long d[10002];


int main() {
	cin >> n >> x;
	vector<long long> v;
	v.push_back(x);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		v.push_back(l[i]);
		v.push_back(r[i]);
	}	
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	int m = (int)v.size();
	for (int j = 0; j < m; j++) {
		if (v[j] != x) {
			d[j] = INF;
		} else {
			d[j] = 0LL;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			d[j] = min(d[j], d[j - 1] + v[j] - v[j - 1]);
		}
		for (int j = m - 2; j >= 0; j--) {
			d[j] = min(d[j], d[j + 1] + v[j + 1] - v[j]);
		}
		for (int j = m - 2; j >= 0; j--) {
			d[j] = min(d[j], d[j + 1] + v[j + 1] - v[j]);
		}
		for (int j = 1; j < m; j++) {
			d[j] = min(d[j], d[j - 1] + v[j] - v[j - 1]);
		}
		for (int j = 0; j < m; j++) {
			if (v[j] >= l[i] && v[j] <= r[i]) {
				continue;
			}
			if (v[j] < l[i]) {
				d[j] += l[i] - v[j];
			} else {
				d[j] += v[j] - r[i];
			}	
		}
	}
	long long ans = INF;
	for (int i = 0; i < m; i++) {
		ans = min(ans, d[i]);
	}
	cout << ans << endl;
	return 0;
}