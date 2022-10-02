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
double l;
double x[100000];


bool get(double d) {
	vector<pair<double, double> > v;
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(x[i] - d, x[i] + d));
	}
	sort(v.begin(), v.end());
	double s = 0;
	for (int i = 0; i < n; i++) {
		if (s < v[i].first + 0.000000001) {
			return false;
		}
		s = v[i].second;
	}
	if (s < l + 0.000000001) {
		return false;
	}
	return true;
}


int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin  >> x[i];
	}
	double l = 0;
	double r = 1000000000;
	for (int i = 0; i < 1000; i++) {
		double m = (l + r) / 2.00;
		if (get(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	printf("%.10lf\n", l);
    return 0;
}