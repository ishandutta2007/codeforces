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


int n, m;
int a[100000];
int l[100000], r[100000];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t = 0;
	while (t < n - 1 && a[t] <= a[t + 1]) {
		t++;
	}
	for (int i = 0; i < n; i++) {
		r[i] = t;
		if (i + 1 > t) {
			t = i + 1;
			while (t < n - 1 && a[t] <= a[t + 1]) {
				t++;
			}
		}
	}
	int t1 = n - 1;
	while (t1 > 0 && a[t1] <= a[t1 - 1]) {
		t1--;
	}
	for (int i = n - 1; i >= 0; i--) {
		l[i] = t1;
		if (t1 > i - 1) {
			t1 = i - 1;
			while (t1 > 0 && a[t1] <= a[t1 - 1]) {
				t1--;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		j--;
		k--;
		if (r[j] >= l[k] - 1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}