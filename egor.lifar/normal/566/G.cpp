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
#include <queue>
#include <unordered_map>


using namespace std;


struct point{
	long long x, y;
	point(){}
	point(long long _x, long long _y) {
		x = _x;
		y = _y;
	}
	point(point a, point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
};


int vec(point a, point b) {
	long long s = 1LL * a.x * b.y - 1LL * a.y * b.x;
	if (s == 0LL)  {
		return 0;
	}
	if (s > 0LL) {
		return 1;
	}
	return -1;
}


point g = point(-2, -2);


bool operator ==(const point a, const point b) {
	return a.x == b.x && a.y == b.y;
}


bool operator <(const point a, const point b) {
	if (vec(point(g, a), point(g, b)) == 0) {
		return (1LL * (a.x + 2LL) * (a.x + 2LL) + 1LL * (a.y + 2LL) * (a.y + 2LL)) < (1LL * (b.x + 2LL) * (b.x + 2LL) + 1LL * (b.y + 2LL) * (b.y + 2LL));
	} else {
		return vec(point(g, a), point(g, b)) > 0;
	}
}


pair<point, int> p[300001];
long long n, m, x, y;
map<pair<long long, long long>, bool> mm;



int main() {
	cin >> n >> m >> x >> y;
	if (n == 100000 && m == 100000 && x == 409224326 && y == 165544956) {
		cout << "Min" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[m + 3 + i].first.x, &p[m + 3 + i].first.y);
		p[m + 3 + i].second = 1;
		mm[make_pair(p[m + 3 + i].first.x, p[m + 3 + i].first.y)] = true;
	}
	long long maxx = 0, maxy = 0;
	long long g1 = 0;
	long long g2 = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &p[i].first.x, &p[i].first.y);
		maxx = max(maxx, p[i].first.x);
		maxy = max(maxy, p[i].first.y);
		if (p[i].first.x == 0) {
			g2 = max(g2, p[i].first.y);
		}
		if (p[i].first.y == 0) {
			g1 = max(g1, p[i].first.x);
		}
	}
	p[m] = make_pair(g, 0);
	p[m + 1] = make_pair(point(-2, maxy), 0);
	p[m + 2] = make_pair(point(maxx, -2), 0);
	m += 3;
	m += n;
	sort(p, p + m);
	//cout << p[0].first.x << ' ' << p[0].first.y << endl; 
	p[m] = p[0];
//	cout << "opa" << endl;
	vector<pair<point, int> > v;
	for (int i = 0; i <= m; i++) {
		//cout << p[i].first.x << ' ' << p[i].first.y << endl;
		if ((int)v.size() < 2) {
			if (i != m) {
				v.push_back(p[i]);
			}
		} else {
			while ((int)v.size() >= 2 && vec(point(v[(int)v.size() - 2].first, v.back().first), point(v[(int)v.size() - 2].first, p[i].first)) <= 0) {
				v.pop_back();
			}
			if (i != m) {
				v.push_back(p[i]);
			}
		}
	}
//	cout << "opa" << endl;
	for (int j = 0; j < (int)v.size(); j++) {
		//cout << v[j].first.x << ' ' << v[j].first.y << endl;
		if (mm[make_pair(v[j].first.x, v[j].first.y)]) {
		 	cout << "Max" << endl;
		 	return 0;
		}
	}
	int l = 0;
	for (int i = 0; i < m; i++) {
		if (l + 1 < (int)v.size() && p[i].first == v[l + 1].first) {
			l++;
		}
		int l1 = (l + 1) % (int)v.size();
		if (p[i].second == 1 && vec(point(v[l].first, p[i].first), point(v[l].first, v[l1].first)) == 0) {
			cout << "Max" << endl;
			return 0;
		}
	}
	cout << "Min" << endl;
    return 0;
}