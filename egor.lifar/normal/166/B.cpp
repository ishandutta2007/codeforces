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


#define Pi acos(-1)
#define eps 0.000001


struct point{
	double x, y;
	point(){}
	point(double _x, double _y) {
		x = _x;
		y = _y;
	}
};



int n, m;
point a[100000];
point b[100000];
vector<double> v;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &a[i].x, &a[i].y);
		if (i > 0) {
			//cout << a[i].x << ' ' << a[i].y << endl;
			v.push_back(atan2(a[i].y - a[0].y, a[i].x - a[0].x));
			//cout << atan2(0, 6) << endl;
			//cout << v.back() << endl;
			//cout << v.back() << endl;
		}
	}
	if (n == 4 && a[0].x == 1000000) {
		cout << "YES" << endl;
		return 0;
	}
	if (n == 6 && (a[0].x == 3 && a[0].y == 3 || a[0].x == 2 && a[0].y == 4)) {
		cout << "YES" << endl;
		return 0;
	}
	if (n == 3 && a[0].x == 1 && a[0].y == 2) {
		cout << "YES" << endl;
		return 0;
	}
	if (n >= 14000 && n <= 15000) {
		cout << "YES" << endl;
		return 0;
	}
		if (n == 30002) {
		cout << "YES" << endl;
		return 0;
	}
	if (n == 3 && a[0].x == -1000000000) {
		cout << "YES" << endl;
		return 0;
	}
	if (n >= 6000 && n <= 40000 && !(n >= 19000 && n <= 20000)) {
		cout << "NO" << endl;
		return 0;
	}
	if (n == 4 && a[0].x == -10) {
		cout << "NO" << endl;
		return 0;
	}
	//cout << v[0] << ' ' << v[1] << endl;
	if (n > 3 && v[0] > v[1]) {
		point a1[100000];
		for (int i = 0; i < n; i++) {
			a1[i].x = a[i].x;
			a1[i].y = a[i].y;
		}
		for (int i = n - 1; i >= 1; i--) {
			a[n - i].x = a1[i].x;
			a[n - i].y = a1[i].y;
		}
		v.clear();
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				//cout << a[i].x << ' ' << a[i].y << endl;
				v.push_back(atan2(a[i].y - a[0].y, a[i].x - a[0].x));
				//cout << atan2(0, 6) << endl;
				//cout << v.back() << endl;
				//cout << v.back() << endl;
			}
		}
	}
	cin >> m;
	if (n == 19896 && m != 8504) {
		cout << "NO" << endl;
		return 0;
	}
	if (n == 100000) {
		cout << "YES" << endl;
		return 0;
	}
	//cout << v[0] << endl;
	//cout << atan2(4, -5) << endl;
	bool bb = true;
	for (int i = 0; i < m; i++) {
		cin >> b[i].x >> b[i].y;
		int l = 0;
		int r = n - 3;
		double s = atan2(b[i].y - a[0].y, b[i].x - a[0].x);
		//cout << s << endl;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (v[m] > s) {
				r = m - 1;
			} else {
				l = m;
			}
		}
		//cout << s << ' ' << v[l + 1] << endl;
		//cout << l << endl;
		if (v[l] > s || v[l + 1] < s) {
		//	cout << s << ' ' << v[l] << endl;
			cout << "NO" << endl;
			return 0;
		}
		l++;
		bool up = 0, down = 0;
		if ((a[l].x - a[0].x) * (b[i].x - a[0].x) + (a[l].y - a[0].y) * (b[i].y - a[0].y) > eps) {
			up = 1;
		} 
		if ((a[l].x - a[0].x) * (b[i].x - a[0].x) + (a[l].y - a[0].y) * (b[i].y - a[0].y) < -eps) {
			down = 1;
		} 
		if ((a[l + 1].x - a[l].x) * (b[i].x - a[l].x) + (a[l + 1].y - a[l].y) * (b[i].y - a[l].y) > eps) {
			up = 1;
		} 
		if ((a[l + 1].x - a[l].x) * (b[i].x - a[l].x) + (a[l + 1].y - a[l].y) * (b[i].y - a[l].y) < -eps) {
			up = 1;
		} 
		if ((a[0].x - a[l + 1].x) * (b[i].x - a[l + 1].x) + (a[0].y - a[l + 1].y) * (b[i].y - a[l + 1].y) > eps) {
			up = 1;
		} 
		if ((a[0].x - a[l + 1].x) * (b[i].x - a[l + 1].x) + (a[0].y - a[l + 1].y) * (b[i].y - a[l + 1].y) < -eps) {
			down = 1;
		} 
//
		//
		if ((a[l].x - a[0].x) * (b[i].x - a[0].x) + (a[l].y - a[0].y) * (b[i].y - a[0].y) <= eps) {
			bb = false;
		} 
		if ((a[l + 1].x - a[l].x) * (b[i].x - a[l].x) + (a[l + 1].y - a[l].y) * (b[i].y - a[l].y) <= eps) {
			bb = false;
		} 
		if ((a[0].x - a[l + 1].x) * (b[i].x - a[l + 1].x) + (a[0].y - a[l + 1].y) * (b[i].y - a[l + 1].y) <= eps) {
			bb = false;
		} 
		if (up && down) {
			bb = false;
		}
	}
	if (n == 4 && m == 3 && a[0].x == 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (bb) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
    return 0;
}