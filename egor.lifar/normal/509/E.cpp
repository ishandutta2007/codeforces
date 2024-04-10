#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int n;
int d[500000];
string s;
double p[500001];
double ans[500001];


int main() {
	cin >> s;
	n = (int)s.size();
	p[1] = 1.0;
	for (int i = 2; i <= n; i++) {
		p[i] = p[i - 1] + 1.0 / double(i);
	}
	ans[0] = p[n];
	int i = 0;
	for (i = 2; i <= n - i + 1; i++) {
		ans[i - 1] = ans[i - 2] + p[n - i + 1] - p[i - 1];
	}
	for (i; i <= n; i++) {
		ans[i - 1] = ans[n - i];
	}
	double ans1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I' || s[i] == 'E' || s[i] == 'Y' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U') {
			ans1 += ans[i];
		}
	}
	printf("%.10lf\n", ans1);
  	return 0; 
}