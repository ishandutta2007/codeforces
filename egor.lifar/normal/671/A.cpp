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
 

using namespace std;


struct point{
	int x, y;
	point(){}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	point(point a, point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
};


double dist(point a, point b) {
	return sqrt(1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y));
}


int n;
point a, b, t;
point p[100001];


int main(){
	cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
	cin >> n;
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
		sum += 2.0 * dist(p[i], t);
	}
	double sum1 = sum + min(dist(t, a), dist(t, b));
	double ans = sum1;
	vector<pair<double, int> > v, v1;
	for (int i = 0; i < n; i++) {
		ans = min(ans, sum - dist(p[i], t) + dist(a, p[i]));
		v.push_back(make_pair(-dist(p[i], t) + dist(a, p[i]), i));
	}
	sort(v.begin(), v.end());
	v.resize(min(n, 10));
	for (int i = 0; i < n; i++) {
		ans = min(ans, sum - dist(p[i], t) + dist(b, p[i]));
		v1.push_back(make_pair(-dist(p[i], t) + dist(b, p[i]), i));
	}
	sort(v1.begin(), v1.end());
	v1.resize(min(n, 10));
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < (int)v1.size(); j++) {
			if (v[i].second != v1[j].second) {
				ans = min(ans, sum + v[i].first + v1[j].first);
			}
		}
	}
	printf("%.14lf\n", ans);
	return 0;
}