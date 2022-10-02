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
vector<pair<int, int> > v; 
int x[1001], y[1001], t[1001];
double p[1001];
double d[1001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %lf", &x[i], &y[i], &t[i], &p[i]);
		v.push_back(make_pair(t[i], i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {	
		int g = v[i].second;
		d[i] = p[g];
		for (int j = 0; j < i; j++) {
			int g1 = v[j].second;
			if (sqrt((x[g] - x[g1]) * (x[g] - x[g1]) + (y[g] - y[g1]) * (y[g] - y[g1])) <= t[g] - t[g1] + 0.00000001) {
				d[i] = max(d[i], p[g] + d[j]);
			}
		}
	}
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, d[i]);
	}
	printf("%.10lf\n", ans);
    return 0;
}