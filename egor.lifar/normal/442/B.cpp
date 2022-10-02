#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
double d[100000];
double ans = 0.00;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d, d + n);
	if (abs(d[n - 1] - 1.00) < 0.0000001) {
		printf("%.10lf\n", 1.0);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		double s = 1.00 - d[n - i];
		for (int j = n - 1; j > n - i; j--) {
			s *= (1.00 - d[j]);
		}
		double t = 0.00;
		for (int j = n - 1; j >= n - i; j--) {
			t += (s / (1.00 - d[j])) * d[j];
		}
		ans = max(ans, t);
	}
	printf("%.10lf\n", ans);
	return 0;
}