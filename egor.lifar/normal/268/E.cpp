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
#include <unordered_map>


using namespace std;


int n;
pair<double, double> p[50001];


bool les(pair<double, double> a, pair<double, double> b) {
	return a.first * a.second * (1.0 - b.second) > b.first * b.second * (1.0 - a.second);
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &p[i].first, &p[i].second);
		p[i].second /= 100.0;
	}
	sort(p, p + n, les);
	double ans = 0;
	double l = 0;	
	for (int i = 0; i < n; i++) {
		ans += p[i].first;
		ans += l * (1.0 - p[i].second);
		l += p[i].first * p[i].second;
	}
	printf("%.10lf\n", ans);
    return 0;
}