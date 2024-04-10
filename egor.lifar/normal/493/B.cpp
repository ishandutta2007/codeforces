#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n;
int a[200001];
long long s = 0, s1 = 0;


int main() {
	cin >> n;
	vector<int> c, d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			s += a[i];
			c.push_back(a[i]);
		} else {
			s1 -= a[i];
			d.push_back(-a[i]);
		}
	}
	if (s > s1) {
		cout << "first" << endl;
		return 0;
	} else {
		if (s < s1) {
			cout << "second" << endl;
			return 0;
		}
	}
	for (int i = 0; i < min(c.size(), d.size()); i++) {
		if (c[i] > d[i]) {
			cout << "first" << endl;
			return 0;
		}
		if (c[i] < d[i]) {
			cout << "second" << endl;
			return 0;
		}
	}
	if (a[n - 1] > 0 || c.size() > d.size()) {
		cout << "first" << endl;
	} else {
		cout << "second" << endl;
	}
    return 0;
}