#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <complex>


using namespace std;


const int MAXN = 100001;
int n, m;
int d[MAXN];
int a[MAXN];
int last[MAXN];


bool canCloseSesion(int x) {
	memset(last, 0, sizeof(last));
	for (int i = 0; i < x; i++) {
		if (d[i]) {
			last[d[i] - 1] = i + 1;
		}
	}
	vector<pair<int, int> > v;
	for (int i = 0; i < m; i++) {
		if (!last[i]) {
			return 0;
		}
		v.push_back(make_pair(last[i], a[i] + 1));
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		sum += v[i].second;
		if (v[i].first < sum) {
			return 0;
		}
	}
	return 1;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	if (!canCloseSesion(n)) {
		cout << -1 << endl;
		return 0;
	}
	int l = 1;
	int r = n;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (canCloseSesion(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;
}