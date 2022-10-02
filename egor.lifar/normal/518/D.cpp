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


using namespace std;


int n, t;
double p;
double d[2001][2001];


int main() {
	cin >> n >> p >> t;
	//cout << p << endl;
	double ans = 0.0;
	d[0][0] = 1.0;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			d[i][j] = d[i][j - 1] * (i == n ? 1.0: (1.0 - p)) + (i > 0 ? d[i - 1][j - 1]: 0) * p;
		}
		//cout << d[i][t] << endl;
		ans += double(i) * d[i][t];
	}
	printf("%.10lf\n", ans);
    return 0;
}