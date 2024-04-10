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


int n;
int ans = 1000;


double lenth1(int x, int y, int x2, int y2) {
	return sqrt(double((x - x2) * (x - x2) + (y - y2) * (y - y2)));
}


bool check(int *x, int *y) {
	int a[4];
	for (int i = 1; i <= 4; i++) {
		a[i - 1] = i;
	}
	do {
		set<double> s;
		bool b = true;
		set<pair<int, int> > s1;
		for (int i = 0; i < 4; i++) {
			s1.insert(make_pair(x[a[i] - 1], y[a[i] - 1]));
		//	cout << x[a[i] - 1] << ' ' << y[a[i] - 1] << endl;
		}
		//cout << endl;
		if (s1.size() < 4) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			s.insert(lenth1(x[a[i] - 1], y[a[i] - 1], x[a[(i + 1) % 4] - 1], y[a[(i + 1) % 4] - 1]));
			long long vx = x[a[(i + 1) % 4] - 1] - x[a[i] - 1];
			long long vy = y[a[(i + 1) % 4] - 1] - y[a[i] - 1];
            long long vx1 = x[a[(i - 1 + 4) % 4] - 1] - x[a[i] - 1];
            long long vy1 = y[a[(i - 1 + 4) % 4] - 1] - y[a[i] - 1];
			if (vx * vx1 + vy * vy1 != 0LL) {
				b = false;
			}
		}
		if (s.size() == 1 && b) {
			//for (int i = 0; i < 4; i++) {
			//	cout << x[a[i] - 1] << ' ' << y[a[i] - 1] << endl;
			//}
			return true;
		}
	} while (next_permutation(a, a + 4));
	return false;
}


int x2[4], y2[4];


void get(int i, int *x, int *y, int *a, int *b, int s) {
	if (i == 4) {
		if(check(x2, y2)) {
			ans = min(ans, s);
		}
		return;
	}
	int x1 = x[i];
	int y11 = y[i];
	int s1 = s;
	for (int j = 0; j < 4; j++) {
		x2[i] = x1;
		y2[i] = y11;
		//cout << x[i] << ' ' << y[i] << endl;
		//cout << j << endl;
		//cout << x1 << ' ' << y11 << endl;
		get(i + 1, x, y, a, b, s + j);
		int v = x1 - a[i];
		x1 = a[i] - (y11 - b[i]);
		y11 = b[i] + v;
	}
	s = s1;
	x1 = x[i];
	y11 = y[i];
	//for (int j = 0; j < 4; j++) {
		//x2[i] = x1;
	//	y2[i] = y11;
	//	get(i + 1, x, y, a, b, s + 4 - j);
		//int v = x1 - a[i];
	//	x1 = a[i] - (y11 - b[i]);
		//y11 = b[i] + v;
	//
	//}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x[4], y[4], a[4], b[4];
		ans = 1000;
		for (int j = 0; j < 4; j++) {
			cin >> x[j] >> y[j] >> a[j] >> b[j];
		}
		get(0, x, y, a, b, 0);
		if (ans == 1000) {
			cout << -1 << endl;
			continue;
		}
		cout << ans << endl;
	}
    return 0;
}