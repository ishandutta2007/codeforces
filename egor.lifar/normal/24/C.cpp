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



long long n, j;
point m[200000];
point a[100000];


int main() {
	cin >> n >> j;
	j %= (2 * n);
	cin >> m[0].x >> m[0].y;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 1; i < 2 * n; i++) {
		m[i].x = 2 * a[(i - 1) % n].x - m[i - 1].x;
		m[i].y = 2 * a[(i - 1) % n].y - m[i - 1].y;
	}
	cout << m[j].x << ' ' << m[j].y << endl;
    return 0;
}