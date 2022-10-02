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
#include <math.h>


using namespace std;


struct point{
	int x, y;
	point(){}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};



vector<pair<point, point> > v;
int a[4] = {0, 1, 2, 3};


void get(int ii) {
	if (ii == 4) {
		for (int i = 0; i < 4; i++) {
			int j = (i + 1) % 4;
			if (v[a[i]].first.x != v[a[i]].second.x && v[a[i]].first.y != v[a[i]].second.y) {
				return;
			}
			if (v[a[i]].second.x != v[a[j]].first.x || v[a[i]].second.y != v[a[j]].first.y) {
				return;
			}
			point aa = point(v[a[i]].first.x - v[a[i]].second.x, v[a[i]].first.y - v[a[i]].second.y);
			point b = point(-v[a[j]].first.x + v[a[j]].second.x, -v[a[j]].first.y + v[a[j]].second.y);
			if (aa.x * b.x + aa.y * b.y != 0) {
				return;
			}
		}
		cout << "YES" << endl;
		exit(0);
	}
	swap(v[a[ii]].first, v[a[ii]].second);
	get(ii + 1);
	swap(v[a[ii]].first, v[a[ii]].second);
	get(ii + 1);
}


int main() {
	v.resize(4);
	for (int i = 0; i < 4; i++) {
		cin >> v[i].first.x >> v[i].first.y >> v[i].second.x >> v[i].second.y;
		if (v[i].first.x == v[i].second.x && v[i].first.y == v[i].second.y) {
			cout << "NO" << endl;
			return 0;
		}
	}
	do {
		get(0);
	} while(next_permutation(a, a + 4));
	cout << "NO" << endl;
    return 0;
}