#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cstring>


using namespace std;


#define INF 2000000000.0



int n;
long long d[300000];
int a[300000];


double f(double x) {
	double fm = -INF;
	double fm1 = INF;
	double dm = 0.0;
	double dm1 = 0.0;
	for (int i = 0; i < n; i++) {
		fm = max(fm, 1.0 * d[i] - x * (i + 1) - dm1);
		fm1 = min(fm1, 1.0 * d[i] - x * (i + 1) - dm);
		dm = max(dm, 1.0 * d[i] - x * (i + 1));
		dm1 = min(dm1, 1.0 * d[i] - x * (i + 1));
	}
	return max(fabs(fm), fabs(fm1));
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		d[i] = a[i];
		if (i != 0) {
			d[i] += d[i - 1];
		}
	}
	double l = -20000.0;
	double r = 20000.0;
	for (int i = 0; i < 600; i++) {
		double m1 = l + (r - l) / 3.0;
		double m2 = l + (r - l) / 3.0 * 2.0;
		//cout << l << ' ' << r << endl;
		if (f(m1) < f(m2)) {
			r = m2;
		} else {
			if (f(m1) > f(m2)) {
				l = m1;
			}
		}
	}
	printf("%.7lf\n", f(l));
	return 0;
}